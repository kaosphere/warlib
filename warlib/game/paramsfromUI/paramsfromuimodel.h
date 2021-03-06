#ifndef PARAMSFROMUIMODEL_H
#define PARAMSFROMUIMODEL_H

#include <QString>
#include "game/stats/statsmodel.h"
#include "game/option/optionmodel.h"
#include "defines.h"

class ParamsfromUImodel
{
public:
    ParamsfromUImodel();
    virtual ~ParamsfromUImodel();

    StatsModel getStats() const;
    void setStats(const StatsModel &value);

    QList<OptionModel> getOptions() const;
    void setOptions(const QList<OptionModel> &value);

    int getPoints() const;
    void setPoints(int value);

    int getWidthBase() const;
    void setWidthBase(int value);

    int getLengthBase() const;
    void setLengthBase(int value);

    int getUnitP() const;
    void setUnitP(int value);

    QString getUrlImage() const;
    void setUrlImage(const QString &value);

    bool getFigSup() const;
    void setFigSup(bool value);

    QString getSpecRules() const;
    void setSpecRules(const QString &value);

    bool getLord() const;
    void setLord(bool value);

    bool getGeneral() const;
    void setGeneral(bool value);

    bool getMage() const;
    void setMage(bool value);

    bool getMounted() const;
    void setMounted(bool value);

    bool getHasCrew() const;
    void setHasCrew(bool value);

    QList<StatsModel> getMorC() const;
    void setMorC(const QList<StatsModel> &value);

    ModelType getType() const;
    void setType(ModelType value);

    bool getHasGB() const;
    void setHasGB(bool value);

    bool getBanner() const;
    void setBanner(bool value);

    int getBannerPoints() const;
    void setBannerPoints(int value);

    bool getMusician() const;
    void setMusician(bool value);

    int getMusicianPoints() const;
    void setMusicianPoints(int value);

    bool getChampion() const;
    void setChampion(bool value);

    StatsModel getChampionStats() const;
    void setChampionStats(const StatsModel &value);

    QPixmap getImage() const;
    void setImage(const QPixmap &value);

private:
    // modelabstract params
    StatsModel stats;
    QList<OptionModel> options;
    ModelType type;
    int points;
    int widthBase;
    int lengthBase;
    int unitP;
    QString urlImage; // Obsolete
    QPixmap image;
    bool figSup;
    // warMachine, monster, infantery, charriot, character, cavalery params
    QString specRules;
    // character params
    bool lord;
    bool general;
    bool mage;
    bool mounted;
    bool hasGB;
    // monster params
    bool hasCrew;
    // mount or crew
    QList<StatsModel> mOrC;

    bool banner;
    int bannerPoints;
    bool musician;
    int musicianPoints;
    bool champion;
    StatsModel championStats;

};

#endif // PARAMSFROMUIMODEL_H
