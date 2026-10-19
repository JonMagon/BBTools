#pragma once
#include "catalog.h"
#include <QtWidgets>
#include <memory>

namespace bb
{
class Editor;
class Node;

struct Edge
{
    Node *source = nullptr;
    Node *target = nullptr;
    int event = 0;
    QGraphicsPathItem *line = nullptr;
    QGraphicsPathItem *arrow = nullptr;
    QGraphicsEllipseItem *port = nullptr;
    QGraphicsSimpleTextItem *stub = nullptr;
    bool selected = false;
    bool hovered = false;
    QPointF output() const;
    void update();
};

QPainterPath connectionPath(QPointF a, QPointF b, bool loop = false);

class Choice : public QComboBox
{
    Q_OBJECT
public:
    qint64 committed;
    qint64 low;
    qint64 high;
    bool fixed;
    Choice(const Choices &choices,
           qint64 initialValue,
           qint64 minimumValue,
           qint64 maximumValue,
           bool fixedChoices,
           QWidget *parent = nullptr);
    bool commit();
signals:
    void chosen(qint64 value);

protected:
    void wheelEvent(QWheelEvent *event) override;
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    void filter(const QString &query);
    void sync();
};

class Node : public QGraphicsRectItem
{
public:
    Editor *owner;
    int chainId;
    int block;
    int layoutRow = 0;
    QWidget *panel = nullptr;
    QVBoxLayout *layout = nullptr;
    QGraphicsProxyWidget *proxy = nullptr;
    QGraphicsSimpleTextItem *title = nullptr;
    QGraphicsEllipseItem *input = nullptr;
    std::vector<QPushButton *> commandRows;
    std::vector<QPushButton *> eventRows;
    QWidget *form = nullptr;
    QLabel *summary = nullptr;
    int kind = -1;
    int index = -1;
    bool ready = false;
    bool resizing = false;
    Node(Editor *editor, int chain, int block);
    Block &data() const;
    void populate();
    void openRecord(int kind, int index);
    void buildForm();
    void closeForm();
    void resizeCard();
    void refreshLabels();
    QPointF eventPort(int eventIndex) const;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

struct Snapshot
{
    std::array<Chain, ChainCount> chains;
    QMap<int, QPointF> positions;
    QMap<int, QPair<int, int>> editors;
    int chainChoice = 0;
};

struct HistoryEntry
{
    Snapshot before;
    Snapshot after;
    QString name;
};

struct Document
{
    Mission mission;
    QByteArray savedSemantic;
    QMap<int, QPointF> positions;
    std::vector<HistoryEntry> past;
    std::vector<HistoryEntry> future;
    bool dirty() const;
};

class GraphView : public QGraphicsView
{
public:
    Editor *owner;
    Edge *dragging = nullptr;
    QGraphicsPathItem *preview = nullptr;
    Node *moving = nullptr;
    bool panning = false;
    bool moved = false;
    QPoint pressPoint;
    QPoint lastPoint;
    QPointF nodeOrigin;
    std::optional<Snapshot> beforeDrag;
    GraphView(Editor *editor, QGraphicsScene *scene);
    Node *nodeAt(QPoint point) const;
    Edge *edgeAt(QPoint point) const;
    Edge *outputAt(QPoint point) const;
    bool interactiveAt(QPoint point) const;
    bool popupOpen() const;
    void cancelConnection();
    void hover(Edge *edge);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void contextMenuEvent(QContextMenuEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void keyPressEvent(QKeyEvent *event) override;
    void leaveEvent(QEvent *event) override;
};

class Editor : public QMainWindow
{
    Q_OBJECT
public:
    Catalog catalog;
    std::vector<std::unique_ptr<Document>> documents;
    QGraphicsScene *scene;
    GraphView *view;
    std::array<Node *, ChainCount * BlockCount> nodes{};
    std::vector<std::unique_ptr<Edge>> edges;
    QComboBox *missionBox;
    QComboBox *chainBox;
    QCheckBox *allBlocks;
    QLineEdit *search;
    QAction *undoAction;
    QAction *redoAction;
    QDockWidget *checks = nullptr;
    QTreeWidget *issueList = nullptr;
    int documentIndex = 0;
    int chainIndex = 0;
    int layoutGeneration = 0;
    bool rebuilding = false;
    bool closing = false;
    bool formPending = false;
    Edge *selectedEdge = nullptr;
    Edge *hoverEdge = nullptr;
    Edge *menuEdge = nullptr;
    std::unique_ptr<QSettings> preferences;
    Editor(bool restoreSettings = true, const QString &gameDirectory = {});
    void setGameDirectory(const QString &directory, bool loadMissions = true);
    void chooseGameDirectory();
    ~Editor() override;
    Document &document() const;
    Mission &mission() const;
    Chain &chain() const;
    void loadCampaign(const QString &archive = {});
    void openFile(const QString &path);
    void rebuild(bool center = false);
    void relink();
    void updateEdges();
    void makeRoom(Node *expanded);
    void remember(Node *node);
    Snapshot snapshot() const;
    void record(const Snapshot &before, QString actionName);
    void edit(QString actionName, const std::function<void()> &action, bool rebuild = false);
    void queueRebuild();
    void queueForm(Node *);
    void changed();
    void history(bool redo);
    void selectEdge(Edge *edge);
    void blockMenu(Node *node, QPoint screenPosition);
    void connectionMenu(Edge *edge, QPoint screenPosition);
    void connectEvent(int block, int event, int destination, int sourceChain = -1);
    void newConnection(int block, int event, QPointF position, QPoint screen, int sourceChain = -1);
    void autoLayout();
    void fit();
    void focusStart();
    bool save(bool saveAs = false);
    bool commitInputs();
    void showChecks();
    void showAbout();
    void refreshChecks();
    void navigateIssue(QTreeWidgetItem *item);
    void findNext();
    void highlightSearch();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    void updateTitle();
    void restorePreferences();
    void writePreferences();
};
} // namespace bb
