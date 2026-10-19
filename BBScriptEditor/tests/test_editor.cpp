#include "editor.h"
#include "fixtures.h"
#include "game_resources.h"
#include <QtTest>
#include <iostream>

static void initializeResources()
{
    Q_INIT_RESOURCE(resources);
}

class Tests : public QObject
{
    Q_OBJECT
private slots:

    void resolvedLettersKeepReferences()
    {
        fixture::Editor window;
        window.show();
        QTest::qWait(10);
        auto node = window.nodes[25];
        QVERIFY(node);
        auto &command = node->data().commands.front();
        const auto packet = bb::encodePacket(command);
        const auto reference = std::get<bb::Letter>(command.payload).text;
        QVERIFY(reference.contains('['));
        const auto resolved = window.catalog.resolveText(reference);
        QVERIFY(!resolved.isEmpty());
        QVERIFY(resolved != QString::fromLatin1(reference.split('\0').first()));
        QVERIFY(window.catalog.commandLabel(window.mission(), command).contains(resolved));
        QVERIFY(node->commandRows.front()->text().contains("First, place"));
        node->openRecord(0, 0);
        QCoreApplication::processEvents();
        auto field = node->form->findChild<QLineEdit *>("Text");
        QVERIFY(field);
        QCOMPARE(field->text(), QString::fromLatin1(reference.split('\0').first()));
        QCOMPARE(bb::encodePacket(command), packet);
        QCOMPARE(window.mission().serialize(), window.mission().source);
        window.closing = true;
    }

    void nativeSaveAndAtomicFailure()
    {
        bb::Catalog catalog;
        auto m = bb::Mission::parse(fixture::campaign()["m28.mis"], "M28.MIS");
        auto &b = m.chains[0].blocks[2];
        auto first = bb::newCommand(21);
        std::get<bb::Flag>(first.payload) = {4, 2};
        first.delay = 0;
        auto second = first;
        std::get<bb::Flag>(second.payload).value = 1;
        b.commands = {first, second};
        bb::Event event;
        event.type = 11;
        event.args = {4, 1, 0};
        event.destination = 31;
        b.events = {event};
        m.chains[0].current = 2;
        QTemporaryDir directory;
        QVERIFY(directory.isValid());
        auto path = directory.filePath("M28.MIS");
        m.save(path);
        auto bytes = bb::readFile(path);
        QCOMPARE(m.serialize(), bytes);
        auto before = bytes;
        m.chains[0].blocks[2].events[0].destination.reset();
        QVERIFY_EXCEPTION_THROWN(m.save(path), std::runtime_error);
        QCOMPARE(bb::readFile(path), before);
        m.chains[0].blocks[2].events[0].destination = 31;
        auto qa = qEnvironmentVariable("BB_CPP_QA_OUTPUT");
        if (!qa.isEmpty())
        {
            QDir().mkpath(qa);
            m.save(qa + "/M28.MIS");
        }
        // Changing delay sorts the file but never rebinds an open editor row.
        b = m.chains[0].blocks[2]; // Reacquire after save replacement.
        m.chains[0].blocks[2].commands[0].delay = 99;
        m.save(path);
        QCOMPARE(m.chains[0].blocks[2].commands[0].delay, quint32(99));
        QCOMPARE(m.serialize(), bb::readFile(path));
    }

    void choiceInteraction()
    {
        bb::Choice choice({{1, "One"}, {2, "Two"}, {3, "Three"}}, 1, 0, 255, false);
        choice.show();
        QTest::qWait(5);
        QSignalSpy changed(&choice, &bb::Choice::chosen);
        choice.lineEdit()->setFocus();
        QTest::keyClicks(choice.lineEdit(), "2");
        QCOMPARE(choice.lineEdit()->text(), QString("2"));
        QVERIFY(choice.commit());
        QCOMPARE(choice.committed, qint64(2));
        QCOMPARE(changed.count(), 1);
        choice.hidePopup();
        choice.lineEdit()->setText("999");
        choice.lineEdit()->setModified(true);
        QVERIFY(!choice.commit());
        QCOMPARE(choice.committed, qint64(2));
        choice.lineEdit()->setText("123");
        choice.lineEdit()->setModified(true);
        QVERIFY(choice.commit());
        QCOMPARE(choice.committed, qint64(123));
        bb::Choice fixed({{0, "Undecided"}, {1, "Victory"}, {2, "Defeat"}}, 1, 0, 255, true);
        fixed.show();
        QVERIFY(!fixed.isEditable());
    }

