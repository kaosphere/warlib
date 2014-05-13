#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QtCore>

#include "player.h"
#include "historic/historic.h"

//! Game
/*!
* Game class. Main class that contains every variables of the game.
* If the Game object is saved, it can be loaded with every information
* needed to restart a game where it was paused. Game inherits QObject
* because have to emit signal in case of changes. The class contains mainly
* the list of Players, with each Player containing its own Army. The game
* also contains the historic list which is the list of all exchanges
* between players during the game (connexions, disconnexions, chats,
* dice launches, ...).
*/
class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = 0);
    
    QString getName() const;
    void setName(const QString &value);

    QString getInformation() const;
    void setInformation(const QString &value);

    QList<Player*> getPlayers() const;
    void setPlayers(const QList<Player*> &value);
    void addPlayer(Player *p);
    void removePlayer(Player *p);

    int getPlayerNumber() const;
    void setPlayerNumber(int value);

    bool getSpectators() const;
    void setSpectators(bool value);

    Historic getHistoric() const;
    void setHistoric(const Historic &value);

signals:
    
public slots:

private:
    //! name
    /*!
    * Name of the game
    */
    QString name;

    //! information
    /*!
    * Information about the game.
    */
    QString information;

    //! players
    /*!
    * List of players that play in the game
    */
    QList<Player*> players; // Player* ?

    //! playerNumber
    /*!
    * Number of players maximum that can play the game
    */
    int playerNumber;
    
    //! spectators
    /*!
    * Does the game authorizes spectators? True if yes, false otherwize.
    */
    bool spectators;

    //! name
    /*!
    * Historic of the events of the whole game. For more info on Historic
    * @see Historic documentation.
    */
    Historic historic;
};

#endif // GAME_H
