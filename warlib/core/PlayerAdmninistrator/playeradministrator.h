#ifndef PLAYERADMINISTRATOR_H
#define PLAYERADMINISTRATOR_H

#include <QObject>
#include "game/player.h"
#include "core/network/client.h"

class PlayerAdministrator : public QObject
{
    Q_OBJECT
public:
    explicit PlayerAdministrator(QObject *parent = 0);

    QList<Player> getPlayerList() const;
    void authorizePlayer(const Player& p);

    bool isNameTaken(QString name);
    void replaceName(const Player &p);
signals:
    void playerListChanged(QList<Player> l);
    void playerNameToChange(QString p, QString p2);

public slots:
    void handleNewPlayerConnection(Client c);
    void handlePlayerDisconnection(Client c);
    void setPlayerList(const QList<Player> &value);

private:
    QList<Player> playerList;

    static const QString LOG_ID_INFO;
    static const QString LOG_ID_TRACE;
    static const QString LOG_ID_WARN;
    static const QString LOG_ID_ERR;

};

#endif // PLAYERADMINISTRATOR_H