    void historyShortcuts()
    {
        fixture::Editor w;
        w.show();
        w.activateWindow();
        w.view->setFocus();
        QTest::qWait(20);
        const auto before = w.chain().blocks[0].commands.size();
        w.edit(
            "Add command",
            [&]
            {
                w.chain().blocks[0].commands.push_back(bb::newCommand(20));
            },
            true);
        QTRY_COMPARE(w.chain().blocks[0].commands.size(), before + 1);
        QCoreApplication::processEvents();
        QTest::keyClick(w.view, Qt::Key_Z, Qt::ControlModifier);
        QTRY_COMPARE(w.chain().blocks[0].commands.size(), before);
        QTest::keyClick(w.view, Qt::Key_Z, Qt::ControlModifier | Qt::ShiftModifier);
        QTRY_COMPARE(w.chain().blocks[0].commands.size(), before + 1);
        QTest::keyClick(w.view, Qt::Key_Z, Qt::ControlModifier);
        QTRY_COMPARE(w.chain().blocks[0].commands.size(), before);
        QTest::keyClick(w.view, Qt::Key_Y, Qt::ControlModifier);
        QTRY_COMPARE(w.chain().blocks[0].commands.size(), before + 1);
        w.closing = true;
    }

    void graphGestures()
    {
        fixture::Editor w;
        w.show();
        QTest::qWait(20);
        w.focusStart();
        auto node = w.nodes[0];
        QVERIFY(node);
        auto before = node->pos();
        auto start = w.view->mapFromScene(node->mapToScene(QPointF(300, 22)));
        QTest::mousePress(w.view->viewport(), Qt::LeftButton, Qt::NoModifier, start);
        QTest::mouseMove(w.view->viewport(), start + QPoint(70, 40), 5);
        QTest::mouseRelease(
            w.view->viewport(), Qt::LeftButton, Qt::NoModifier, start + QPoint(70, 40));
        QVERIFY(node->pos() != before);
        QVERIFY(!w.document().past.empty());
        auto edge = w.edges.front().get();
        QVERIFY(edge->target);
        int source = edge->source->block, event = edge->event;
        auto old = edge->source->data().events[event].destination;
        w.view->centerOn(edge->line);
        QCoreApplication::processEvents();
        w.selectEdge(edge);
        auto empty = w.view->viewport()->rect().bottomRight() - QPoint(10, 10);
        QTest::mousePress(w.view->viewport(), Qt::LeftButton, Qt::NoModifier, empty);
        QTest::mouseMove(w.view->viewport(), empty - QPoint(80, 20), 5);
        QTest::mouseRelease(
            w.view->viewport(), Qt::LeftButton, Qt::NoModifier, empty - QPoint(80, 20));
        QCOMPARE(w.selectedEdge, edge);
        w.selectEdge(nullptr);
        auto screen = w.view->viewport()->mapToGlobal(QPoint(200, 120));
        QTimer::singleShot(20,
                           [&]
                           {
                               auto menu = qobject_cast<QMenu *>(QApplication::activePopupWidget());
                               QVERIFY(menu);
                               QCOMPARE(menu->actions().first()->text(),
                                        QString("Delete connection"));
                               QVERIFY(menu->styleSheet().contains("#e05a5a"));
                               QCOMPARE(w.menuEdge, edge);
                               menu->setActiveAction(menu->actions().first());
                               QTest::keyClick(menu, Qt::Key_Return);
                           });
        w.connectionMenu(edge, screen);
        QTest::qWait(50);
        QVERIFY(!w.chain().blocks[source].events[event].destination);
        QCOMPARE(w.chain().blocks[source].events[event].type, quint8(1));
        w.history(false);
        QTest::qWait(5);
        QCOMPARE(w.chain().blocks[source].events[event].destination, old);
        // Drag a condition wire onto a different block input.
        edge = w.edges.front().get();
        auto target = w.nodes[25];
        QVERIFY(target);
        w.view->resetTransform();
        w.view->centerOn((edge->output() + target->mapToScene(QPointF(0, 22))) * .5);
        QCoreApplication::processEvents();
        auto from = w.view->mapFromScene(edge->output()),
             to = w.view->mapFromScene(target->mapToScene(QPointF(0, 22)));
        QTest::mousePress(w.view->viewport(), Qt::LeftButton, Qt::NoModifier, from);
        QVERIFY(w.view->dragging);
        QTest::mouseMove(w.view->viewport(), to, 5);
        QTest::mouseRelease(w.view->viewport(), Qt::LeftButton, Qt::NoModifier, to);
        QCOMPARE(w.chain().blocks[source].events[event].target(), 25);
        w.closing = true;
    }

