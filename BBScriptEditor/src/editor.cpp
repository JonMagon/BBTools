#include "editor.h"
#include "editor_support.h"
#include <algorithm>
#include <cmath>
#include <limits>

namespace bb
{
using namespace detail;

bool Document::dirty() const
{
    return mission.semantic() != savedSemantic;
}

Document &Editor::document() const
{
    return *documents.at(documentIndex);
}

Mission &Editor::mission() const
{
    return document().mission;
}

Chain &Editor::chain() const
{
    return mission().chains[qBound(0, chainIndex, ChainCount - 1)];
}

Editor::Editor(bool settings, const QString &gameDirectory)
{
    if (settings)
    {
        preferences = std::make_unique<QSettings>(
            QSettings::IniFormat, QSettings::UserScope, "BBTools", "BBScriptEditor");
        QSettings previous(QSettings::IniFormat, QSettings::UserScope, "BBTools", "ScriptsEditor");
        if (preferences->allKeys().isEmpty())
        {
            for (const auto &key : previous.allKeys())
            {
                preferences->setValue(key, previous.value(key));
            }
        }
    }
    setWindowTitle("BBScriptEditor");
    resize(1440, 900);
    scene = new QGraphicsScene(this);
    view = new GraphView(this, scene);
    auto central = new QWidget;
    auto outer = new QVBoxLayout(central);

    auto toolbar = new QHBoxLayout;
    missionBox = new NoWheelComboBox;
    missionBox->setMinimumWidth(240);
    chainBox = new NoWheelComboBox;
    for (int i = 0; i < 5; ++i)
    {
        chainBox->addItem(QString("Chain %1").arg(i), i);
    }
    chainBox->addItem("All chains", 5);
    allBlocks = new QCheckBox("Show empty blocks", this);
    allBlocks->hide();
    search = new QLineEdit;
    search->setPlaceholderText("Find command, condition or block… Enter: next match");
    toolbar->addWidget(missionBox);
    toolbar->addWidget(chainBox);

    auto button = [&](QString label, std::function<void()> cb, QKeySequence shortcut = {})
    {
        auto b = new QPushButton(label);
        toolbar->addWidget(b);
        connect(b, &QPushButton::clicked, this, cb);
        if (!shortcut.isEmpty())
        {
            auto action = new QAction(this);
            action->setShortcut(shortcut);
            addAction(action);
            connect(action, &QAction::triggered, this, cb);
        }
        return b;
    };
    auto menuAction = [this](QMenu *menu,
                             const QString &label,
                             std::function<void()> callback,
                             QKeySequence shortcut = {})
    {
        auto action = menu->addAction(label);
        action->setShortcut(shortcut);
        connect(action, &QAction::triggered, this, callback);
        return action;
    };
    auto fileMenu = menuBar()->addMenu("&File");
    menuAction(fileMenu,
               "Game folder…",
               [this]
               {
                   chooseGameDirectory();
               });
    menuAction(
        fileMenu,
        "Open file…",
        [this]
        {
            auto path = QFileDialog::getOpenFileName(
                this,
                "Open mission / save / archive",
                {},
                "Missions and archives (*.mis *.MIS *.sav *.SAV *.box *.BOX);;All files (*)");
            if (path.isEmpty())
            {
                return;
            }
            try
            {
                if (QFileInfo(path).suffix().compare("box", Qt::CaseInsensitive) == 0)
                {
                    loadCampaign(path);
                }
                else
                {
                    openFile(path);
                }
            }
            catch (const std::exception &e)
            {
                QMessageBox::warning(this, "Open failed", e.what());
            }
        },
        QKeySequence::Open);
    fileMenu->addSeparator();
    menuAction(
        fileMenu,
        "&Save",
        [this]
        {
            save();
        },
        QKeySequence::Save);
    menuAction(
        fileMenu,
        "Save &As…",
        [this]
        {
            save(true);
        },
        QKeySequence::SaveAs);
    fileMenu->addSeparator();
    menuAction(
        fileMenu,
        "E&xit",
        [this]
        {
            close();
        },
        QKeySequence::Quit);

    auto editMenu = menuBar()->addMenu("&Edit");
    undoAction = menuAction(
        editMenu,
        "&Undo",
        [this]
        {
            history(false);
        },
        QKeySequence("Ctrl+Z"));
    redoAction = menuAction(editMenu,
                            "&Redo",
                            [this]
                            {
                                history(true);
                            });
    redoAction->setShortcuts({QKeySequence("Ctrl+Shift+Z"), QKeySequence("Ctrl+Y")});

    auto helpMenu = menuBar()->addMenu("&Help");
    menuAction(helpMenu,
               "&About BBScriptEditor…",
               [this]
               {
                   showAbout();
               });
    button("Check",
           [this]
           {
               showChecks();
           });
    toolbar->addWidget(search);
    button("Fit graph",
           [this]
           {
               fit();
           });
    button("100%",
           [this]
           {
               view->resetTransform();
           });
    button("Auto layout",
           [this]
           {
               autoLayout();
           });
    outer->addLayout(toolbar);
    outer->addWidget(view);
    setCentralWidget(central);
    connect(missionBox,
            &QComboBox::currentIndexChanged,
            this,
            [this](int i)
            {
                if (rebuilding || i < 0)
                {
                    return;
                }
                documentIndex = i;
                rebuild(true);
            });
    connect(chainBox,
            &QComboBox::currentIndexChanged,
            this,
            [this](int i)
            {
                if (rebuilding)
                {
                    return;
                }
                chainIndex = i;
                rebuild(true);
            });
    connect(allBlocks,
            &QCheckBox::toggled,
            this,
            [this]
            {
                rebuild(true);
            });
    connect(search, &QLineEdit::returnPressed, this, &Editor::findNext);
    connect(search, &QLineEdit::textChanged, this, &Editor::highlightSearch);
    QString directory = gameDirectory;
    if (directory.isEmpty() && preferences)
    {
        directory = preferences->value("gameDirectory").toString();
    }
    if (!directory.isEmpty() && QDir(directory).exists())
    {
        setGameDirectory(directory);
    }
    restorePreferences();
    if (documents.empty())
    {
        auto welcome = scene->addText("Choose File → Game folder… or open a mission.");
        welcome->setDefaultTextColor(QColor("#e4edf3"));
        view->centerOn(welcome);
        undoAction->setEnabled(false);
        redoAction->setEnabled(false);
    }
}

Editor::~Editor()
{
    closing = true;
    view->cancelConnection();
    edges.clear();
    nodes.fill(nullptr);
    view->setScene(nullptr);
    scene->clear();
}

void Editor::rebuild(bool center)
{
    if (closing || documents.empty())
    {
        return;
    }
    rebuilding = true;
    const int generation = ++layoutGeneration;
    const int documentId = documentIndex, chainMode = chainIndex;
    auto savedPositions = document().positions;
    formPending = false;
    view->cancelConnection();
    view->moving = nullptr;
    view->beforeDrag.reset();
    selectedEdge = hoverEdge = menuEdge = nullptr;
    edges.clear();
    for (auto node : nodes)
    {
        if (node)
        {
            node->ready = false;
            for (auto child : node->panel->findChildren<QWidget *>())
            {
                child->blockSignals(true);
            }
        }
    }
    nodes.fill(nullptr);
    scene->clear();
    double chainTop = 0, chainBottom = 0;
    for (int ch = 0; ch < 5; ++ch)
    {
        if (chainIndex != 5 && chainIndex != ch)
        {
            continue;
        }
        auto &displayChain = mission().chains[ch];
        QSet<int> visible{31, qMin<int>(displayChain.current, 31)};
        for (int b = 0; b < 32; ++b)
        {
            auto &block = displayChain.blocks[b];
            if (allBlocks->isChecked() || !block.commands.empty() || !block.events.empty())
            {
                visible.insert(b);
            }
            for (auto &e : block.events)
            {
                if (e.destination)
                {
                    visible.insert(e.target());
                }
            }
        }
        auto heading =
            scene->addText(QString("CHAIN %1   •   %2 visible / 32 blocks   •   outcome %3")
                               .arg(ch)
                               .arg(visible.size())
                               .arg(mission().outcomes[ch]));
        heading->setDefaultTextColor(QColor("#e4edf3"));
        heading->setPos(0, chainTop);
        // Original compact breadth-first placement, wrapping after four columns.
        QSet<int> incoming;
        for (int b : visible)
        {
            if (b != 31)
            {
                for (auto &e : displayChain.blocks[b].events)
                {
                    if (e.enabled && e.destination)
                    {
                        incoming.insert(e.target());
                    }
                }
            }
        }
        QList<QPair<int, int>> todo;
        for (int b = 0; b < 31; ++b)
        {
            if (visible.contains(b) && !incoming.contains(b))
            {
                todo.append({b, 0});
            }
        }
        QMap<int, QPointF> defaults;
        std::array<int, 4> rows{};
        while (defaults.size() < visible.size() - (visible.contains(31) ? 1 : 0))
        {
            if (todo.isEmpty())
            {
                for (int b = 0; b < 31; ++b)
                {
                    if (visible.contains(b) && !defaults.contains(b))
                    {
                        todo.append({b, 0});
                        break;
                    }
                }
            }
            if (todo.isEmpty())
            {
                break;
            }
            auto [b, depth] = todo.takeFirst();
            if (b == 31 || !visible.contains(b) || defaults.contains(b))
            {
                continue;
            }
            int col = depth % 4, row = qMax(depth / 4, rows[col]);
            rows[col] = row + 1;
            defaults[b] = QPointF(col * 462.5, row * 265);
            for (auto &e : displayChain.blocks[b].events)
            {
                if (e.enabled && e.destination)
                {
                    todo.append({e.target(), depth + 1});
                }
            }
        }
        defaults[31] = QPointF(0, *std::max_element(rows.begin(), rows.end()) * 265 + 60);
        QMap<int, QList<Node *>> rowNodes;
        for (int b = 0; b < 32; ++b)
        {
            if (visible.contains(b))
            {
                auto n = new Node(this, ch, b);
                scene->addItem(n);
                nodes[ch * 32 + b] = n;
                n->layoutRow = int(defaults[b].y());
                rowNodes[int(defaults[b].y())].append(n);
            }
        }

        double rowY = chainTop + 55;
        for (auto row = rowNodes.begin(); row != rowNodes.end(); ++row)
        {
            double tallest = 0;
            for (auto node : row.value())
            {
                node->setPos(document().positions.value(ch * 32 + node->block,
                                                        QPointF(defaults[node->block].x(), rowY)));
                tallest = qMax(tallest, node->rect().height());
            }
            rowY += tallest + 95;
        }
        for (auto node : nodes)
        {
            if (node && node->chainId == ch)
            {
                chainBottom = qMax(chainBottom, node->y() + node->rect().height());
            }
        }
        chainTop = chainBottom + 180;
    }
    rebuilding = false;
    for (auto n : nodes)
    {
        if (n)
        {
            makeRoom(n);
        }
    }
    relink();
    updateTitle();
    highlightSearch();
    if (checks && checks->isVisible())
    {
        refreshChecks();
    }
    // Qt finalizes proxy layouts after they enter the scene. Reapply default
    // grid rows using the polished card heights, exactly as the Python editor.
    QTimer::singleShot(0,
                       this,
                       [this, generation, documentId, chainMode, savedPositions, center]
                       {
                           QTimer::singleShot(
                               0,
                               this,
                               [this, generation, documentId, chainMode, savedPositions, center]
                               {
                                   if (closing || generation != layoutGeneration ||
                                       documentId != documentIndex || chainMode != chainIndex)
                                   {
                                       return;
                                   }
                                   rebuilding = true;
                                   double top = 55;
                                   for (int ch = 0; ch < 5; ++ch)
                                   {
                                       QMap<int, QList<Node *>> rows;
                                       for (auto node : nodes)
                                       {
                                           if (node && node->chainId == ch)
                                           {
                                               node->resizeCard();
                                               rows[node->layoutRow].append(node);
                                           }
                                       }
                                       if (rows.isEmpty())
                                       {
                                           continue;
                                       }
                                       for (auto row = rows.begin(); row != rows.end(); ++row)
                                       {
                                           double height = 0;
                                           for (auto node : row.value())
                                           {
                                               node->setPos(savedPositions.value(
                                                   ch * 32 + node->block, QPointF(node->x(), top)));
                                               height = qMax(height, node->rect().height());
                                           }
                                           top += height + 95;
                                       }
                                       double bottom = 0;
                                       for (auto node : nodes)
                                       {
                                           if (node && node->chainId == ch)
                                           {
                                               bottom =
                                                   qMax(bottom, node->y() + node->rect().height());
                                           }
                                       }
                                       top = bottom + 180;
                                   }
                                   document().positions = savedPositions;
                                   rebuilding = false;
                                   updateEdges();
                                   if (center)
                                   {
                                       focusStart();
                                   }
                               });
                       });
}

void Editor::relink()
{
    selectedEdge = hoverEdge = menuEdge = nullptr;
    for (auto &edge : edges)
    {
        delete edge->line;
        delete edge->arrow;
        delete edge->port;
        delete edge->stub;
    }
    edges.clear();
    for (auto node : nodes)
    {
        if (node)
        {
            for (int i = 0; i < int(node->data().events.size()); ++i)
            {
                auto e = std::make_unique<Edge>();
                e->source = node;
                e->event = i;
                auto target = node->data().events[i].target();
                e->target = target >= 0 ? nodes[node->chainId * 32 + target] : nullptr;
                e->line = scene->addPath({});
                e->line->setZValue(-1);
                e->arrow = scene->addPath({});
                e->arrow->setZValue(3);
                e->port = scene->addEllipse({});
                e->port->setZValue(3);
                e->stub = scene->addSimpleText("");
                e->stub->setZValue(3);
                for (auto item :
                     std::array<QGraphicsItem *, 4>{e->line, e->arrow, e->port, e->stub})
                {
                    item->setAcceptedMouseButtons(Qt::NoButton);
                }
                e->update();
                edges.push_back(std::move(e));
            }
        }
    }
}

void Editor::updateEdges()
{
    if (rebuilding)
    {
        return;
    }
    for (auto &e : edges)
    {
        e->update();
    }
}

void Editor::remember(Node *node)
{
    if (!rebuilding && !closing)
    {
        document().positions[node->chainId * 32 + node->block] = node->pos();
    }
}

void Editor::makeRoom(Node *expanded)
{
    if (rebuilding)
    {
        return;
    }
    bool prior = rebuilding;
    rebuilding = true;
    std::vector<Node *> ordered;
    for (auto n : nodes)
    {
        if (n)
        {
            ordered.push_back(n);
        }
    }
    std::stable_sort(ordered.begin(),
                     ordered.end(),
                     [](auto a, auto b)
                     {
                         if (a->y() != b->y())
                         {
                             return a->y() < b->y();
                         }
                         return a->chainId * 32 + a->block < b->chainId * 32 + b->block;
                     });
    // Walk the original top-to-bottom order once. Re-sorting/comparing mutated
    // Y positions can miss ties introduced by an earlier displacement.
    QSet<Node *> displaced;
    for (size_t i = 0; i < ordered.size(); ++i)
    {
        for (size_t j = i + 1; j < ordered.size(); ++j)
        {
            auto upper = ordered[i], lower = ordered[j];
            auto a = upper->sceneBoundingRect(), b = lower->sceneBoundingRect();
            if (a.right() > b.left() && a.left() < b.right() && b.top() < a.bottom() + 25)
            {
                lower->setY(a.bottom() + 25);
                displaced.insert(lower);
            }
        }
    }
    rebuilding = prior;
    for (auto node : displaced)
    {
        remember(node);
    }
    updateEdges();
    Q_UNUSED(expanded);
}

void Editor::updateTitle()
{
    if (documents.empty())
    {
        return;
    }
    setWindowTitle(mission().name + (document().dirty() ? " *" : "") + " — BBScriptEditor");
    undoAction->setEnabled(!document().past.empty());
    redoAction->setEnabled(!document().future.empty());
    int visible = 0;
    for (auto node : nodes)
    {
        visible += node != nullptr;
    }
    statusBar()->showMessage(QString("%1 · file tick %2 · %3 visible blocks")
                                 .arg(mission().name)
                                 .arg(mission().tick)
                                 .arg(visible));
}

void Editor::selectEdge(Edge *e)
{
    if (selectedEdge)
    {
        selectedEdge->selected = false;
        selectedEdge->update();
    }
    selectedEdge = e;
    if (e)
    {
        e->selected = true;
        e->update();
    }
    view->viewport()->setCursor(e ? Qt::ArrowCursor : Qt::OpenHandCursor);
}

void Editor::connectEvent(int b, int e, int target, int sourceChain)
{
    int ch = sourceChain < 0 ? chainIndex : sourceChain;
    edit("Connect event",
         [&]
         {
             mission().chains[ch].blocks[b].events[e].destination = quint8(target);
         });
    relink();
}

void Editor::newConnection(int b, int event, QPointF position, QPoint screen, int sourceChain)
{
    int doc = documentIndex, ch = sourceChain < 0 ? chainIndex : sourceChain, mode = chainIndex;
    QTimer::singleShot(0,
                       this,
                       [this, b, event, position, screen, doc, ch, mode]
                       {
                           if (doc != documentIndex || mode != chainIndex)
                           {
                               return;
                           }
                           auto free = unusedBlocks(mission().chains[ch]);
                           QMenu menu(this);
                           auto create = menu.addAction("Create new block here");
                           create->setEnabled(!free.empty());
                           auto choose = menu.addMenu("Choose unused block");
                           for (int id : free)
                           {
                               auto a = choose->addAction(QString("Block %1").arg(id));
                               a->setData(id);
                           }
                           choose->setEnabled(!free.empty());
                           auto selected = menu.exec(screen);
                           if (!selected)
                           {
                               return;
                           }
                           int id = selected == create ? free.front() : selected->data().toInt();
                           edit(
                               "Create and connect block",
                               [&]
                               {
                                   mission().chains[ch].blocks[b].events[event].destination =
                                       quint8(id);
                                   document().positions[ch * 32 + id] = position;
                               },
                               true);
                       });
}

void Editor::connectionMenu(Edge *edge, QPoint point)
{
    int b = edge->source->block, i = edge->event, doc = documentIndex, ch = edge->source->chainId,
        mode = chainIndex;
    menuEdge = edge;
    view->hover(edge);
    QTimer::singleShot(
        0,
        this,
        [this, b, i, point, doc, ch, mode]
        {
            if (doc != documentIndex || mode != chainIndex)
            {
                menuEdge = nullptr;
                return;
            }
            QMenu menu(this);
            menu.setStyleSheet(
                "QMenu::item {color:#e05a5a;} QMenu::item:selected {color:#ff8585;}");
            auto remove = menu.addAction("Delete connection");
            auto selected = menu.exec(point);
            menuEdge = nullptr;
            view->hover(view->edgeAt(view->viewport()->mapFromGlobal(QCursor::pos())));
            if (selected == remove)
            {
                QTimer::singleShot(
                    0,
                    this,
                    [this, b, i, doc, ch, mode]
                    {
                        if (doc != documentIndex || mode != chainIndex)
                        {
                            return;
                        }
                        if (selectedEdge && selectedEdge->source->chainId == ch &&
                            selectedEdge->source->block == b && selectedEdge->event == i)
                        {
                            return;
                        }
                        edit("Disconnect event",
                             [&]
                             {
                                 mission().chains[ch].blocks[b].events[i].destination.reset();
                             });
                        relink();
                    });
            }
        });
}

void Editor::blockMenu(Node *node, QPoint point)
{
    int b = node->block, doc = documentIndex, ch = node->chainId, mode = chainIndex;
    QTimer::singleShot(
        0,
        this,
        [this, b, point, doc, ch, mode]
        {
            if (doc != documentIndex || mode != chainIndex)
            {
                return;
            }
            QMenu menu(this);
            auto current = menu.addAction("Set current block in file");
            current->setEnabled(mission().chains[ch].current != b);
            auto remove = menu.addAction(b == 31 ? "Clear background block…" : "Delete block…");
            remove->setEnabled(mission().chains[ch].current != b);
            auto action = menu.exec(point);
            if (action == current)
            {
                edit(
                    "Set current block",
                    [&]
                    {
                        mission().chains[ch].current = quint8(b);
                    },
                    true);
            }
            if (action == remove &&
                QMessageBox::question(this,
                                      "Delete block",
                                      QString("Clear block %1? Incoming conditions will remain, "
                                              "with disconnected outputs.")
                                          .arg(b)) == QMessageBox::Yes)
            {
                edit(
                    "Delete block",
                    [&]
                    {
                        auto &block = mission().chains[ch].blocks[b];
                        block.commands.clear();
                        block.events.clear();
                        for (auto &source : mission().chains[ch].blocks)
                        {
                            for (auto &e : source.events)
                            {
                                if (e.target() == b)
                                {
                                    e.destination.reset();
                                }
                            }
                        }
                    },
                    true);
            }
        });
}

void Editor::autoLayout()
{
    if (documents.empty())
    {
        return;
    }
    auto before = snapshot();
    for (int ch = 0; ch < 5; ++ch)
    {
        if (chainIndex == 5 || chainIndex == ch)
        {
            for (int b = 0; b < 32; ++b)
            {
                document().positions.remove(ch * 32 + b);
            }
        }
    }
    rebuild();
    record(before, "Auto layout");
    fit();
}

void Editor::focusStart()
{
    if (documents.empty())
    {
        return;
    }
    view->resetTransform();
    int ch = chainIndex == 5 ? 0 : chainIndex;
    auto current = mission().chains[ch].current;
    auto node = current < 32 ? nodes[ch * 32 + current] : nullptr;
    if (node)
    {
        view->centerOn(node->pos() + QPointF(370, 250));
    }
}

void Editor::fit()
{
    QRectF bounds;
    for (auto n : nodes)
    {
        if (n)
        {
            bounds =
                bounds.isNull() ? n->sceneBoundingRect() : bounds.united(n->sceneBoundingRect());
        }
    }
    if (!bounds.isEmpty())
    {
        view->fitInView(bounds.adjusted(-70, -70, 70, 70), Qt::KeepAspectRatio);
        auto zoom = view->transform().m11();
        if (zoom > .9)
        {
            view->scale(.9 / zoom, .9 / zoom);
        }
    }
}

bool Editor::commitInputs()
{
    if (auto active = QApplication::focusWidget())
    {
        if (auto field = qobject_cast<QLineEdit *>(active))
        {
            QMetaObject::invokeMethod(field, "editingFinished", Qt::DirectConnection);
        }
    }
    bool ok = true;
    for (auto node : nodes)
    {
        if (node)
        {
            for (auto choice : node->panel->findChildren<Choice *>())
            {
                if (choice->isVisible())
                {
                    ok = choice->commit() && ok;
                }
            }
            for (auto field : node->panel->findChildren<QLineEdit *>())
            {
                if (auto number = dynamic_cast<IntegerEdit *>(field); number && number->isVisible())
                {
                    ok = number->commit() && ok;
                }
                if (field->property("invalid").toBool())
                {
                    ok = false;
                }
            }
        }
    }
    if (!ok)
    {
        statusBar()->showMessage("Correct the highlighted input before continuing.");
    }
    return ok;
}

void Editor::highlightSearch()
{
    auto query = search->text().trimmed();
    int matches = 0;
    for (auto n : nodes)
    {
        if (n)
        {
            QString text = "block " + QString::number(n->block);
            for (auto &c : n->data().commands)
            {
                text += " " + catalog.commandLabel(mission(), c);
            }
            for (auto &e : n->data().events)
            {
                text += " " + catalog.eventLabel(mission(), e);
            }
            bool match = !query.isEmpty() && (text.contains(query, Qt::CaseInsensitive) ||
                                              query == QString::number(n->block));
            matches += match;
            bool current = mission().chains[n->chainId].current == n->block;
            n->setPen(QPen(QColor(match     ? "#ffc76a"
                                  : current ? "#70dfb4"
                                            : "#607482"),
                           match || current ? 3 : 1));
        }
    }
    if (!query.isEmpty())
    {
        statusBar()->showMessage(QString("%1 matching blocks · Enter: next").arg(matches));
    }
}

void Editor::findNext()
{
    auto query = search->text().trimmed();
    if (query.isEmpty())
    {
        return;
    }
    QList<Node *> matches;
    for (auto n : nodes)
    {
        if (n)
        {
            QString text = "block " + QString::number(n->block);
            for (auto &c : n->data().commands)
            {
                text += " " + catalog.commandLabel(mission(), c);
            }
            for (auto &e : n->data().events)
            {
                text += " " + catalog.eventLabel(mission(), e);
            }
            if (text.contains(query, Qt::CaseInsensitive) || query == QString::number(n->block))
            {
                matches.append(n);
            }
        }
    }
    if (!matches.isEmpty())
    {
        int current = -1;
        for (int i = 0; i < matches.size(); ++i)
        {
            if (matches[i]->isSelected())
            {
                current = i;
            }
        }
        auto next = matches[(current + 1) % matches.size()];
        scene->clearSelection();
        next->setSelected(true);
        if (view->transform().m11() < .5)
        {
            view->resetTransform();
        }
        view->centerOn(next);
        return;
    }
    statusBar()->showMessage("No matching block in this chain.");
}

} // namespace bb
