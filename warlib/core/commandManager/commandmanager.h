#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

#include <QObject>

#include "core/messagequeue.h"
#include "game/game.h"
#include "core/network/networkinterface.h"
#include "Utilities/RandomIdGenerator/idgenerator.h"

enum CommandType{
    SERVER_INFO_REQUEST,
    SERVER_INFO,
    GLOBAL_UPDATE_REQUEST,
    GLOBAL_UPDATE,
    PLAYER_LIST_UPDATE,
    CHAT_MESSAGE,
    NEW_RULER,
    RULER_POSITION_CHANGE,
    RULER_REMOVE,
    NEW_ROUND_TEMPLATE,
    ROUND_TEMPLATE_POSITION_CHANGE,
    ROUND_TEMPLATE_REMOVE,
    NEW_REGIMENT,
    REGIMENT_MOVE,
    REGIMENT_REMOVE_DEADS,
    REGIMENT_WIDTH_CHANGE,
    REGIMENT_REMOVE
};

class CommandManager : public QObject
{
    Q_OBJECT
public:
    explicit CommandManager(MessageQueue* iq, MessageQueue* oq, Game* g, QObject *parent = 0);

signals:
    void newChatMessageAvailable(QString sender,QString msg);
    void refreshPlayerList(QList<Player> l);
    void createRuler(QString id, int l);
    void moveRuler(QString id, QPointF p, QTransform a);
    void removeRuler(QString id);
    void createRoundTemplate(QString id, int d);
    void moveTemplate(QString id, QPointF p);
    void removeTemplate(QString);
    void createRegiment(QString, QString, RegimentAbstract);
    void moveRegiment(QString, QPointF, QTransform);
    void removeRegiment(QString);
    void removeDeads(QString, int);
    void changeRegimentWidth(QString, int);
    
public slots:
    void processIncomingMessage();
    void enQueueChatMessage(QString message);
    void enQueueServerInfoRequest();
    void enQueuePlayerListRefreshMessage(QList<Player> l);
    void enQueueCreateRulerMessage(int l);
    void enQueueRulerMoveMessage(QString i, QPointF p, QTransform matrix);
    void enqueueCreateRoundTemplateMessage(int d);
    void enQueueTemplateMoveMessage(QString id, QPointF p);
    void enQueueRemoveRulerMessage(QString i);
    void enQueueRemoveTemplateMessage(QString i);
    void enqueueNewRegimentMessage(QString o, RegimentAbstract r);
    void enqueueRegimentMoveMessage(QString i, QPointF p, QTransform matrix);
    void enqueueRemoveRegimentMessage(QString i);
    void enqueueRemoveDeadsMessage(QString i, int n);
    void enqueueChangeWidthMessage(QString i, int w);

private:
    static const QString LOG_ID_INFO;
    static const QString LOG_ID_TRACE;
    static const QString LOG_ID_WARN;
    static const QString LOG_ID_ERR;

    MessageQueue* outQueue;
    MessageQueue* inQueue;
    Game* game;
    //QMap<int, RegimentGraphics>* regimentMap;


    void addMessageToOutQueue(const Message &m);
    void addMessageToInQueue(const Message &m);
    void handleServerInfoRequest(MessageDestination dest, QString sender);
    void handleServerInfo(QByteArray &data);
    void handleNewChatMessage(const Message& m, QDataStream& data);
    void handlePlayerListRefreshMessage(const Message &m, QDataStream &data);
    void handleCreateRulerMessage(const Message &m, QDataStream &data);
    void handleRulerMoveMessage(const Message &m, QDataStream &data);
    void handleCreateRoundTemplateMessage(const Message &m, QDataStream& data);
    void handleTemplateMoveMessage(const Message &m, QDataStream &data);
    void handleRemoveRulerMessage(const Message &m, QDataStream &data);
    void handleRemoveTemplateMessage(const Message &m, QDataStream &data);
    void handleNewRegimentMessage(const Message &m, QDataStream &data);
    void handleRegimentMoveMessage(const Message &m, QDataStream &data);
    void handleRemoveRegimentMessage(const Message &m, QDataStream &data);
    void handleRemoveDeadsRegimentMessage(const Message &m, QDataStream &data);
    void handleChangeWidthRegimentMessage(const Message &m, QDataStream &data);
};

#endif // COMMANDMANAGER_H