    void allChainsAndForms()
    {
        fixture::Editor w;
        w.show();
        QTest::qWait(10);
        w.chainBox->setCurrentIndex(5);
        QCoreApplication::processEvents();
        for (int ch = 0; ch < 5; ++ch)
        {
            QVERIFY(w.nodes[ch * 32 + 31]);
        }
        auto node = w.nodes[2 * 32 + 31];
        node->data().commands.push_back(bb::newCommand(19, 2));
        w.rebuild();
        node = w.nodes[2 * 32 + 31];
        node->kind = 0;
        node->index = 0;
        node->buildForm();
        QCoreApplication::processEvents();
        auto player = node->form->findChild<bb::Choice *>("Packet player");
        QVERIFY(player);
        player->chosen(3);
        QCOMPARE(node->data().commands[0].player, quint8(3));
        QCOMPARE(w.mission().chains[0].blocks[31].commands.size(), size_t(0));
        auto delay = node->form->findChild<QLineEdit *>("Delay ticks");
        QVERIFY(delay);
        delay->setText("123");
        QVERIFY(w.commitInputs());
        QCOMPARE(node->data().commands[0].delay, quint32(123));
        delay->setText("not a number");
        QVERIFY(!w.commitInputs());
        QCOMPARE(node->data().commands[0].delay, quint32(123));
        delay->setText("123");
        QVERIFY(w.commitInputs());
        w.closing = true;
    }

    void polishedGeometryAndEveryForm()
    {
        fixture::Editor w;
        w.show();
        QTest::qWait(20);
        auto checkGeometry = [&]
        {
            for (auto n : w.nodes)
            {
                if (n)
                {
                    QVERIFY2(n->proxy->pos().y() + n->proxy->size().height() <=
                                 n->rect().bottom() + 1,
                             "Card must enclose its polished proxy widget");
                    QVERIFY2(n->proxy->size().width() <= n->rect().width() - 18,
                             "Proxy width must fit card");
                    for (auto other : w.nodes)
                    {
                        if (other && other != n)
                        {
                            QVERIFY2(
                                !n->sceneBoundingRect()
                                     .adjusted(2, 2, -2, -2)
                                     .intersects(other->sceneBoundingRect().adjusted(2, 2, -2, -2)),
                                "Cards must not overlap");
                        }
                    }
                }
            }
        };
        checkGeometry();
        for (int type = 1; type <= 25; ++type)
        {
            w.mission().chains[0].blocks[0].commands = {bb::newCommand(quint16(type))};
            w.rebuild();
            auto n = w.nodes[0];
            n->kind = 0;
            n->index = 0;
            n->buildForm();
            QCoreApplication::processEvents();
            checkGeometry();
            QVERIFY(n->summary);
            QVERIFY(!n->summary->text().isEmpty());
            QVERIFY(n->form->findChild<bb::Choice *>("Type"));
        }
        for (int type = 1; type <= 14; ++type)
        {
            w.mission().chains[0].blocks[0].events[0].type = quint8(type);
            w.rebuild();
            auto n = w.nodes[0];
            n->kind = 1;
            n->index = 0;
            n->buildForm();
            QCoreApplication::processEvents();
            checkGeometry();
        }
        auto qa = qEnvironmentVariable("BB_CPP_QA_OUTPUT");
        if (!qa.isEmpty())
        {
            QDir().mkpath(qa);
            w.grab().save(qa + "/form.png");
        }
        w.closing = true;
    }

