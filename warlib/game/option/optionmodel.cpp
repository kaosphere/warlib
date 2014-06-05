#include "optionmodel.h"

OptionModel::OptionModel()
{
}

OptionModel::OptionModel(const QString &n, const int &pts, const bool &act, const QString &specRules, const bool& ro)
{
    name = n;
    nbPoints = pts;
    activated = act;
    specialRules = specRules;
    regimentOptions = ro;
}

OptionModel::OptionModel(const OptionModel &obj) : SerializableObject()
{
    name = obj.name;
    nbPoints = obj.nbPoints;
    activated = obj.activated;
    specialRules = obj.specialRules;
    regimentOptions = obj.regimentOptions;
}

OptionModel::~OptionModel()
{
}

bool OptionModel::operator ==(const OptionModel &o)
{
    if(name == o.name &&
       nbPoints == o.nbPoints &&
       specialRules == o.specialRules &&
       activated == o.activated &&
       regimentOptions == o.regimentOptions)
        return true;
    else return false;
}

OptionModel &OptionModel::operator =(const OptionModel & obj)
{
    name = obj.name;
    nbPoints = obj.nbPoints;
    activated = obj.activated;
    specialRules = obj.specialRules;
    regimentOptions = obj.regimentOptions;

    return *this;
}

QString OptionModel::displayString()
{
    QString s;
    QTextStream info(&s);
    info << name << endl;
    info << "Points :                   " << nbPoints << endl;
    info << "Rules :                    " << specialRules << endl;
    info << "Selected :                 " << activated << endl;
    info << "Regiment options :         " << regimentOptions <<endl;
    return s;
}

QString OptionModel::getHtml()
{
    QString html;
    html += QString("%1 (%3 pts)")
            .arg(name)
            .arg(QString::number(nbPoints));
    return html;
}

QString OptionModel::getName() const
{
    return name;
}

void OptionModel::setName(const QString &value)
{
    name = value;
}

bool OptionModel::isActivated() const
{
    return activated;
}

void OptionModel::setActivated(bool value)
{
    activated = value;
}

int OptionModel::getNbPoints() const
{
    return nbPoints;
}

void OptionModel::setNbPoints(int value)
{
    nbPoints = value;
}

QString OptionModel::getSpecialRules() const
{
    return specialRules;
}

void OptionModel::setSpecialRules(const QString &value)
{
    specialRules = value;
}

bool OptionModel::isRegimentOptions() const
{
    return regimentOptions;
}

void OptionModel::setRegimentOptions(bool value)
{
    regimentOptions = value;
}

void OptionModel::initOptionModelMetaType()
{
    qRegisterMetaTypeStreamOperators<OptionModel>("OptionModel");
    qRegisterMetaTypeStreamOperators<QList<OptionModel*> >("QList<OptionModel*>");
    qMetaTypeId<OptionModel>();
}

QDataStream &operator<<(QDataStream &ds, const QList<OptionModel*> &obj)
{
    ds << obj.size();
    for(int i = 0 ; i<obj.size(); i++)
    {
        ds << *obj[i];
    }
    return ds;
}

QDataStream &operator>>(QDataStream &ds, QList<OptionModel*> &obj)
{
    int size = 0;
    ds >> size;
    for(int i = 0 ; i<size; i++)
    {
        OptionModel* o = new OptionModel();
        ds >> *o;
        obj.append(o);
    }
    return ds;
}

