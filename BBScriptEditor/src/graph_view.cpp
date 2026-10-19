#include "editor.h"
#include "editor_support.h"
#include <algorithm>
#include <cmath>
#include <limits>

namespace bb
{
using namespace detail;

QPainterPath connectionPath(QPointF a, QPointF b, bool loop)
{
    QPainterPath path(a);
    if (loop)
    {
        path.cubicTo(a + QPointF(100, -150), b + QPointF(-90, -150), b);
    }
    else if (b.x() - a.x() < 40)
    {
        auto start = a + QPointF(32, 0), end = b - QPointF(32, 0);
        auto bend = std::min(260., std::max(160., std::abs(b.y() - a.y()) * .3));
        path.lineTo(start);
        if (std::abs(b.y() - a.y()) < 40)
        {
            QPointF middle((start.x() + end.x()) * .5, std::max(a.y(), b.y()) + 100);
            path.cubicTo(start + QPointF(bend, 0), middle + QPointF(bend, 0), middle);
            path.cubicTo(middle - QPointF(bend, 0), end - QPointF(bend, 0), end);
        }
        else
        {
            path.cubicTo(start + QPointF(bend, 0), end - QPointF(bend, 0), end);
        }
        path.lineTo(b);
    }
    else
    {
        auto bend = std::min(160., std::max(75., std::abs(b.x() - a.x()) * .5));
        path.cubicTo(a + QPointF(bend, 0), b - QPointF(bend, 0), b);
    }
    return path;
}

QPointF Edge::output() const
{
    return source->eventPort(event);
}

void Edge::update()
{
    auto a = output(), b = target ? target->mapToScene(QPointF(0, 22)) : a + QPointF(60, 0);
    auto path = connectionPath(a, b, source == target);
    line->setPath(path);
    auto &e = source->data().events.at(event);
    QColor color = selected    ? QColor("#70efce")
                   : hovered   ? QColor("#c0dce8")
                   : !target   ? QColor("#edbd83")
                   : e.enabled ? QColor("#9db1c2")
                               : QColor("#59616a");
    QPen pen(color, selected ? 3.5 : hovered ? 2.5 : 1.7);
    if (!e.enabled || !target)
    {
        pen.setStyle(Qt::DashLine);
    }
    line->setPen(pen);
    QPainterPath arrowPath;
    if (target)
    {
        auto before = path.pointAtPercent(.99);
        auto d = b - before;
        auto angle = std::atan2(d.y(), d.x());
        QPointF u(std::cos(angle), std::sin(angle)), v(-u.y(), u.x());
        arrowPath.moveTo(b);
        arrowPath.lineTo(b - u * 11. + v * 5.);
        arrowPath.lineTo(b - u * 11. - v * 5.);
        arrowPath.closeSubpath();
    }
    arrow->setPath(arrowPath);
    arrow->setBrush(color);
    arrow->setPen(Qt::NoPen);
    port->setRect(a.x() - 4, a.y() - 4, 8, 8);
    port->setBrush(color);
    port->setPen(pen);
    stub->setText(target ? "" : "Drag to connect");
    stub->setBrush(color);
    stub->setPos(path.pointAtPercent(.5) + QPointF(4, 4));
}

GraphView::GraphView(Editor *e, QGraphicsScene *scene) : QGraphicsView(scene, e), owner(e)
{
    setRenderHint(QPainter::Antialiasing);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setTransformationAnchor(AnchorUnderMouse);
    setMouseTracking(true);
    setBackgroundBrush(QColor("#15212a"));
    setSceneRect(-20000, -20000, 40000, 40000);
    setCursor(Qt::OpenHandCursor);
}

Node *GraphView::nodeAt(QPoint p) const
{
    auto s = mapToScene(p);
    for (auto item : scene()->items(s))
    {
        for (auto parent = item; parent; parent = parent->parentItem())
        {
            if (auto node = dynamic_cast<Node *>(parent))
            {
                return node;
            }
        }
    }
    return nullptr;
}

bool GraphView::interactiveAt(QPoint p) const
{
    auto node = nodeAt(p);
    if (!node)
    {
        return false;
    }
    auto at = node->proxy->mapFromScene(mapToScene(p)).toPoint();
    auto widget = node->panel->childAt(at);
    for (auto child = widget; child && child != node->panel; child = child->parentWidget())
    {
        if (qobject_cast<QAbstractButton *>(child) || qobject_cast<QLineEdit *>(child) ||
            qobject_cast<QComboBox *>(child) || qobject_cast<QAbstractSlider *>(child) ||
            qobject_cast<QAbstractSpinBox *>(child))
        {
            return true;
        }
    }
    return false;
}

bool GraphView::popupOpen() const
{
    if (QApplication::activePopupWidget())
    {
        return true;
    }
    for (auto combo : owner->findChildren<QComboBox *>())
    {
        if (combo->view()->isVisible())
        {
            return true;
        }
    }
    for (auto node : owner->nodes)
    {
        if (node)
        {
            for (auto combo : node->panel->findChildren<QComboBox *>())
            {
                if (combo->view()->isVisible())
                {
                    return true;
                }
            }
        }
    }
    return false;
}

Edge *GraphView::edgeAt(QPoint p) const
{
    auto at = mapToScene(p);
    for (auto &edge : owner->edges)
    {
        if (!edge->target && edge->stub->sceneBoundingRect().contains(at))
        {
            return edge.get();
        }
    }
    if (nodeAt(p))
    {
        return nullptr;
    }
    QPainterPathStroker stroke;
    stroke.setWidth(14. / transform().m11());
    for (auto i = owner->edges.rbegin(); i != owner->edges.rend(); ++i)
    {
        if (stroke.createStroke((*i)->line->path()).contains(at))
        {
            return i->get();
        }
    }
    return nullptr;
}

Edge *GraphView::outputAt(QPoint p) const
{
    for (auto &e : owner->edges)
    {
        if ((mapFromScene(e->output()) - p).manhattanLength() < 12)
        {
            return e.get();
        }
    }
    auto e = edgeAt(p);
    return e && !e->target ? e : nullptr;
}

void GraphView::hover(Edge *e)
{
    if (owner->menuEdge)
    {
        e = owner->menuEdge;
    }
    if (owner->hoverEdge && owner->hoverEdge != e)
    {
        owner->hoverEdge->hovered = false;
        owner->hoverEdge->update();
    }
    owner->hoverEdge = e;
    if (e)
    {
        e->hovered = true;
        e->update();
    }
    viewport()->setCursor(e || nodeAt(viewport()->mapFromGlobal(QCursor::pos())) || popupOpen()
                              ? Qt::ArrowCursor
                              : Qt::OpenHandCursor);
}

void GraphView::cancelConnection()
{
    dragging = nullptr;
    if (preview)
    {
        scene()->removeItem(preview);
        delete preview;
        preview = nullptr;
    }
    hover(nullptr);
}

void GraphView::mousePressEvent(QMouseEvent *event)
{
    if (popupOpen())
    {
        viewport()->setCursor(Qt::ArrowCursor);
        QGraphicsView::mousePressEvent(event);
        return;
    }
    pressPoint = lastPoint = event->position().toPoint();
    moved = false;
    if (event->button() == Qt::RightButton && dragging)
    {
        cancelConnection();
        event->accept();
        return;
    }
    if (event->button() == Qt::LeftButton)
    {
        if (auto edge = outputAt(pressPoint))
        {
            owner->selectEdge(nullptr);
            dragging = edge;
            hover(nullptr);
            preview = scene()->addPath(connectionPath(edge->output(), mapToScene(pressPoint)),
                                       QPen(QColor("#70efce"), 2));
            preview->setZValue(5);
            event->accept();
            return;
        }
        if (!interactiveAt(pressPoint))
        {
            if (auto n = nodeAt(pressPoint))
            {
                moving = n;
                nodeOrigin = n->pos();
                beforeDrag = owner->snapshot();
                scene()->clearSelection();
                n->setSelected(true);
                event->accept();
                return;
            }
            panning = true;
            viewport()->setCursor(Qt::ClosedHandCursor);
            event->accept();
            return;
        }
    }
    if (event->button() == Qt::MiddleButton)
    {
        panning = true;
        viewport()->setCursor(Qt::ClosedHandCursor);
        event->accept();
        return;
    }
    QGraphicsView::mousePressEvent(event);
}

void GraphView::mouseMoveEvent(QMouseEvent *event)
{
    auto point = event->position().toPoint();
    if ((point - pressPoint).manhattanLength() >= QApplication::startDragDistance())
    {
        moved = true;
    }
    if (dragging)
    {
        preview->setPath(connectionPath(dragging->output(), mapToScene(point)));
        event->accept();
        return;
    }
    if (moving)
    {
        if (moved)
        {
            moving->setPos(nodeOrigin + mapToScene(point) - mapToScene(pressPoint));
        }
        event->accept();
        return;
    }
    if (panning)
    {
        if (moved)
        {
            auto delta = point - lastPoint;
            horizontalScrollBar()->setValue(horizontalScrollBar()->value() - delta.x());
            verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
        }
        lastPoint = point;
        event->accept();
        return;
    }
    hover(popupOpen() ? nullptr : edgeAt(point));
    QGraphicsView::mouseMoveEvent(event);
}

void GraphView::mouseReleaseEvent(QMouseEvent *event)
{
    auto point = event->position().toPoint();
    if (dragging && event->button() == Qt::LeftButton)
    {
        int b = dragging->source->block, i = dragging->event, ch = dragging->source->chainId;
        auto target = nodeAt(point);
        auto position = mapToScene(point);
        auto screen = event->globalPosition().toPoint();
        cancelConnection();
        if (target && target->chainId == ch)
        {
            owner->connectEvent(b, i, target->block, ch);
        }
        else if (!target && moved)
        {
            owner->newConnection(b, i, position, screen, ch);
        }
        event->accept();
        return;
    }
    if (moving)
    {
        if (beforeDrag && moved)
        {
            owner->record(*beforeDrag, "Move block");
        }
        moving = nullptr;
        beforeDrag.reset();
        if (!moved)
        {
            owner->selectEdge(nullptr);
        }
        event->accept();
        return;
    }
    if (panning)
    {
        panning = false;
        if (!moved && event->button() == Qt::LeftButton)
        {
            owner->selectEdge(edgeAt(point));
            if (!owner->selectedEdge)
            {
                scene()->clearSelection();
            }
        }
        hover(edgeAt(point));
        event->accept();
        return;
    }
    QGraphicsView::mouseReleaseEvent(event);
}

void GraphView::contextMenuEvent(QContextMenuEvent *event)
{
    if (dragging)
    {
        cancelConnection();
        event->accept();
        return;
    }
    if (!popupOpen())
    {
        if (auto edge = edgeAt(event->pos()))
        {
            if (!edge->selected && edge->target)
            {
                owner->connectionMenu(edge, event->globalPos());
            }
            event->accept();
            return;
        }
        if (auto node = nodeAt(event->pos()); node && !interactiveAt(event->pos()))
        {
            owner->blockMenu(node, event->globalPos());
            event->accept();
            return;
        }
    }
    QGraphicsView::contextMenuEvent(event);
}

void GraphView::drawBackground(QPainter *painter, const QRectF &rect)
{
    QGraphicsView::drawBackground(painter, rect);
    int step = transform().m11() > .45 ? 25 : 100;
    painter->setPen(QPen(QColor("#1e2c36"), 0));
    QList<QLineF> lines;
    double left = std::floor(rect.left() / step) * step, top = std::floor(rect.top() / step) * step;
    for (double x = left; x <= rect.right(); x += step)
    {
        lines.append(QLineF(x, rect.top(), x, rect.bottom()));
    }
    for (double y = top; y <= rect.bottom(); y += step)
    {
        lines.append(QLineF(rect.left(), y, rect.right(), y));
    }
    painter->drawLines(lines);
}

void GraphView::wheelEvent(QWheelEvent *event)
{
    if (popupOpen())
    {
        QGraphicsView::wheelEvent(event);
        return;
    }
    if (interactiveAt(event->position().toPoint()))
    {
        event->accept();
        return;
    }
    auto factor = std::pow(1.0015, event->angleDelta().y());
    auto zoom = transform().m11() * factor;
    if (zoom >= .15 && zoom <= 2.5)
    {
        scale(factor, factor);
    }
    event->accept();
}

void GraphView::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape && dragging)
    {
        cancelConnection();
        e->accept();
        return;
    }
    QGraphicsView::keyPressEvent(e);
}

void GraphView::leaveEvent(QEvent *e)
{
    if (!dragging)
    {
        hover(nullptr);
    }
    QGraphicsView::leaveEvent(e);
}

} // namespace bb