    void originalAppearanceAndDescenders()
    {
        fixture::Editor w;
        w.show();
        QTest::qWait(20);
        auto node = w.nodes[0];
        QVERIFY(node);
        auto command = node->commandRows[0], event = node->eventRows[0];
        QCOMPARE(command->palette().color(QPalette::Button), QColor("#1b2b36"));
        QCOMPARE(event->palette().color(QPalette::Button), QColor("#322c38"));
        QCOMPARE(w.view->backgroundBrush().color(), QColor("#15212a"));
        bool commandsCount = false, eventsCount = false;
        for (auto label : node->panel->findChildren<QLabel *>())
        {
            commandsCount |= label->text() == "COMMANDS  (1)";
            eventsCount |= label->text() == "CONDITIONS / TRANSITIONS  (1)";
        }
        QVERIFY(commandsCount);
        QVERIFY(eventsCount);
        node->openRecord(0, 0);
        QCoreApplication::processEvents();
        QCOMPARE(command->palette().color(QPalette::Button), QColor("#3b5668"));
        node->closeForm();
        QCoreApplication::processEvents();
        QCOMPARE(command->palette().color(QPalette::Button), QColor("#1b2b36"));
        // Font/style changes must retain natural multiline height and descenders.
        // This fails if row height is pinned before Qt has polished its font.
        command->setText("going glyphs: gjpqy\nmagic gate: gjpqy");
        command->setStyleSheet(command->styleSheet() + "font-size:20px;");
        QCoreApplication::processEvents();
        node->resizeCard();
        QCoreApplication::processEvents();
        QVERIFY(command->height() >= command->sizeHint().height());
        QVERIFY(command->maximumHeight() == QWIDGETSIZE_MAX);
        QVERIFY(command->height() > 50);
        QCOMPARE(node->layout->contentsMargins(), QMargins(8, 5, 8, 8));

        // Reference grid: cosmetic lines every 25 units, or 100 at low zoom.
        struct GridProbe : bb::GraphView
        {
            using GraphView::drawBackground;
            using GraphView::GraphView;
        };

        GridProbe probe(&w, w.scene);
        QImage grid(128, 128, QImage::Format_RGB32);
        grid.fill(QColor("#15212a"));
        {
            QPainter painter(&grid);
            probe.drawBackground(&painter, QRectF(0, 0, 128, 128));
        }
        QCOMPARE(grid.pixelColor(25, 12), QColor("#1e2c36"));
        QCOMPARE(grid.pixelColor(26, 12), QColor("#15212a"));
        probe.scale(.4, .4);
        grid.fill(QColor("#15212a"));
        {
            QPainter painter(&grid);
            probe.drawBackground(&painter, QRectF(0, 0, 128, 128));
        }
        QCOMPARE(grid.pixelColor(25, 12), QColor("#15212a"));
        QCOMPARE(grid.pixelColor(100, 12), QColor("#1e2c36"));
        w.closing = true;
    }

