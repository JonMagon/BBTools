#include "editor.h"
#include "editor_support.h"
#include <algorithm>
#include <cmath>

namespace bb
{
using namespace detail;

Snapshot Editor::snapshot() const
{
    Snapshot result;
    result.chains = mission().chains;
    result.positions = document().positions;
    result.chainChoice = chainIndex;
    for (auto node : nodes)
    {
        if (node && node->kind >= 0)
        {
            result.editors[node->chainId * 32 + node->block] = {node->kind, node->index};
        }
    }
    return result;
}

void Editor::record(const Snapshot &before, QString name)
{
    auto after = snapshot();
    if (snapshotsEqual(before, after))
    {
        return;
    }
    auto &currentDocument = document();
    currentDocument.past.push_back({before, after, name});
    if (currentDocument.past.size() > 100)
    {
        currentDocument.past.erase(currentDocument.past.begin());
    }
    currentDocument.future.clear();
    changed();
}

void Editor::edit(QString name, const std::function<void()> &action, bool rebuildAfter)
{
    auto before = snapshot();
    action();
    if (!rebuildAfter)
    {
        for (auto node : nodes)
        {
            if (node)
            {
                node->refreshLabels();
            }
        }
        updateEdges();
    }
    record(before, name);
    if (rebuildAfter)
    {
        queueRebuild();
    }
}

void Editor::queueRebuild()
{
    QTimer::singleShot(0,
                       this,
                       [this]
                       {
                           if (!closing)
                           {
                               rebuild();
                           }
                       });
}

void Editor::queueForm(Node *node)
{
    if (formPending)
    {
        return;
    }
    formPending = true;
    int documentId = documentIndex, chainChoice = chainIndex,
        nodeKey = node->chainId * 32 + node->block;
    QTimer::singleShot(0,
                       this,
                       [this, documentId, chainChoice, nodeKey]
                       {
                           formPending = false;
                           if (!closing && documentId == documentIndex &&
                               chainChoice == chainIndex && nodes[nodeKey])
                           {
                               nodes[nodeKey]->buildForm();
                           }
                       });
}

void Editor::changed()
{
    updateTitle();
    highlightSearch();
    if (checks && checks->isVisible())
    {
        refreshChecks();
    }
}

void Editor::history(bool redo)
{
    if (documents.empty())
    {
        return;
    }
    if (!commitInputs())
    {
        return;
    }
    QTimer::singleShot(0,
                       this,
                       [this, redo]
                       {
                           auto &currentDocument = document();
                           auto &from = redo ? currentDocument.future : currentDocument.past;
                           auto &to = redo ? currentDocument.past : currentDocument.future;
                           if (from.empty())
                           {
                               return;
                           }
                           auto entry = std::move(from.back());
                           from.pop_back();
                           auto state = redo ? entry.after : entry.before;
                           currentDocument.mission.chains = state.chains;
                           currentDocument.positions = state.positions;
                           to.push_back(std::move(entry));
                           chainIndex = state.chainChoice;
                           {
                               QSignalBlocker blocker(chainBox);
                               chainBox->setCurrentIndex(chainIndex);
                           }
                           auto transform = view->transform();
                           auto center = view->mapToScene(view->viewport()->rect().center());
                           rebuild();
                           for (auto i = state.editors.begin(); i != state.editors.end(); ++i)
                           {
                               if (auto node = nodes[i.key()])
                               {
                                   node->kind = i.value().first;
                                   node->index = i.value().second;
                                   node->buildForm();
                               }
                           }
                           rebuilding = true;
                           for (auto node : nodes)
                           {
                               if (node &&
                                   state.positions.contains(node->chainId * 32 + node->block))
                               {
                                   node->setPos(state.positions[node->chainId * 32 + node->block]);
                               }
                           }
                           rebuilding = false;
                           document().positions = state.positions;
                           updateEdges();
                           view->setTransform(transform);
                           view->centerOn(center);
                       });
}

} // namespace bb
