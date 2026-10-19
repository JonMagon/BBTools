#pragma once
#include <QtGui>

namespace bb
{
// Read-only access to the user's installation; no game artwork is bundled.
QByteArray readBoxEntry(const QString &archive, const QString &name);
QMap<int, QIcon> loadTerrainIcons(const QString &directory);
} // namespace bb
