#include "test.h"

test::test():ModelAbstract()
{
    value = 0;
    name = "";
    opt = new OptionModel();
}

test::test(const QString &n, const QString &move, const QString &weaponS,
           const QString &balisticS, const QString &strength, const QString &toughness,
           const QString &wounds, const QString &init, const QString &attacks,
           const QString &leadership, const QString &save, const QString &invSave, const int points, const int &widthBase,
           const int &lengthBase, const int &unitP, const QString& url, int val, QString na) :
           ModelAbstract(n, move, weaponS, balisticS,strength, toughness,wounds,init,
                         attacks,leadership, save, invSave,points,widthBase,lengthBase,unitP,url)
{
    value = val;
    name = na;
    opt = new OptionModel();
}

QString test::displayStringInfo()
{
    QString out;
    QTextStream s(&out);

    s << displayBaseInfo();
    s << "Test::Value : " << QString::number(value) << endl;
    s << "Test::name : " << name << endl;
    s << "Test::opt : " << opt->displayString() << endl;

    return out;
}

void test::save(QString)
{

}

ModelAbstract* test::setFromFile(const QString path)
{
    Q_UNUSED(path);
    return NULL;
}

ModelAbstract* test::setFromUI(const ParamsfromUImodel *params)
{
    Q_UNUSED(params);
    return NULL;
}

void test::load(QString)
{

}

QString test::getHtml()
{
    return NULL;
}

ModelAbstract *test::clone()
{
    return NULL;
}

int test::computePoints()
{
    return 0;
}

OptionModel *test::getOpt() const
{
    return opt;
}

void test::setOpt(OptionModel *value)
{
    opt = value;
}

void test::initTestMetatype()
{
    qRegisterMetaTypeStreamOperators<test>("test");
    qMetaTypeId<test>();
}

QString test::getName() const
{
    return name;
}

void test::setName(const QString &value)
{
    name = value;
}

int test::getValue() const
{
    return value;
}

void test::setValue(int v)
{
    value = v;
}


