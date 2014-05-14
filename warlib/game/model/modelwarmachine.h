#ifndef MODELWARMACHINE_H
#define MODELWARMACHINE_H

#include <QObject>
#include <QtCore>
#include <QtWidgets>

#include "modelabstract.h"
#include "modelinfantery.h"

class ModelWarMachine : public ModelAbstract
{

public:
    ModelWarMachine();

    ModelWarMachine(const QString &n, const QString &move, const QString &weaponS, const QString &balisticS,
                    const QString &strength, const QString &toughness, const QString &wounds,
                    const QString &init, const QString &attacks, const QString &leadership,
                    const QString &save, const QString &invSave, const int points, const int &widthBase,
                    const int &lengthBase, const int &unitP, const QString& urlImage , bool figSup,
                    const QString& specRules, const ModelType &t);
    ModelWarMachine(const ModelWarMachine &copy);

    virtual ~ModelWarMachine();

    static void initModelWarMachine();
    virtual ModelWarMachine* setFromFile(QString path);
    virtual ModelWarMachine* setFromUI(const ParamsfromUImodel *params);
    virtual void load(QString path);
    virtual void save(QString path);

    //! SerializeOut
    /*!
     * VIRTUAL : Method to serialize unknown modelabstract pointer.
     */
    virtual QDataStream &serializeOut(QDataStream &out);

    //! SerializeIn
    /*!
     * VIRTUAL : Method to serialize unknown modelabstract pointer.
     * \param in QDataStream from which the data is read to feed the object.
     */
    virtual QDataStream &serializeIn(QDataStream& in);
    
    //! clone
    /*!
    * VIRTUAL : Method that returns a copy of the object. This is used to copy a pointer
    * to a derived class.
    */
    virtual ModelAbstract* clone();

    virtual QString displayStringInfo();
    virtual QString getHtml();

    virtual int computePoints();

    QString getSpecialRules() const;
    void setSpecialRules(const QString &value);

    ModelType getType() const;
    void setType(const ModelType &value);

    QList<StatsModel> getCrew() const;
    void setCrew(const QList<StatsModel> &value);
    void addCrew(StatsModel c);
    void clearCrew();

private:
    QString specialRules;
    ModelType type;

    //TODO : remove this crew shit
    QList<StatsModel> crew;

    friend QDataStream & operator << (QDataStream &, const ModelWarMachine &);
    friend QDataStream & operator >> (QDataStream &, ModelWarMachine &);
};

Q_DECLARE_METATYPE(ModelWarMachine)

#endif // MODELWARMACHINE_H