#pragma once
#include "editor.h"

// Artificial MAP/BOX data; no files from the original game.
namespace fixture
{
QByteArray box(const QMap<QString, QByteArray> &files);
QMap<QString, QByteArray> texts();
QByteArray mission(int number);
QMap<QString, QByteArray> campaign();
void populate(bb::Editor &editor);

class Editor : public bb::Editor
{
public:
    Editor();
};
} // namespace fixture
