#include "editor.h"
#include "editor_support.h"
#include <algorithm>
#include <cmath>

namespace bb
{
using namespace detail;

void Editor::showChecks()
{
    if (documents.empty())
    {
        return;
    }
    if (!checks)
    {
        checks = new QDockWidget("Script checks", this);
        checks->setAllowedAreas(Qt::BottomDockWidgetArea);
        checks->setFeatures(QDockWidget::DockWidgetClosable);
        auto panel = new QWidget;
        auto layout = new QVBoxLayout(panel);
        auto refresh = new QPushButton("Refresh");
        layout->addWidget(refresh);
        issueList = new QTreeWidget;
        issueList->setColumnCount(5);
        issueList->setHeaderLabels({"Level", "Chain", "Block", "Record", "Details"});
        issueList->header()->setSectionResizeMode(4, QHeaderView::Stretch);
        issueList->setRootIsDecorated(false);
        issueList->setMinimumHeight(170);
        layout->addWidget(issueList);
        checks->setWidget(panel);
        addDockWidget(Qt::BottomDockWidgetArea, checks);
        connect(refresh, &QPushButton::clicked, this, &Editor::refreshChecks);
        connect(issueList,
                &QTreeWidget::itemActivated,
                this,
                [this](auto item, int)
                {
                    navigateIssue(item);
                });
    }
    checks->show();
    refreshChecks();
}

void Editor::refreshChecks()
{
    if (documents.empty())
    {
        return;
    }
    if (!issueList)
    {
        return;
    }
    issueList->clear();
    auto issues = validate(mission(), catalog);
    int errors = 0;
    for (auto &i : issues)
    {
        errors += i.error;
        auto item = new QTreeWidgetItem(
            issueList,
            {i.error ? "Error" : "Note",
             QString::number(i.chain),
             QString::number(i.block),
             i.kind < 0 ? "" : QString(i.kind ? "Event %1" : "Command %1").arg(i.record + 1),
             i.message});
        item->setData(0, Qt::UserRole, QVariantList{i.chain, i.block, i.kind, i.record});
        item->setForeground(0, QColor(i.error ? "#b53030" : "#83652a"));
    }
    checks->setWindowTitle(
        QString("Script checks · %1 errors · %2 notes").arg(errors).arg(issues.size() - errors));
    for (int col = 0; col < 4; ++col)
    {
        issueList->resizeColumnToContents(col);
    }
}

void Editor::navigateIssue(QTreeWidgetItem *item)
{
    if (!item)
    {
        return;
    }
    auto data = item->data(0, Qt::UserRole).toList();
    chainIndex = data[0].toInt();
    {
        QSignalBlocker blocker(chainBox);
        chainBox->setCurrentIndex(chainIndex);
    }
    rebuild();
    int b = chainIndex * 32 + data[1].toInt();
    if (!nodes[b])
    {
        allBlocks->setChecked(true);
    }
    if (auto node = nodes[b])
    {
        scene->clearSelection();
        node->setSelected(true);
        view->centerOn(node);
        if (data[2].toInt() >= 0)
        {
            node->kind = data[2].toInt();
            node->index = data[3].toInt();
            node->buildForm();
            view->centerOn(node);
        }
    }
}

} // namespace bb
