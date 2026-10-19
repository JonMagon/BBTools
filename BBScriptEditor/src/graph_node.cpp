#include "editor.h"
#include "editor_support.h"
#include <algorithm>
#include <cmath>
#include <limits>

namespace bb
{
using namespace detail;

Node::Node(Editor *editor, int chain, int id)
    : QGraphicsRectItem(0, 0, 390, 180), owner(editor), chainId(chain), block(id)
{
    setFlags(ItemIsMovable | ItemIsSelectable | ItemSendsGeometryChanges);
    setBrush(QColor(block == 31 ? "#3b3045" : "#24333e"));
    setPen(QPen(QColor(owner->mission().chains[chainId].current == block ? "#70dfb4" : "#607482"),
                owner->mission().chains[chainId].current == block ? 3 : 1));
    setCursor(Qt::ArrowCursor);
    title = new QGraphicsSimpleTextItem(
        QString("BLOCK %1").arg(block) + (block == 31 ? "  BACKGROUND" : "") +
            (owner->mission().chains[chainId].current == block ? "  • FILE CURRENT" : ""),
        this);
    title->setBrush(QColor("#b9f4df"));
    title->setPos(16, 12);
    title->setAcceptedMouseButtons(Qt::NoButton);
    input = new QGraphicsEllipseItem(-5, 17, 10, 10, this);
    input->setZValue(4);
    input->setBrush(QColor("#24333e"));
    input->setPen(QPen(QColor("#9db1c2"), 1.5));
    input->setAcceptedMouseButtons(Qt::NoButton);
    panel = new QWidget;
    panel->setFixedWidth(370);
    panel->setStyleSheet(nodeStyleSheet());
    layout = new QVBoxLayout(panel);
    layout->setContentsMargins(8, 5, 8, 8);
    layout->setSpacing(6);
    proxy = new QGraphicsProxyWidget(this);
    proxy->setWidget(panel);
    proxy->setPos(10, 40);
    QObject::connect(proxy,
                     &QGraphicsProxyWidget::geometryChanged,
                     proxy,
                     [this]
                     {
                         if (ready && !resizing)
                         {
                             resizeCard();
                         }
                     });
    populate();
    ready = true;
}

Block &Node::data() const
{
    return owner->mission().chains[chainId].blocks[block];
}

void Node::populate()
{
    for (int k = 0; k < 2; ++k)
    {
        auto header = new QHBoxLayout;
        auto label = new QLabel(QString(k ? "CONDITIONS / TRANSITIONS  (%1)" : "COMMANDS  (%1)")
                                    .arg(k ? data().events.size() : data().commands.size()));
        label->setStyleSheet(k ? "color:#edbd83;font-weight:bold;"
                               : "color:#85c9e8;font-weight:bold;");
        header->addWidget(label);
        header->addStretch();
        auto add = new QPushButton("+");
        add->setFixedWidth(28);
        header->addWidget(add);
        layout->addLayout(header);
        QObject::connect(add,
                         &QPushButton::clicked,
                         owner,
                         [this, k]
                         {
                             int id = block;
                             owner->edit(
                                 k ? "Add condition" : "Add command",
                                 [&]
                                 {
                                     auto &b = owner->mission().chains[chainId].blocks[id];
                                     if (k)
                                     {
                                         Event e;
                                         e.destination.reset();
                                         b.events.push_back(e);
                                     }
                                     else
                                     {
                                         b.commands.push_back(newCommand(13, quint8(chainId)));
                                     }
                                 },
                                 true);
                         });
        auto rowsWidget = new QWidget;
        auto rowsLayout = new QVBoxLayout(rowsWidget);
        rowsLayout->setContentsMargins(0, 0, 0, 8);
        rowsLayout->setSpacing(5);
        layout->addWidget(rowsWidget);
        auto n = k ? data().events.size() : data().commands.size();
        if (!n)
        {
            auto empty = new QLabel(k ? "No conditional transitions" : "No commands");
            empty->setStyleSheet("color:#8fa3b1;padding:6px;");
            rowsLayout->addWidget(empty);
        }
        for (int i = 0; i < int(n); ++i)
        {
            auto row = new QPushButton;
            row->setCursor(Qt::ArrowCursor);
            row->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
            rowsLayout->addWidget(row);
            (k ? eventRows : commandRows).push_back(row);
            QObject::connect(row,
                             &QPushButton::clicked,
                             owner,
                             [this, k, i]
                             {
                                 openRecord(k, i);
                             });
        }
    }
    refreshLabels();
    resizeCard();
}

void Node::refreshLabels()
{
    for (int k = 0; k < 2; ++k)
    {
        auto &rows = k ? eventRows : commandRows;
        for (int i = 0; i < int(rows.size()); ++i)
        {
            QString label, prefix;
            if (k)
            {
                auto &e = data().events[i];
                prefix = QString("Event %1  →  %2").arg(i + 1).arg(eventDestinationLabel(e)) +
                         (e.enabled ? "" : " · DISABLED");
                label = owner->catalog.eventLabel(owner->mission(), e);
            }
            else
            {
                auto &c = data().commands[i];
                prefix = QString("Command %1  ·  +%2 ticks").arg(i + 1).arg(c.delay);
                label = owner->catalog.commandLabel(owner->mission(), c);
            }
            auto lines = wrapRecordText(label);
            bool active = (kind == k && index == i);
            rows[i]->setStyleSheet(QString("text-align:left;padding:8px;background:%1;")
                                       .arg(active ? "#3b5668"
                                            : k    ? "#322c38"
                                                   : "#1b2b36"));
            rows[i]->setText(prefix + "\n" + lines.join('\n'));
            rows[i]->setToolTip(label);
            rows[i]->ensurePolished();
        }
    }
    if (summary && index >= 0)
    {
        if (kind == 0)
        {
            auto &c = data().commands[index];
            summary->setText(owner->catalog.commandLabel(owner->mission(), c));
            summary->setToolTip(owner->catalog.explanation(owner->mission(), c));
        }
        else
        {
            auto &e = data().events[index];
            summary->setText(owner->catalog.eventLabel(owner->mission(), e));
            summary->setToolTip(owner->catalog.eventExplanation(e));
        }
    }
    resizeCard();
}

void Node::openRecord(int k, int i)
{
    kind = k;
    index = i;
    refreshLabels();
    owner->scene->clearSelection();
    setSelected(true);
    owner->queueForm(this);
}

void Node::closeForm()
{
    if (form)
    {
        auto old = form;
        form = nullptr;
        summary = nullptr;
        old->blockSignals(true);
        for (auto child : old->findChildren<QWidget *>())
        {
            child->blockSignals(true);
        }
        layout->removeWidget(old);
        old->hide();
        old->deleteLater();
    }
    kind = -1;
    index = -1;
    refreshLabels();
}

void Node::buildForm()
{
    int k = kind, i = index;
    if (form)
    {
        auto old = form;
        form = nullptr;
        summary = nullptr;
        for (auto child : old->findChildren<QWidget *>())
        {
            child->blockSignals(true);
        }
        layout->removeWidget(old);
        old->hide();
        old->deleteLater();
    }
    kind = k;
    index = i;
    if (index < 0 ||
        (kind == 0 ? index >= int(data().commands.size()) : index >= int(data().events.size())))
    {
        return;
    }
    form = new QWidget;
    auto outer = new QVBoxLayout(form);
    outer->setContentsMargins(0, 8, 0, 0);
    auto bar = new QHBoxLayout;
    bar->addWidget(
        new QLabel(QString(kind ? "EVENT %1 PROPERTIES" : "COMMAND %1 PROPERTIES").arg(index + 1)),
        1);
    auto remove = new QPushButton("Remove"), done = new QPushButton("Done");
    bar->addWidget(remove);
    bar->addWidget(done);
    outer->addLayout(bar);
    auto fields = new QFormLayout;
    fields->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
    outer->addLayout(fields);
    summary = new QLabel;
    summary->setWordWrap(true);
    summary->setMinimumWidth(340);
    outer->addWidget(summary);
    layout->addWidget(form);
    QObject::connect(done,
                     &QPushButton::clicked,
                     owner,
                     [this]
                     {
                         closeForm();
                     });
    QObject::connect(remove,
                     &QPushButton::clicked,
                     owner,
                     [this]
                     {
                         int b = block, k = kind, i = index;
                         owner->edit(
                             "Remove record",
                             [&]
                             {
                                 auto &data = owner->mission().chains[chainId].blocks[b];
                                 if (k)
                                 {
                                     data.events.erase(data.events.begin() + i);
                                 }
                                 else
                                 {
                                     data.commands.erase(data.commands.begin() + i);
                                 }
                             },
                             true);
                     });
    auto types = owner->catalog.choices(kind ? "events" : "commands");
    int type = kind ? data().events[index].type : data().commands[index].type;
    auto typeChoice = new Choice(types, type, 0, kind ? 255 : 65535, true);
    typeChoice->setObjectName("Type");
    fields->addRow("Type", typeChoice);
    QObject::connect(typeChoice,
                     &Choice::chosen,
                     owner,
                     [this](qint64 value)
                     {
                         owner->edit("Change record type",
                                     [&]
                                     {
                                         if (kind)
                                         {
                                             auto &e = data().events[index];
                                             e.type = quint8(value);
                                             e.args = {};
                                         }
                                         else
                                         {
                                             auto &c = data().commands[index];
                                             auto fresh = newCommand(quint16(value), c.player);
                                             fresh.delay = c.delay;
                                             fresh.active = c.active;
                                             c = fresh;
                                         }
                                     });
                         owner->queueForm(this);
                     });
    auto numeric = [&](QString name,
                       qint64 value,
                       qint64 low,
                       qint64 high,
                       Choices choices,
                       bool fixed,
                       std::function<void(qint64)> callback)
    {
        QWidget *widget = nullptr;
        if (!choices.isEmpty())
        {
            auto choice = new Choice(choices, value, low, high, fixed);
            if (name == "Texture")
            {
                choice->setIconSize(QSize(48, 24));
                for (int i = 0; i < choice->count(); ++i)
                {
                    choice->setItemIcon(
                        i, owner->catalog.textureIcons.value(choice->itemData(i).toInt()));
                }
            }
            QObject::connect(choice, &Choice::chosen, owner, callback);
            widget = choice;
        }
        else
        {
            widget = new IntegerEdit(value, low, high, callback);
        }
        widget->setObjectName(name);
        fields->addRow(name, widget);
    };
    if (kind == 0)
    {
        auto &c = data().commands[index];
        numeric("Delay ticks",
                c.delay,
                0,
                UINT32_MAX,
                {},
                false,
                [this](qint64 v)
                {
                    owner->edit("Command delay",
                                [&]
                                {
                                    data().commands[index].delay = quint32(v);
                                });
                });
        numeric("Packet player",
                c.player,
                0,
                4,
                playerChoices(),
                true,
                [this](qint64 v)
                {
                    owner->edit("Packet player",
                                [&]
                                {
                                    data().commands[index].player = quint8(v);
                                });
                });
        for (auto f : owner->catalog.fields(owner->mission(), c))
        {
            numeric(f.name,
                    f.value,
                    f.low,
                    f.high,
                    f.choices,
                    f.fixed,
                    [this, f](qint64 v)
                    {
                        owner->edit(f.name,
                                    [&]
                                    {
                                        f.set(data().commands[index], v);
                                    });
                        if (f.rebuild)
                        {
                            owner->queueForm(this);
                        }
                    });
        }
        auto textField = [&](QString label,
                             QByteArray bytes,
                             std::function<void(Command &, QByteArray)> setter,
                             int maxLength = 65000)
        {
            auto field = new QLineEdit(decodeNullTerminatedText(bytes));
            field->setMaxLength(maxLength);
            field->setObjectName("Text");
            fields->addRow(label, field);
            QObject::connect(field,
                             &QLineEdit::editingFinished,
                             owner,
                             [this, field, setter]
                             {
                                 if (field->text() != QString::fromLatin1(field->text().toLatin1()))
                                 {
                                     field->setProperty("invalid", true);
                                     field->setStyleSheet("border:1px solid #ef7777;");
                                     return;
                                 }
                                 field->setProperty("invalid", false);
                                 field->setStyleSheet("");
                                 owner->edit("Text",
                                             [&]
                                             {
                                                 setter(data().commands[index],
                                                        field->text().toLatin1());
                                             });
                             });
        };
        if (auto p = std::get_if<Letter>(&c.payload))
        {
            textField("Text / reference",
                      p->text,
                      [](Command &c, QByteArray b)
                      {
                          auto &p = std::get<Letter>(c.payload);
                          if (decodeNullTerminatedText(p.text) != decodeNullTerminatedText(b))
                          {
                              p.text = b + '\0';
                          }
                      });
        }
        if (auto p = std::get_if<Rename>(&c.payload))
        {
            textField("Village name",
                      p->text,
                      [](Command &c, QByteArray b)
                      {
                          auto &p = std::get<Rename>(c.payload);
                          if (decodeNullTerminatedText(p.text) != decodeNullTerminatedText(b))
                          {
                              p.text = b + '\0';
                          }
                      });
        }
        if (auto p = std::get_if<Sound>(&c.payload); p && p->speech)
        {
            textField(
                "Sample name",
                p->sample,
                [](Command &c, QByteArray b)
                {
                    auto &p = std::get<Sound>(c.payload);
                    if (decodeNullTerminatedText(p.sample) != decodeNullTerminatedText(b))
                    {
                        p.sample = (b + '\0').leftJustified(16, '\0', true);
                    }
                },
                15);
        }
        if (auto p = std::get_if<Selection>(&c.payload))
        {
            QStringList ids;
            for (auto id : p->objects)
            {
                ids << QString::number(id);
            }
            auto field = new QLineEdit(ids.join(", "));
            field->setObjectName("Selection");
            fields->addRow("Selected object slots", field);
            QObject::connect(
                field,
                &QLineEdit::editingFinished,
                owner,
                [this, field]
                {
                    std::vector<qint32> ids;
                    bool valid = true;
                    for (auto part : field->text().split(','))
                    {
                        if (part.trimmed().isEmpty())
                        {
                            continue;
                        }
                        bool ok = false;
                        auto id = part.trimmed().toInt(&ok, 0);
                        if (!ok || id < 0 || id >= 5000)
                        {
                            valid = false;
                        }
                        ids.push_back(id);
                    }
                    valid = valid && ids.size() <= 62;
                    field->setProperty("invalid", !valid);
                    field->setStyleSheet(valid ? "" : "border:1px solid #ef7777;");
                    if (valid)
                    {
                        owner->edit(
                            "Selection",
                            [&]
                            {
                                std::get<Selection>(data().commands[index].payload).objects = ids;
                                data().commands[index].trailing.clear();
                            });
                    }
                });
        }
    }
    else
    {
        auto &e = data().events[index];
        auto enabled = new QCheckBox;
        enabled->setChecked(e.enabled);
        fields->addRow("Enabled", enabled);
        QObject::connect(enabled,
                         &QCheckBox::toggled,
                         owner,
                         [this](bool v)
                         {
                             owner->edit("Event enabled",
                                         [&]
                                         {
                                             data().events[index].enabled = v;
                                         });
                         });
        auto names =
            owner->catalog.root["eventFields"].toObject()[QString::number(e.type)].toArray();
        if (names.isEmpty())
        {
            names = {"Argument 0", "Argument 1", "Argument 2"};
        }
        for (int a = 0; a < names.size(); ++a)
        {
            auto name = names[a].toString();
            Choices choices;
            bool fixed = false;
            if (name.contains("slot", Qt::CaseInsensitive))
            {
                choices = owner->catalog.objectChoices(owner->mission());
            }
            else if (name.contains("class", Qt::CaseInsensitive) || name.contains("held item"))
            {
                choices = owner->catalog.classes();
            }
            else if (name.contains("Player", Qt::CaseInsensitive))
            {
                choices = playerChoices();
                fixed = true;
            }
            else if (name == "Unit type")
            {
                choices = owner->catalog.unitChoices();
            }
            numeric(name,
                    e.args[a],
                    INT32_MIN,
                    INT32_MAX,
                    choices,
                    fixed,
                    [this, a](qint64 v)
                    {
                        owner->edit("Condition argument",
                                    [&]
                                    {
                                        data().events[index].args[a] = qint32(v);
                                    });
                    });
        }
    }
    refreshLabels();
    resizeCard();
}

void Node::resizeCard()
{
    if (resizing)
    {
        return;
    }
    resizing = true;
    auto height = rect().height();
    panel->ensurePolished();
    for (auto child : panel->findChildren<QWidget *>())
    {
        child->ensurePolished();
    }
    panel->layout()->invalidate();
    panel->layout()->activate();
    panel->adjustSize();
    panel->resize(370, panel->sizeHint().height());
    proxy->resize(panel->size());
    setRect(0, 0, 390, panel->height() + 52);
    resizing = false;
    if (ready && rect().height() > height + .5)
    {
        owner->makeRoom(this);
    }
    owner->updateEdges();
}

QPointF Node::eventPort(int i) const
{
    if (i < 0 || i >= int(eventRows.size()))
    {
        return mapToScene(QPointF(390, 80));
    }
    auto row = eventRows[i];
    auto point = row->mapTo(panel, QPoint(row->width(), row->height() / 2));
    return mapToScene(QPointF(390, 40 + point.y()));
}

QVariant Node::itemChange(GraphicsItemChange c, const QVariant &value)
{
    auto result = QGraphicsRectItem::itemChange(c, value);
    if (c == ItemSelectedHasChanged)
    {
        setZValue(value.toBool() ? 2 : 0);
    }
    if (c == ItemPositionHasChanged && ready)
    {
        owner->remember(this);
        owner->updateEdges();
    }
    return result;
}

void Node::paint(QPainter *p, const QStyleOptionGraphicsItem *o, QWidget *w)
{
    auto option = *o;
    option.state &= ~QStyle::State_Selected;
    QGraphicsRectItem::paint(p, &option, w);
    if (isSelected())
    {
        QPen pen(QColor("#b9d3e3"), 1, Qt::DashLine);
        p->setPen(pen);
        p->setBrush(Qt::NoBrush);
        p->drawRect(rect().adjusted(-2, -2, 2, 2));
    }
}

} // namespace bb
