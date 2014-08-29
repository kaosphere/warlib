#ifndef OPTIONMODEL_H
#define OPTIONMODEL_H

#include <QObject>
#include <QtCore>
#include <QtWidgets>

#include "defines.h"
#include "core/serializableobject.h"

class OptionModel : public SerializableObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int nbPoints READ getNbPoints WRITE setNbPoints NOTIFY nbPointsChanged)
    Q_PROPERTY(bool activated READ isActivated WRITE setActivated NOTIFY activatedChanged)
    Q_PROPERTY(QString specialRules READ getSpecialRules WRITE setSpecialRules NOTIFY specialRulesChanged)
    Q_PROPERTY(bool regimentOptions READ isRegimentOptions WRITE setRegimentOptions NOTIFY regimentOptionsChanged)

public:
    explicit OptionModel();

    OptionModel(const QString &n, const int& pts, const bool& act, const QString& specRules, const bool &ro);

    OptionModel(const OptionModel & obj);

    virtual ~OptionModel();

    bool operator==(const OptionModel&);
    OptionModel& operator=(const OptionModel&);
    
    QString displayString();
    
    QString getHtml();

    QString getName() const;
    void setName(const QString &value);

    int getNbPoints() const;
    void setNbPoints(int value);

    bool isActivated() const;
    void setActivated(bool value);

    QString getSpecialRules() const;
    void setSpecialRules(const QString &value);

    bool isRegimentOptions() const;
    void setRegimentOptions(bool value);

    //! initOptionModelMetaType
    /*!
    * Init metatype information of the class so that it can be
    * serialized by Qt property system.
    */
    static void initOptionModelMetaType();

protected:
    QString name;
    int nbPoints;
    bool activated;
    QString specialRules;
    bool regimentOptions;
    
signals:
    void nameChanged();
    void nbPointsChanged();
    void activatedChanged();
    void specialRulesChanged();
    void regimentOptionsChanged();
    
public slots:
    
};

//QDataStream &operator<<(QDataStream &ds, const QList<OptionModel*> &obj);
//QDataStream &operator>>(QDataStream &ds, QList<OptionModel*> &obj);

Q_DECLARE_METATYPE(OptionModel)
Q_DECLARE_METATYPE(OptionModel*)

#endif // OPTIONMODEL_H
