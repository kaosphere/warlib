#include "modelwarmachine.h"

ModelWarMachine::ModelWarMachine(QObject* parent):
    ModelAbstract(parent)
{
}

ModelWarMachine::ModelWarMachine(const QString &n, const QString &move, const QString &weaponS,
                                 const QString &balisticS, const QString &strength, const QString &toughness,
                                 const QString &wounds, const QString &init, const QString &attacks,
                                 const QString &leadership, const QString &save, const QString &invSave, const int points,
                                 const int &widthBase, const int &lengthBase, const int &unitP, const QString &urlImage,
                                 bool figSup, const QString &specRules, const ModelType &t, QObject *parent) :
    ModelAbstract(n,move,weaponS,balisticS, strength, toughness, wounds, init, attacks, leadership, save,
        invSave, points, widthBase, lengthBase, unitP, urlImage, figSup, t, parent)
{
    specialRules = specRules;
}

ModelWarMachine::ModelWarMachine(const ModelWarMachine &copy) : ModelAbstract(copy)
{
    specialRules = copy.specialRules;
    crew = copy.crew;
}

ModelWarMachine::~ModelWarMachine()
{
}

void ModelWarMachine::initModelWarMachine()
{
    qRegisterMetaTypeStreamOperators<ModelWarMachine>("ModelWarMachine");
    qMetaTypeId<ModelWarMachine>();
}

ModelWarMachine *ModelWarMachine::setFromFile(QString path)
{
    ModelWarMachine* tmp = new ModelWarMachine(*this);
    tmp->load(path);

    return tmp;
}

QDataStream &ModelWarMachine::serializeOut(QDataStream& out)
{
    out << (*this);
    return out;
}

QDataStream & ModelWarMachine::serializeIn(QDataStream &in)
{
    in >> (*this);
    return in;
}

ModelAbstract *ModelWarMachine::clone()
{
    return new ModelWarMachine(*this);
}

ModelWarMachine *ModelWarMachine::setFromUI(const ParamsfromUImodel *params)
{
    ModelWarMachine* tmp = new ModelWarMachine(*this);

    // modelabstract params
    tmp->setStats(params->getStats());
    tmp->setSquareBaseW(params->getWidthBase());
    tmp->setSquareBaseL(params->getLengthBase());
    tmp->setUnitPower(params->getUnitP());
    tmp->setFigSupInd(params->getFigSup());
    tmp->setUrlImage(params->getUrlImage());
    tmp->setImage(params->getImage());
    tmp->setOptions(params->getOptions());

    // modelwarmachine params
    tmp->setSpecialRules(params->getSpecRules());
    tmp->setType(params->getType());
    tmp->setCrew(params->getMorC());

    return tmp;
}

void ModelWarMachine::load(QString path)
{
    ModelWarMachine temp;

    QSettings readFile(path, QSettings::IniFormat);
    temp = readFile.value("ModelWarMachine", qVariantFromValue(ModelWarMachine())).value<ModelWarMachine>();

    type = temp.getType();
    stats = temp.getStats();
    squareBaseW = temp.getSquareBaseW();
    squareBaseL = temp.getSquareBaseL();
    unitPower = temp.getUnitPower();

    urlImage = temp.getUrlImage();

    if(!temp.getImage().isNull())
    {
        image = temp.getImage();
    }

    figSupInd = temp.getFigSupInd();
    specialRules = temp.getSpecialRules();
    crew = temp.getCrew();

    options = temp.getOptions();
}

void ModelWarMachine::save(QString path)
{
    QFile::remove(path);
    QSettings savedFile(path, QSettings::IniFormat);
    savedFile.setValue("ModelWarMachine", qVariantFromValue(*this));
    savedFile.sync();
}

int ModelWarMachine::computePoints()
{
    //compute whole points of the model
    int points = computeBasePoints();
    QList<StatsModel>::Iterator j;
    for(j = crew.begin(); j < crew.end(); ++j)
    {
        points += j->getPoints();
    }
    return points;
}

int ModelWarMachine::computePointsWithoutOptions()
{
    //compute whole points of the model
    int points = computeBasePointsWithoutOptions();
    QList<StatsModel>::Iterator j;
    for(j = crew.begin(); j < crew.end(); ++j)
    {
        points += j->getPoints();
    }
    return points;
}

QString ModelWarMachine::displayStringInfo()
{
    QString s;
    QTextStream info(&s);
    info << "Model War Machine : " << endl;
    info << displayBaseInfo();
    info << "====================================================" << endl;
    info << QString(QString::fromUtf8("Règles additionnelles : ")) << endl;
    info << specialRules << endl;
    info << "====================================================" << endl;
    info << QString(QString::fromUtf8("Statistique des servants : ")) << endl;
    QList<StatsModel>::iterator i;
    for(i = crew.begin(); i < crew.end() ; ++i)
    {
        info << "------------------" << endl;
        info << i->displayString() << endl;;
    }
    info << "====================================================" << endl;
    return s;
}

QString ModelWarMachine::getHtml()
{
    QString html;
    html += getBaseHtml();
    html += "Règles additionnelles : <br/>\n";
    html += QString(specialRules.toHtmlEscaped() + "<br/>\n");
    if(crew.size() != 0)
    {
        html += QString("Liste des servants: <br/>\n");
        QList<StatsModel>::iterator i;
        for(i = crew.begin(); i < crew.end() ; ++i)
        {
            html += QString("<li>\n");
            html += QString("%1 : <br/>\n").arg(i->getName());
            html += i->getHtml();
            html += QString("</li>\n");
        }
    }
    html += "<br/>\n";

    return html;
}

QString ModelWarMachine::getSpecialRules() const
{
    return specialRules;
}

void ModelWarMachine::setSpecialRules(const QString &value)
{
    specialRules = value;
}

QList<StatsModel> ModelWarMachine::getCrew() const
{
    return crew;
}

void ModelWarMachine::setCrew(const QList<StatsModel> &value)
{
    crew = value;
}

void ModelWarMachine::addCrew(StatsModel c)
{
    crew << c;
}

void ModelWarMachine::clearCrew()
{
    crew.clear();
}

QDataStream & operator <<(QDataStream & out, const ModelWarMachine & obj)
{
    out << SAVE_VERSION;
    obj.serializeOutBase(out);
    out << obj.specialRules
        << obj.crew.size();

    for(int i = 0 ; i < obj.crew.size() ; i++)
    {
        out << obj.crew[i];
    }

    return out;
}

QDataStream & operator >>(QDataStream & in, ModelWarMachine & obj)
{
    int nb;
    int version = 0;

    in >> version;
    obj.serializeInBase(in);
    //in >> static_cast<ModelAbstract&>(obj);
    if( version < 3)
    {
        int type = 0;
        in >> type;

        switch(type)
        {
        case 0:
            obj.type = BASE;
            break;
        case 1:
            obj.type = SPECIAL;
            break;
        case 2:
            obj.type = RARE;
            break;
        case 3:
            obj.type = CHARACTER;
            break;
        default:
            break;
        }
    }
    in >> obj.specialRules;
    in >> nb;

    for(int i = 0 ; i < nb ; i++)
    {
        StatsModel s;
        in >> s;
        obj.addCrew(s);
    }

    return in;
}