    void campaignRoundTrips()
    {
        bb::Catalog catalog;
        catalog.letters = fixture::texts();
        auto archive = fixture::campaign();
        QCOMPARE(archive.size(), 30);
        for (int n = 1; n <= 30; ++n)
        {
            auto bytes = archive[QString("m%1.mis").arg(n)];
            auto m = bb::Mission::parse(bytes);
            QCOMPARE(m.title, QString("Synthetic mission %1").arg(n));
            QCOMPARE(m.objects.size(), size_t(2));
            QCOMPARE(m.objects[0].slot, 9);
            QCOMPARE(m.objects[0].objectClass, quint8(199));
            QCOMPARE(m.objects[0].x, quint8(3));
            QCOMPARE(m.tick, quint32(28));
            QCOMPARE(m.chains[0].blocks[0].events[0].target(), 25);
            QCOMPARE(m.serialize(), bytes);
            for (auto &issue : bb::validate(m, catalog))
            {
                QVERIFY2(!issue.error, qPrintable(issue.message));
            }
        }
    }

    void noGameFilesRequired()
    {
        bb::Editor window(false);
        window.show();
        QTest::qWait(5);
        QVERIFY(window.documents.empty());
        QVERIFY(window.catalog.letters.isEmpty());
        QVERIFY(window.catalog.textureIcons.isEmpty());
        QVERIFY(!window.save());
        window.showChecks();
        window.autoLayout();
        window.focusStart();
        window.history(false);
        bb::Catalog catalog;
        QCOMPARE(catalog.resolveText("[missing.txt]"), QString("[missing.txt]"));
        QVERIFY_EXCEPTION_THROWN(bb::readFile(":/data/mistext0.box"), std::runtime_error);
        QVERIFY_EXCEPTION_THROWN(bb::readFile(":/data/missions.box"), std::runtime_error);
        window.closing = true;
    }

    void externalGameDirectory()
    {
        QTemporaryDir folder;
        QVERIFY(folder.isValid());
        auto write = [&](const QString &name, const QByteArray &data)
        {
            QFile file(folder.filePath(name));
            QVERIFY(file.open(QIODevice::WriteOnly));
            QCOMPARE(file.write(data), data.size());
        };
        write("missions.box", fixture::box(fixture::campaign()));
        write("mistext0.box", fixture::box(fixture::texts()));
        bb::Editor window(false);
        window.setGameDirectory(folder.path());
        QCOMPARE(window.documents.size(), size_t(30));
        QVERIFY(window.catalog.resolveText("[editor-letter.txt]").startsWith("First, place"));
        QCOMPARE(bb::readBoxEntry(folder.filePath("mistext0.box"), "EDITOR-LETTER.TXT"),
                 fixture::texts()["editor-letter.txt"]);
        QVERIFY(!QFileInfo::exists(folder.filePath("textures")));
        window.closing = true;
    }

    void optionalRealCampaign()
    {
        auto folder = qEnvironmentVariable("BB_SCRIPTS_GAME_DIR");
        if (folder.isEmpty())
        {
            QSKIP("Set BB_SCRIPTS_GAME_DIR to run against your game installation");
        }
        bb::Catalog catalog;
        catalog.setGameDirectory(folder);
        QVERIFY(!catalog.letters.isEmpty());
        QVERIFY(!catalog.textureIcons.isEmpty());
        auto archive = bb::readBox(bb::readFile(QDir(folder).filePath("missions.box")));
        for (int n = 1; n <= 30; ++n)
        {
            auto bytes = archive[QString("m%1.mis").arg(n)];
            QVERIFY(!bytes.isEmpty());
            auto m = bb::Mission::parse(bytes);
            QCOMPARE(m.serialize(), bytes);
        }
    }

    void editedRoundtrip()
    {
        auto archive = fixture::campaign();
        for (int n = 1; n <= 30; ++n)
        {
            auto name = QString("m%1.mis").arg(n);
            auto original = bb::Mission::parse(archive[name]);
            auto m = original;
            auto command = bb::newCommand(19, 1);
            auto &p = std::get<bb::Property>(command.payload);
            p.object = 9;
            p.property = 21;
            p.value = 108;
            command.delay = 42;
            m.chains[2].blocks[7].commands.push_back(command);
            bb::Event e;
            e.type = 11;
            e.args = {4, 1, 0};
            e.destination = 200;
            m.chains[2].blocks[7].events.push_back(e);
            m.chains[2].current = 7;
            auto bytes = m.serialize();
            auto reloaded = bb::Mission::parse(bytes);
            QCOMPARE(reloaded.semantic(), m.semantic());
            QCOMPARE(bytes.first(m.scriptStart), m.source.first(m.scriptStart));
            QCOMPARE(bytes.mid(reloaded.scriptEnd), m.source.mid(m.scriptEnd));
            QCOMPARE(reloaded.chains[2].blocks[7].events.back().target(), 31);
            QCOMPARE(reloaded.chains[2].blocks[7].start, original.chains[2].blocks[7].start);
        }
    }

