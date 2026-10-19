#include "editor.h"
#include "editor_support.h"
#include <algorithm>
#include <cmath>

namespace bb
{
using namespace detail;

void Editor::chooseGameDirectory()
{
    auto directory = QFileDialog::getExistingDirectory(
        this, "Select installed game data folder", catalog.gameDirectory);
    if (directory.isEmpty())
    {
        return;
    }
    try
    {
        setGameDirectory(directory);
    }
    catch (const std::exception &error)
    {
        QMessageBox::warning(this, "Game data", error.what());
    }
}

void Editor::setGameDirectory(const QString &directory, bool loadMissions)
{
    const auto path = QFileInfo(directory).absoluteFilePath();
    catalog.setGameDirectory(path);
    if (preferences)
    {
        preferences->setValue("gameDirectory", path);
    }
    if (loadMissions && QFileInfo::exists(QDir(path).filePath("missions.box")))
    {
        loadCampaign();
    }
    else if (!documents.empty())
    {
        rebuild();
    }
}

void Editor::loadCampaign(const QString &path)
{
    QString archive = path.isEmpty() ? QDir(catalog.gameDirectory).filePath("missions.box") : path;
    if (path.isEmpty() && (catalog.gameDirectory.isEmpty() || !QFileInfo::exists(archive)))
    {
        return;
    }
    auto entries = readBox(readFile(archive));
    auto folder = QFileInfo(archive).absolutePath();
    if (QFileInfo::exists(QDir(folder).filePath("mistext0.box")))
    {
        catalog.setGameDirectory(folder);
    }
    int first = int(documents.size());
    for (int n = 1; n <= 30; ++n)
    {
        auto name = QString("M%1.MIS").arg(n);
        if (!entries.contains(name.toLower()))
        {
            continue;
        }
        auto d = std::make_unique<Document>();
        d->mission = Mission::parse(entries[name.toLower()], name);
        d->savedSemantic = d->mission.semantic();
        documents.push_back(std::move(d));
        QSignalBlocker blocker(missionBox);
        missionBox->addItem(name + " — " + documents.back()->mission.title);
    }
    if (int(documents.size()) == first)
    {
        throw std::runtime_error("Archive has no campaign missions M1.MIS–M30.MIS");
    }
    missionBox->setMaxVisibleItems(missionBox->count());
    documentIndex = first;
    {
        QSignalBlocker blocker(missionBox);
        missionBox->setCurrentIndex(first);
    }
    rebuild(true);
}

void Editor::openFile(const QString &path)
{
    auto folder = QFileInfo(path).absolutePath();
    if (catalog.gameDirectory.isEmpty() && QFileInfo::exists(QDir(folder).filePath("mistext0.box")))
    {
        catalog.setGameDirectory(folder);
    }
    auto d = std::make_unique<Document>();
    d->mission = Mission::parse(readFile(path), QFileInfo(path).fileName());
    d->mission.path = QFileInfo(path).absoluteFilePath();
    d->savedSemantic = d->mission.semantic();
    documents.push_back(std::move(d));
    documentIndex = int(documents.size()) - 1;
    {
        QSignalBlocker blocker(missionBox);
        missionBox->addItem(mission().name + " — " + mission().title);
        missionBox->setCurrentIndex(documentIndex);
    }
    missionBox->setMaxVisibleItems(missionBox->count());
    rebuild(true);
}

bool Editor::save(bool saveAs)
{
    if (documents.empty())
    {
        return false;
    }
    if (!commitInputs())
    {
        return false;
    }
    auto issues = validate(mission(), catalog);
    if (std::any_of(issues.begin(),
                    issues.end(),
                    [](auto &i)
                    {
                        return i.error;
                    }))
    {
        showChecks();
        return false;
    }
    auto path = mission().path;
    if (saveAs || path.isEmpty())
    {
        path = QFileDialog::getSaveFileName(this,
                                            "Save mission",
                                            path.isEmpty() ? mission().name : path,
                                            "Mission/save (*.mis *.sav);;All files (*)");
        if (path.isEmpty())
        {
            return false;
        }
    }
    try
    {
        mission().save(path);
        document().savedSemantic = mission().semantic();
        {
            QSignalBlocker blocker(missionBox);
            missionBox->setItemText(documentIndex, mission().name + " — " + mission().title);
        }
        changed();
        return true;
    }
    catch (const std::exception &e)
    {
        QMessageBox::warning(this, "Save failed", e.what());
        return false;
    }
}

void Editor::restorePreferences()
{
    if (!preferences)
    {
        return;
    }
    restoreGeometry(preferences->value("window/geometry").toByteArray());
    if (documents.empty())
    {
        return;
    }
    int doc = preferences->value("mission", 0).toInt(), ch = preferences->value("chain", 0).toInt();
    if (doc >= 0 && doc < int(documents.size()))
    {
        documentIndex = doc;
        QSignalBlocker blocker(missionBox);
        missionBox->setCurrentIndex(doc);
    }
    chainIndex = qBound(0, ch, 5);
    {
        QSignalBlocker blocker(chainBox);
        chainBox->setCurrentIndex(chainIndex);
    }
    rebuild();
    QTimer::singleShot(0,
                       this,
                       [this]
                       {
                           QTimer::singleShot(
                               0,
                               this,
                               [this]
                               {
                                   if (!preferences->contains("view/zoom"))
                                   {
                                       focusStart();
                                       return;
                                   }
                                   double zoom = preferences->value("view/zoom", .6).toDouble();
                                   if (!std::isfinite(zoom) || zoom < .15 || zoom > 2.5)
                                   {
                                       zoom = .6;
                                   }
                                   view->resetTransform();
                                   view->scale(zoom, zoom);
                                   auto x = preferences->value("view/x", 0).toDouble(),
                                        y = preferences->value("view/y", 0).toDouble();
                                   if (std::isfinite(x) && std::isfinite(y))
                                   {
                                       view->centerOn(x, y);
                                   }
                               });
                       });
}

void Editor::writePreferences()
{
    if (!preferences)
    {
        return;
    }
    preferences->setValue("window/geometry", saveGeometry());
    preferences->setValue("mission", documentIndex);
    preferences->setValue("chain", chainIndex);
    preferences->setValue("view/zoom", view->transform().m11());
    auto center = view->mapToScene(view->viewport()->rect().center());
    preferences->setValue("view/x", center.x());
    preferences->setValue("view/y", center.y());
    preferences->sync();
}

void Editor::closeEvent(QCloseEvent *e)
{
    if (!commitInputs())
    {
        e->ignore();
        return;
    }
    int previous = documentIndex;
    for (int i = 0; i < int(documents.size()); ++i)
    {
        if (documents[i]->dirty())
        {
            auto answer = QMessageBox::question(
                this,
                "Unsaved mission",
                QString("Save changes to %1?").arg(documents[i]->mission.name),
                QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
            if (answer == QMessageBox::Cancel)
            {
                e->ignore();
                return;
            }
            if (answer == QMessageBox::Save)
            {
                documentIndex = i;
                if (i != previous)
                {
                    rebuild();
                }
                if (!save())
                {
                    e->ignore();
                    return;
                }
            }
        }
    }
    documentIndex = previous;
    writePreferences();
    closing = true;
    e->accept();
}

} // namespace bb
