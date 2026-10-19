#pragma once
#include "format.h"
#include <QtGui>
#include <functional>

namespace bb
{
using Choices = QMap<qint64, QString>;

struct Field
{
    QString name;
    qint64 value = 0;
    qint64 low = INT32_MIN;
    qint64 high = INT32_MAX;
    Choices choices;
    bool fixed = false;
    bool rebuild = false;
    std::function<void(Command &, qint64)> set;
};

class Catalog
{
public:
    QJsonObject root;
    QJsonObject units;
    QJsonObject classLabels;
    QJsonObject classIds;
    QJsonArray activities;
    QJsonArray states;
    QJsonArray actions;
    QMap<QString, QByteArray> letters;
    QMap<int, QIcon> textureIcons;
    QString gameDirectory;
    Catalog();
    void setGameDirectory(const QString &directory);
    Choices choices(const QString &group) const;
    Choices classes() const;
    Choices unitChoices() const;
    Choices actionChoices() const;
    Choices objectChoices(const Mission &mission, bool selection = false) const;
    Choices classModes(int classId, const QJsonArray &entries) const;
    QString className(int classId) const;
    QString objectName(const Mission &mission, int slot) const;
    QString commandLabel(const Mission &mission, const Command &command) const;
    QString eventLabel(const Mission &mission, const Event &event) const;
    QString explanation(const Mission &mission, const Command &command) const;
    QString eventExplanation(const Event &event) const;
    QString resolveText(const QByteArray &reference) const;
    std::vector<Field> fields(const Mission &mission, const Command &command) const;
};

struct Issue
{
    bool error = false;
    int chain = 0;
    int block = 0;
    int kind = -1;
    int record = -1;
    QString message;
};

std::vector<Issue> validate(const Mission &mission, const Catalog &catalog);
} // namespace bb
