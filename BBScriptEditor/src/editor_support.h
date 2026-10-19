#pragma once

#include "editor.h"

namespace bb::detail
{
Choices playerChoices();
QString decodeNullTerminatedText(const QByteArray &bytes);
QString eventDestinationLabel(const Event &event);
QString nodeStyleSheet();
QString comboPopupStyleSheet();
QStringList wrapRecordText(const QString &text);
bool snapshotsEqual(const Snapshot &first, const Snapshot &second);

class NoWheelComboBox : public QComboBox
{
public:
    NoWheelComboBox();

protected:
    void wheelEvent(QWheelEvent *event) override;
};

class IntegerEdit : public QLineEdit
{
public:
    IntegerEdit(qint64 initialValue,
                qint64 minimum,
                qint64 maximum,
                std::function<void(qint64)> onValueChanged);
    bool commit();

private:
    qint64 value;
    qint64 minimum;
    qint64 maximum;
    std::function<void(qint64)> onValueChanged;
};
} // namespace bb::detail