    void packetTypes()
    {
        for (int i = 1; i <= 25; ++i)
        {
            auto c = bb::newCommand(quint16(i), 3);
            QCOMPARE(bb::decodePacket(bb::encodePacket(c)).type, quint16(i));
            QCOMPARE(bb::encodePacket(bb::decodePacket(bb::encodePacket(c))), bb::encodePacket(c));
        }
        auto c = bb::newCommand(7);
        std::get<bb::Selection>(c.payload).objects = {1, 9, 4999};
        c.trailing.clear();
        auto d = bb::decodePacket(bb::encodePacket(c));
        QCOMPARE(std::get<bb::Selection>(d.payload).objects, std::vector<qint32>({1, 9, 4999}));
    }

    void malformed()
    {
        QVERIFY_EXCEPTION_THROWN(bb::Mission::parse("MAP"), std::runtime_error);
        auto c = bb::decodePacket(QByteArray::fromHex("1300100000"));
        QVERIFY(c.malformed);
        QCOMPARE(bb::encodePacket(c), QByteArray::fromHex("1300100000"));
    }

    void graphSmoke()
    {
        fixture::Editor w;
        w.show();
        QTest::qWait(30);
        QCOMPARE(w.documents.size(), size_t(30));
        QVERIFY(w.nodes[31]);
        auto before = w.mission().semantic();
        w.edit(
            "add",
            [&]
            {
                w.chain().blocks[0].commands.push_back(bb::newCommand(20));
            },
            true);
        QCoreApplication::processEvents();
        QVERIFY(w.document().dirty());
        w.history(false);
        QCoreApplication::processEvents();
        QCOMPARE(w.mission().semantic(), before);
        w.history(true);
        QCoreApplication::processEvents();
        QVERIFY(w.document().dirty());
        w.showChecks();
        QVERIFY(w.issueList);
        for (int mission = 0; mission < 30; ++mission)
        {
            w.documentIndex = mission;
            for (int ch = 0; ch < 5; ++ch)
            {
                w.chainIndex = ch;
                w.rebuild();
                for (auto n : w.nodes)
                {
                    if (n)
                    {
                        if (!n->data().commands.empty())
                        {
                            n->kind = 0;
                            n->index = 0;
                            n->buildForm();
                            n->closeForm();
                        }
                        if (!n->data().events.empty())
                        {
                            n->kind = 1;
                            n->index = 0;
                            n->buildForm();
                            n->closeForm();
                        }
                    }
                }
                QCoreApplication::sendPostedEvents(nullptr, QEvent::DeferredDelete);
            }
        }
        w.closing = true;
    }

    void fieldModel()
    {
        bb::Catalog cat;
        auto m = bb::Mission::parse(fixture::campaign()["m4.mis"]);
        auto c = bb::newCommand(19);
        auto &p = std::get<bb::Property>(c.payload);
        p.property = 17;
        auto fields = cat.fields(m, c);
        QCOMPARE(fields.size(), size_t(3));
        QVERIFY(fields.back().fixed);
        fields.back().set(c, 3);
        QCOMPARE(p.value, 3);
        auto decoded = bb::decodePacket(bb::encodePacket(c));
        QCOMPARE(std::get<bb::Property>(decoded.payload).value, 3);
    }
};

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    initializeResources();
    Tests tests;
    return QTest::qExec(&tests, argc, argv);
}

#include "test_editor.moc"
