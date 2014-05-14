#ifndef Army_H
#define Army_H

#include "game/regiment/regimentabstract.h"
#include <QtCore>
#include <QString>
#include <QList>

class Army : public QObject
{
    Q_OBJECT

public:
    Army(QObject *parent = 0);

    virtual ~Army();

	static void initArmySystem();

    QString getName() const;
    void setName(const QString &value);

    QList<RegimentAbstract> &getUnits();
    void setUnits(const QList<RegimentAbstract> &value);
    void addUnit(const RegimentAbstract& u);
    void removeUnit(const RegimentAbstract& u);
    
    void save(const QString& path);
    void load(const QString& path);

    unsigned int getPoints() const;
    void setPoints(unsigned int value);

    friend QDataStream & operator << (QDataStream &, const Army &);
    friend QDataStream & operator >> (QDataStream &, Army &);

    friend QDataStream & operator << (QDataStream &, Army *);
    friend QDataStream & operator >> (QDataStream &, Army *);

    bool operator==(const Army& obj);
    Army &operator=(const Army&);
    
    QString displayInfo() const;
    QString displayShortInfo() const;

    QString getHtml();

    int computePoints();

private:
    QString name;
    QList<RegimentAbstract> units;
};

Q_DECLARE_METATYPE(Army*)

namespace QtMetaTypePrivate {
template <>
struct QMetaTypeFunctionHelper<Army, true> {
    static void Delete(void *t)
    {
        delete static_cast<Army*>(t);
    }

    static void *Create(const void *t)
    {
        Q_UNUSED(t)
        return new Army();
    }

    static void Destruct(void *t)
    {
        Q_UNUSED(t) // Silence MSVC that warns for POD types.
        static_cast<Army*>(t)->~Army();
    }

    static void *Construct(void *where, const void *t)
    {
        Q_UNUSED(t)
        return new (where) Army;
    }
#ifndef QT_NO_DATASTREAM
    static void Save(QDataStream &stream, const void *t)
    {
        stream << *static_cast<const Army*>(t);
    }

    static void Load(QDataStream &stream, void *t)
    {
        stream >> *static_cast<Army*>(t);
    }
#endif // QT_NO_DATASTREAM
};

}


#endif // Army_H
