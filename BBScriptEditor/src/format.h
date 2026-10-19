#pragma once
#include <QtCore>
#include <array>
#include <optional>
#include <variant>
#include <vector>

namespace bb
{
constexpr int ChainCount = 5;
constexpr int BlockCount = 32;
constexpr int BackgroundBlock = 31;
// Exact disk layouts. These records document the file, not host pointers.
// Unidentified members are intentionally reserved; their bytes are preserved.
#pragma pack(push, 1)

struct MapHeaderDisk
{
    char signature[8];
    char title[64];
    quint8 width;
    quint8 height;
};

struct ObjectArrayDisk
{
    quint32 listHead;
    quint32 savedBase;
    qint32 slotCount;
};

struct MapObjectDisk
{
    quint32 inUse;
    quint32 nextPointer;
    quint32 previousPointer;
    quint32 targetPointer;
    quint32 linkedObjectPointer;
    quint32 workObjectPointer;
    quint32 goingToPointer;
    quint32 homePointer;
    quint32 occupantPointer;
    quint32 attackTargetPointer;
    quint32 insideBuildingPointer;
    quint32 reachedObjectPointer;
    quint32 spousePointer;
    quint32 actionTargetPointer;
    quint32 stockPointer;
    char name[28]; // Flagposts store a saved village-name pointer in this union.
    quint32 spritePointer;
    qint32 queuedSound;
    quint8 soundDelay;
    quint8 reservedAfterSoundDelay;
    // World coordinates use 16.16 fixed point.
    qint32 positionX;
    qint32 positionY;
    qint32 positionZ;
    qint32 velocityX;
    qint32 velocityY;
    qint32 velocityZ;
    qint32 targetVelocityX;
    qint32 targetVelocityY;
    qint32 objectHeight;
    qint32 sortDepth;
    qint32 speedFactor;
    qint32 slotIndex;
    quint8 attackPlayer;
    quint8 attackClass;
    quint8 attackUnitType;
    quint8 reservedAfterAttackFilter;
    qint32 wealth;
    quint16 carriedValue;
    quint32 flags;
    qint16 health;
    qint16 maximumHealth;
    qint16 previousHealth;
    std::array<qint16, 3> previousRectLeft;
    std::array<qint16, 3> previousRectTop;
    std::array<qint16, 3> previousRectRight;
    std::array<qint16, 3> previousRectBottom;
    qint16 screenLeft;
    qint16 screenTop;
    qint16 screenRight;
    qint16 screenBottom;
    qint16 clickLeft;
    qint16 clickTop;
    qint16 clickRight;
    qint16 clickBottom;
    quint8 age;
    quint8 reservedAfterAge;
    quint16 destinationFractionX;
    quint16 destinationFractionY;
    quint8 objectClass;
    quint8 terrainMask;
    quint8 pathX;
    quint8 pathY;
    quint8 tileX;
    quint8 tileY;
    quint8 tileZ;
    quint8 previousTileX;
    quint8 previousTileY;
    quint8 goalX;
    quint8 goalY;
    quint8 originalGoalX;
    quint8 originalGoalY;
    quint8 stuckTimer;
    quint8 repathCount;
    quint8 destinationX;
    quint8 destinationY;
    quint8 heading; // Generator period / house occupant count for other classes.
    quint8 generatorMaximum;
    quint8 generatorClass;
    quint8 animationTimer;
    quint8 damage;
    quint8 state;
    quint8 reservedBeforePath;
    quint32 pathPointer;
    quint8 pathLength;
    quint8 pathIndex;
    quint8 activity;
    quint8 attackStyle;
    quint8 unitType;
    quint8 timer;
    quint8 action;
    quint8 owner;
    quint8 playerColor;
    quint8 frame;
    quint8 thinkTimer;
    quint8 carriedResource;
    quint8 job;
    quint8 animationCounter;
    std::array<quint8, 2> reservedBeforeNeeds;
    quint8 food;
    quint8 water;
    quint8 soundCooldown;
    quint8 matingLock;
    quint8 speaking;
    quint8 effectTimer;
    quint8 fleeing;
    quint8 punishmentStage;
    quint8 birthTimer;
    quint8 intelligence;
    quint8 maximumIntelligence;
    quint8 speed;
    quint8 maximumSpeed;
    quint8 law;
    quint8 maximumLaw;
    quint8 faith;
    quint8 maximumFaith;
    quint8 happiness;
    quint8 maximumHappiness;
    quint8 fertility;
    quint8 matingCooldown;
    quint8 crime;
    quint8 crimeTimer;
    quint8 taxCooldown;
    quint8 attackerCount;
    quint8 reservedAfterAttackerCount;
    quint8 heldItemClass;
    quint8 fitness;
    quint8 damageTaken;
    quint8 going;
    quint8 disease;
    quint8 reservedBeforeDrawPosition;
    qint32 drawX;
    qint32 drawY;
    quint8 onScreen;
    quint8 redrawCount;
    quint8 attackRange;
    quint8 slowTick;
    quint8 visionRadius;
    quint8 selectedByMask;
    quint8 behavior;
    quint8 effectType;
    std::array<quint8, 8> reservedBeforeChat;
    quint8 chatCooldown;
    quint8 pathRetries;
};

struct TimedMessageDisk
{
    quint8 active;
    quint8 reserved;
    quint32 delayTicks;
    quint32 dataPointer;
    quint32 nextPointer;
    quint16 packetLength;
};

struct EventDisk
{
    quint8 type;
    quint8 reserved;
    qint32 first;
    qint32 second;
    qint32 third;
    quint8 destination;
    quint8 reservedDestination;
    qint32 enabled;
    quint32 reservedTail;
};

struct PacketHeaderDisk
{
    quint16 type;
    quint16 length;
    quint8 player;
};

struct BoxEntryDisk
{
    char name[256];
    char path[256];
    std::array<quint8, 16> timestamp;
    quint32 size;
};

struct PlayerDisk
{
    std::array<quint8, 1104> reservedBeforeOutcome;
    quint8 outcome;
    std::array<quint8, 2223> reservedTail;
};

struct MailDisk
{
    char text[1024];
    quint32 read;
    quint32 nextPointer;
};

struct ScriptGlobalsDisk
{
    quint8 technology;
    quint8 diseaseChance;
    quint8 reserved;
};

struct ScriptRetryDisk
{
    qint32 retry;
    qint32 endTimer;
};

struct CameraDisk
{
    qint32 gameTick;
    std::array<quint8, 44> viewState;
};

#pragma pack(pop)
static_assert(sizeof(MapHeaderDisk) == 74);
static_assert(sizeof(PacketHeaderDisk) == 5 && sizeof(ObjectArrayDisk) == 12);
static_assert(sizeof(MapObjectDisk) == 314);
static_assert(offsetof(MapObjectDisk, objectClass) == 212);
static_assert(offsetof(MapObjectDisk, pathPointer) == 236);
static_assert(offsetof(MapObjectDisk, going) == 285);
static_assert(sizeof(TimedMessageDisk) == 16 && sizeof(EventDisk) == 24);
static_assert(sizeof(PlayerDisk) == 3328 && sizeof(MailDisk) == 1032);
static_assert(sizeof(BoxEntryDisk) == 532 && sizeof(CameraDisk) == 48);

// Domain model: the UI accesses these members, never raw packet offsets.
struct Move
{
    quint8 x = 0;
    quint8 y = 0;
    quint8 reserved = 0;
    qint32 object = 0;
};

struct Destination
{
    quint8 x = 0;
    quint8 y = 0;
};

struct Target
{
    quint8 reserved = 0;
    qint32 object = 0;
};

struct Create
{
    quint8 objectClass = 0;
    quint8 x = 0;
    quint8 y = 0;
    quint8 elevation = 0;
};

struct Texture
{
    quint8 texture = 0;
    quint8 x = 0;
    quint8 y = 0;
};

struct Letter
{
    QByteArray text;
};

struct Selection
{
    std::vector<qint32> objects;
};

struct Speed
{
    quint8 speed = 0;
};

struct Terrain
{
    quint8 x = 0;
    quint8 y = 0;
    quint8 reserved = 0;
    qint32 raise = 0;
};

struct Demolish
{
    quint8 x = 0;
    quint8 y = 0;
};

struct Empty
{
};

struct Sync
{
    quint8 compare = 0;
    quint16 random = 0;
};

struct Rename
{
    quint8 reserved = 0;
    qint32 object = 0;
    QByteArray text;
};

struct Action
{
    quint8 reserved = 0;
    qint32 object = 0;
    quint8 action = 0;
};

struct Spell
{
    quint8 spell = 0;
    quint8 x = 0;
    quint8 y = 0;
};

struct Property
{
    quint8 reserved = 0;
    qint32 object = 0;
    quint8 property = 1;
    quint8 reservedValue = 0;
    qint32 value = 0;
};

struct Outcome
{
    quint8 outcome = 0;
};

struct Flag
{
    quint8 flag = 0;
    qint32 value = 0;
};

struct Gold
{
    quint8 player = 0;
    qint32 delta = 0;
};

struct Delete
{
    quint8 reserved = 0;
    qint32 object = 0;
};

struct Music
{
    quint8 reserved = 0;
    qint32 track = 0;
};

struct Sound
{
    quint8 reserved = 0;
    qint32 speech = 0;
    qint32 effect = 0;
    QByteArray sample = QByteArray(16, '\0');
    qint32 speaker = 0;
};

struct Unknown
{
    QByteArray bytes;
};

using Payload = std::variant<Move,
                             Destination,
                             Target,
                             Create,
                             Texture,
                             Letter,
                             Selection,
                             Speed,
                             Terrain,
                             Demolish,
                             Empty,
                             Sync,
                             Rename,
                             Action,
                             Spell,
                             Property,
                             Outcome,
                             Flag,
                             Gold,
                             Delete,
                             Music,
                             Sound,
                             Unknown>;

struct Command
{
    quint16 type = 13;
    quint8 player = 0;
    quint32 delay = 0;
    quint8 active = 1;
    Payload payload = Empty{};
    QByteArray trailing;
    QByteArray originalPacket; // Exact fallback for malformed/unknown packets; not UI state.
    bool malformed = false;
    TimedMessageDisk diskHeader{};
};

struct Event
{
    quint8 type = 1;
    std::array<qint32, 3> args{};
    std::optional<quint8> destination = 0;
    qint32 enabled = 1;
    EventDisk disk{};
    int target() const;
};

struct Block
{
    std::vector<Command> commands;
    std::vector<Event> events;
    quint32 cursor = 0;
    quint32 start = 0;
    QByteArray originalBytes, originalSemantic;
};

struct Chain
{
    std::array<Block, BlockCount> blocks;
    quint8 current = 0;
};

struct Object
{
    int slot = 0;
    quint8 objectClass = 0;
    quint8 x = 0;
    quint8 y = 0;
    quint8 owner = 0;
    quint8 unit = 0;
    quint8 state = 0;
    quint8 activity = 0;
};

struct Mission
{
    QString name;
    QString path;
    QString title;
    int version = 0;
    quint32 tick = 0;
    quint8 tech = 0;
    std::array<quint8, ChainCount> outcomes{};
    std::array<Chain, ChainCount> chains;
    std::vector<Object> objects;
    QByteArray source;
    qsizetype scriptStart = 0;
    qsizetype scriptChainsEnd = 0;
    qsizetype scriptEnd = 0;
    static Mission parse(const QByteArray &bytes, QString name = {});
    QByteArray serialize() const;
    QByteArray semantic() const;
    const Object *object(int slot) const;
    void save(const QString &filename);
};

QByteArray readFile(const QString &path);
QMap<QString, QByteArray> readBox(const QByteArray &bytes);
QByteArray encodePacket(const Command &command);
Command decodePacket(const QByteArray &bytes);
Command newCommand(quint16 type, quint8 player = 0);
QByteArray blockSemantic(const Block &block);
std::vector<int> unusedBlocks(const Chain &chain);
} // namespace bb
