#include "editor_support.h"

namespace bb::detail
{
Choices playerChoices()
{
    Choices choices;
    for (int player = 0; player < 5; ++player)
    {
        choices[player] = "Player " + QString::number(player);
    }
    return choices;
}

QString decodeNullTerminatedText(const QByteArray &bytes)
{
    return QString::fromLatin1(bytes.split('\0').first());
}

QString eventDestinationLabel(const Event &event)
{
    return event.destination ? QString("BLOCK %1").arg(event.target()) : "Not connected";
}

QString nodeStyleSheet()
{
    return "QWidget {background:#24333e;color:#e1eaf0;font-size:12px;} "
           "QLineEdit,QSpinBox,QComboBox {background:#17232c;border:1px solid "
           "#536879;border-radius:4px;padding:3px;} "
           "QPushButton {background:#3c5362;border:1px solid "
           "#607482;border-radius:4px;padding:4px;} "
           "QLabel {background:transparent;}";
}

QString comboPopupStyleSheet()
{
    return "QComboBox {combobox-popup:0;} QComboBox QAbstractItemView "
           "{background:#1b2b36;color:#e1eaf0;selection-background-color:#3b5668;selection-color:#"
           "ffffff;"
           "outline:0px;}";
}

QStringList wrapRecordText(const QString &text)
{
    QStringList lines;
    QString line;
    for (auto word : text.simplified().split(' ', Qt::SkipEmptyParts))
    {
        if (!line.isEmpty() && line.size() + 1 + word.size() > 48)
        {
            lines << line;
            line.clear();
        }
        while (word.size() > 48)
        {
            int room = 48 - line.size() - (line.isEmpty() ? 0 : 1);
            if (room <= 0)
            {
                lines << line;
                line.clear();
                continue;
            }
            line += (line.isEmpty() ? "" : " ") + word.left(room);
            word = word.mid(room);
            lines << line;
            line.clear();
        }
        line += (line.isEmpty() ? "" : " ") + word;
    }
    if (!line.isEmpty())
    {
        lines << line;
    }
    return lines;
}

bool snapshotsEqual(const Snapshot &first, const Snapshot &second)
{
    if (first.positions != second.positions)
    {
        return false;
    }
    for (int chainIndex = 0; chainIndex < 5; ++chainIndex)
    {
        if (first.chains[chainIndex].current != second.chains[chainIndex].current)
        {
            return false;
        }
        for (int blockIndex = 0; blockIndex < 32; ++blockIndex)
        {
            if (blockSemantic(first.chains[chainIndex].blocks[blockIndex]) !=
                blockSemantic(second.chains[chainIndex].blocks[blockIndex]))
            {
                return false;
            }
        }
    }
    return true;
}

NoWheelComboBox::NoWheelComboBox()
{
    setView(new QListView);
    setStyleSheet(comboPopupStyleSheet());
    setMaxVisibleItems(12);
}

void NoWheelComboBox::wheelEvent(QWheelEvent *event)
{
    event->accept();
}

IntegerEdit::IntegerEdit(qint64 initialValue,
                         qint64 minimum,
                         qint64 maximum,
                         std::function<void(qint64)> onValueChanged)
    : QLineEdit(QString::number(initialValue)), value(initialValue), minimum(minimum),
      maximum(maximum), onValueChanged(std::move(onValueChanged))
{
    setProperty("numericInput", true);
    connect(this,
            &QLineEdit::editingFinished,
            this,
            [this]
            {
                commit();
            });
}

bool IntegerEdit::commit()
{
    bool parsed = false;
    const auto enteredValue = text().toLongLong(&parsed, 10);
    const bool valid = parsed && enteredValue >= minimum && enteredValue <= maximum;
    setProperty("invalid", !valid);
    setStyleSheet(valid ? "" : "QLineEdit {border:1px solid #ef7777;}");
    if (valid && enteredValue != value)
    {
        value = enteredValue;
        onValueChanged(enteredValue);
    }
    return valid;
}
} // namespace bb::detail
