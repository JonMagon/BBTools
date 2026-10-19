#include "editor.h"
#include "editor_support.h"
#include <algorithm>
#include <cmath>
#include <limits>

namespace bb
{
using namespace detail;

void Choice::wheelEvent(QWheelEvent *event)
{
    event->accept();
}

Choice::Choice(const Choices &choices,
               qint64 initialValue,
               qint64 minimumValue,
               qint64 maximumValue,
               bool fixedChoices,
               QWidget *parent)
    : QComboBox(parent), committed(initialValue), low(minimumValue), high(maximumValue),
      fixed(fixedChoices)
{
    setView(new QListView);
    setStyleSheet(comboPopupStyleSheet());
    setMaxVisibleItems(12);
    setMinimumContentsLength(12);
    setSizeAdjustPolicy(AdjustToMinimumContentsLengthWithIcon);
    setCursor(Qt::ArrowCursor);
    view()->setCursor(Qt::ArrowCursor);
    view()->viewport()->setCursor(Qt::ArrowCursor);
    view()->verticalScrollBar()->setCursor(Qt::ArrowCursor);
    setEditable(!fixed);
    setInsertPolicy(NoInsert);
    for (auto choice = choices.begin(); choice != choices.end(); ++choice)
    {
        auto label = QString("%1 · %2").arg(choice.key()).arg(choice.value());
        addItem(label, choice.key());
    }
    if (findData(initialValue) < 0)
    {
        addItem(QString("%1 · Stored value").arg(initialValue), initialValue);
    }
    setCurrentIndex(findData(initialValue));
    if (!fixed)
    {
        setCompleter(nullptr);
        lineEdit()->installEventFilter(this);
        view()->installEventFilter(this);
        view()->viewport()->installEventFilter(this);
        connect(lineEdit(), &QLineEdit::textEdited, this, &Choice::filter);
        connect(lineEdit(),
                &QLineEdit::editingFinished,
                this,
                [this]
                {
                    commit();
                });
        lineEdit()->setModified(false);
    }
    connect(this,
            &QComboBox::activated,
            this,
            [this](int itemIndex)
            {
                auto selectedValue = itemData(itemIndex).toLongLong();
                bool changed = selectedValue != committed;
                committed = selectedValue;
                sync();
                if (changed)
                {
                    emit chosen(selectedValue);
                }
            });
}

void Choice::sync()
{
    QSignalBlocker blocker(this);
    int i = findData(committed);
    if (i < 0)
    {
        addItem(QString::number(committed), committed);
        i = count() - 1;
    }
    setCurrentIndex(i);
    if (lineEdit())
    {
        lineEdit()->setModified(false);
    }
    setProperty("invalid", false);
    setStyleSheet(comboPopupStyleSheet());
}

bool Choice::commit()
{
    if (fixed)
    {
        return true;
    }
    if (!lineEdit()->isModified())
    {
        return true;
    }
    auto t = lineEdit()->text().trimmed();
    bool ok = false;
    auto value = t.toLongLong(&ok, 0);
    if (!ok)
    {
        for (int i = 0; i < count(); ++i)
        {
            if (itemText(i).compare(t, Qt::CaseInsensitive) == 0)
            {
                value = itemData(i).toLongLong();
                ok = true;
                break;
            }
        }
    }
    ok = ok && value >= low && value <= high;
    setProperty("invalid", !ok);
    setStyleSheet(comboPopupStyleSheet() +
                  (ok ? QString{} : QString("QComboBox {border:1px solid #ef7777;}")));
    if (!ok)
    {
        return false;
    }
    bool changed = value != committed;
    committed = value;
    sync();
    if (changed)
    {
        emit chosen(value);
    }
    return true;
}

void Choice::filter(const QString &t)
{
    auto list = qobject_cast<QListView *>(view());
    for (int i = 0; i < count(); ++i)
    {
        list->setRowHidden(i, !itemText(i).contains(t.trimmed(), Qt::CaseInsensitive));
    }
    if (!view()->isVisible())
    {
        auto input = lineEdit()->text();
        auto caret = lineEdit()->cursorPosition();
        showPopup();
        lineEdit()->setText(input);
        lineEdit()->setCursorPosition(caret);
        lineEdit()->setModified(true);
    }
}

bool Choice::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonRelease && object == lineEdit())
    {
        QTimer::singleShot(0,
                           this,
                           [this]
                           {
                               showPopup();
                           });
    }
    if (event->type() == QEvent::KeyPress)
    {
        auto key = static_cast<QKeyEvent *>(event);
        bool typing = !key->text().isEmpty() && key->text()[0].isPrint() &&
                      !(key->modifiers() & (Qt::ControlModifier | Qt::AltModifier));
        if (!lineEdit()->isModified() &&
            (typing || key->key() == Qt::Key_Backspace || key->matches(QKeySequence::Paste)))
        {
            lineEdit()->selectAll();
        }
        if (object == view() || object == view()->viewport())
        {
            if (key->key() == Qt::Key_Return && lineEdit()->isModified())
            {
                if (commit())
                {
                    hidePopup();
                }
                return true;
            }
            if (key->key() != Qt::Key_Up && key->key() != Qt::Key_Down &&
                key->key() != Qt::Key_PageUp && key->key() != Qt::Key_PageDown &&
                key->key() != Qt::Key_Return && key->key() != Qt::Key_Enter &&
                key->key() != Qt::Key_Escape && key->key() != Qt::Key_Tab)
            {
                QApplication::sendEvent(lineEdit(), key);
                return true;
            }
        }
    }
    return QComboBox::eventFilter(object, event);
}

} // namespace bb
