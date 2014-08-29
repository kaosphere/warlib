#ifndef TEST_H
#define TEST_H

#include "modelabstract.h"
#include <QtCore>

class test : public ModelAbstract
{
    Q_OBJECT
    Q_PROPERTY(int value READ getValue WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(OptionModel* opt READ getOpt WRITE setOpt NOTIFY optChanged)

public:
    test();
    test(const QString &n, const QString &move, const QString &weaponS,
         const QString &balisticS, const QString &strength, const QString &toughness,
         const QString &wounds, const QString &init, const QString &attacks,
         const QString &leadership, const QString &save, const QString &invSave,
         const int points, const int &widthBase, const int &lengthBase, const int &unitP,
         const QString &url, int val, QString na);

    QString getName() const;
    void setName(const QString &value);

    int getValue() const;
    void setValue(int v);

    virtual QString displayStringInfo();

    virtual void save(QString);
    virtual ModelAbstract* setFromFile(const QString path);
    virtual ModelAbstract* setFromUI(const ParamsfromUImodel *params);
    virtual void load(QString);
    virtual QString getHtml();
    virtual ModelAbstract* clone();
    virtual int computePoints();

    OptionModel* getOpt() const;
    void setOpt(OptionModel *value);

    static void initTestMetatype();

signals:
    void valueChanged();
    void nameChanged();
    void optChanged();

private:
    int value;
    QString name;
    OptionModel* opt;
};

Q_DECLARE_METATYPE(test)
Q_DECLARE_METATYPE(test*)

#endif // TEST_H
