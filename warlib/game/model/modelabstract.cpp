#include "modelabstract.h"

ModelAbstract::ModelAbstract()
{
}

ModelAbstract::ModelAbstract(const StatsModel &stat,
                             const int &widthBase,
                             const int &lengthBase,
                             const int &unitP,
                             const QString &url)
{
    stats = stat;
    squareBaseW = widthBase;
    squareBaseL = lengthBase;
    unitPower = unitP;
    imagePath = url;
}

ModelAbstract::ModelAbstract(const QString &n,
                             const QString &move,
                             const QString &weaponS,
                             const QString &balisticS,
                             const QString &strength,
                             const QString &toughness,
                             const QString &wounds,
                             const QString &init,
                             const QString &attacks,
                             const QString &leadership,
                             const QString &save,
                             const QString &invSave,
                             const int points,
                             const int &widthBase,
                             const int &lengthBase,
                             const int &unitP,
                             const QString &url)
{
    stats.setName(n);
    stats.setM(move);
    stats.setWs(weaponS);
    stats.setBs(balisticS);
    stats.setS(strength);
    stats.setT(toughness);
    stats.setW(wounds);
    stats.setI(init);
    stats.setA(attacks);
    stats.setLd(leadership);
    stats.setSvg(save);
    stats.setSvgInv(invSave);
    stats.setPoints(points);

    squareBaseW = widthBase;
    squareBaseL = lengthBase;
    unitPower = unitP;

    imagePath = url;
}

ModelAbstract::ModelAbstract(const ModelAbstract &copy) : SerializableObject()
{
    stats = copy.stats;
    imagePath = copy.imagePath;
    squareBaseW = copy.squareBaseW;
    squareBaseL = copy.squareBaseL;
    unitPower = copy.unitPower;
    options = copy.options;
    banner = copy.banner;
    bannerPoints = copy.bannerPoints;
    musician = copy.musician;
    musicianPoints = copy.musicianPoints;
    champion = copy.champion;
    championStats = copy.championStats;
}

ModelAbstract::~ModelAbstract(){}


QString ModelAbstract::displayBaseInfo()
{
    QString s;
    QTextStream info(&s);
    info << stats.getName() << endl;
    info << "Points : " << computePoints() << endl;
    info << "====================================================" << endl;
    info << stats.displayString();
    info << "====================================================" << endl;
    info << "Base width : " << squareBaseW << endl;
    info << "Base length : " << squareBaseL << endl;
    info << "Unit power : " << unitPower << endl;
    info << "Image path : " << imagePath << endl;
    info << "Available options : " << endl;
    QList<OptionModel>::iterator i;
    for(i = options.begin(); i < options.end() ; ++i)
    {
        info << "----------------------------" << endl;
        info << i->displayString() << endl;
    }
    if(musician)
    {
        info << "Has a musician for " << musicianPoints << " points." << endl;
    }
    else info << "Has no musician (" << musicianPoints << " pts)" << endl;
    if(banner)
    {
        info << "Has a banner for " << bannerPoints << " points." << endl;
    }
    else info << "Has no banner (" << musicianPoints << " pts)" << endl;
    if(champion)
    {
        info << "Has a champion : " << endl;
        info << championStats.displayString();
    }
    else
    {
        info << "Has no champion." << endl;
        info << championStats.displayString();
    }

    return s;
}


QString ModelAbstract::getBaseHtml()
{
    QString html;
    html += QString("%1</h2>\n").arg(stats.getName());
	html += stats.getHtml();
	QList<OptionModel>::iterator i;
    for(i = options.begin(); i < options.end() ; ++i)
    {
        if(i->isActivated())
        {
            html += "<li>";
            html += i->getHtml();
            html += "</li>\n";
        }
	}
	html += "<br/>\n";
	
    return html;
}


StatsModel ModelAbstract::getStats() const
{
    return stats;
}

void ModelAbstract::setStats(const StatsModel &value)
{
    stats = value;
}


int ModelAbstract::getUnitPower() const
{
    return unitPower;
}

void ModelAbstract::setUnitPower(int value)
{
    unitPower = value;
}

int ModelAbstract::getSquareBaseL() const
{
    return squareBaseL;
}

void ModelAbstract::setSquareBaseL(int value)
{
    squareBaseL = value;
}

int ModelAbstract::getSquareBaseW() const
{
    return squareBaseW;
}

void ModelAbstract::setSquareBaseW(int value)
{
    squareBaseW = value;
}

QList<OptionModel> ModelAbstract::getOptions() const
{
    return options;
}

void ModelAbstract::setOptions(const QList<OptionModel> &value)
{
    options = value;
}

void ModelAbstract::addOption(const OptionModel &opt)
{
    options << opt;
}

void ModelAbstract::removeOption(const OptionModel& opt)
{
    options.removeOne(opt);
}

void ModelAbstract::clearOptions()
{
    options.clear();
}

QString ModelAbstract::getImagePath() const
{
    return imagePath;
}

void ModelAbstract::setImagePath(const QString &value)
{
    imagePath = value;
}

StatsModel ModelAbstract::getChampionStats() const
{
    return championStats;
}

void ModelAbstract::setChampionStats(const StatsModel &value)
{
    championStats = value;
}

bool ModelAbstract::getChampion() const
{
    return champion;
}

void ModelAbstract::setChampion(bool value)
{
    champion = value;
}

int ModelAbstract::getMusicianPoints() const
{
    return musicianPoints;
}

void ModelAbstract::setMusicianPoints(int value)
{
    musicianPoints = value;
}

bool ModelAbstract::getMusician() const
{
    return musician;
}

void ModelAbstract::setMusician(bool value)
{
    musician = value;
}


bool ModelAbstract::getBanner() const
{
    return banner;
}

void ModelAbstract::setBanner(bool value)
{
    banner = value;
}

int ModelAbstract::getBannerPoints() const
{
    return bannerPoints;
}

void ModelAbstract::setBannerPoints(int value)
{
    bannerPoints = value;
}

int ModelAbstract::getRegimentPoints()
{
    int points = 0;
    QList<OptionModel>::iterator i;
    for (i = options.begin(); i != options.end(); ++i)
    {
        if(i->isActivated() && i->isRegimentOptions())
            points += i->getNbPoints();
    }
    return points;
}

int ModelAbstract::computeBasePoints()
{
    int points = stats.getPoints();
    QList<OptionModel>::iterator i;
    for (i = options.begin(); i != options.end(); ++i)
    {
        if(i->isActivated() && !i->isRegimentOptions())
            points += i->getNbPoints();
    }
    return points;
}
