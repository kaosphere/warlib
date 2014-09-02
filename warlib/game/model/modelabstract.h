/*! ********************************************************************
* modelabstract.h
* ModelAbstract class
*
* AUTEUR: Alexandre Jumeline
* DATE: 03-04-2014
*************************************************************************/

#ifndef MODELABSTRACT_H
#define MODELABSTRACT_H

#include <QObject>
#include <QtCore>
#include <iostream>
#include <QTextDocument>
#include <QList>

#include "game/option/optionmodel.h"
#include "game/stats/statsmodel.h"
#include "game/paramsfromUI/paramsfromuimodel.h"
#include "core/serializableobject.h"
#include "defines.h"

//! ModelAbstract class
/*!
* Main data structure storing model characteristics.
* This is the base class for all types of models.
*/
class ModelAbstract : public SerializableObject
{
    Q_OBJECT
    Q_PROPERTY(StatsModel stats READ getStats WRITE setStats NOTIFY StatsChanged)
    Q_PROPERTY(int squareBaseW READ getSquareBaseW WRITE setSquareBaseW NOTIFY squareBaseWChanged)
    Q_PROPERTY(int squareBaseL READ getSquareBaseL WRITE setSquareBaseL NOTIFY squareBaseLChanged)
    Q_PROPERTY(int unitPower READ getUnitPower WRITE setUnitPower NOTIFY unitPowerChanged)
    Q_PROPERTY(QString imagePath READ getImagePath WRITE setImagePath NOTIFY imagePathChanged)
    Q_PROPERTY(QList<QVariant> options READ getOptionsVariant WRITE setOptionsVariant NOTIFY optionsChanged)
    Q_PROPERTY(bool banner READ getBanner WRITE setBanner NOTIFY bannerChanged)
    Q_PROPERTY(int bannerPoints READ getBannerPoints WRITE setBannerPoints NOTIFY bannerPointsChanged)
    Q_PROPERTY(bool musician READ getMusician WRITE setMusician NOTIFY musicianChanged)
    Q_PROPERTY(int musicianPoints READ getMusicianPoints WRITE setMusicianPoints NOTIFY musicianPointsChanged)
    Q_PROPERTY(bool champion READ getChampion WRITE setChampion NOTIFY championChanged)
    Q_PROPERTY(StatsModel championStats READ getChampionStats WRITE setChampionStats NOTIFY championStatsChanged)

public:
	//! Constructor.
	/*!
	Base constructor of ModelAbstract class
	*/
    explicit ModelAbstract();
	
	//! Constructor.
	/*!
	* Constructor of ModelAbstract class
	* \param stat A StatsModel object.
	* \param widthBase width of the model's base.
	* \param lengthBase length of the model's base.
	* \param unitP Unit power of the model
	* \param url Path of the model image
	* \param figSup DEPRECATED. TODO: Remove
	*/
    ModelAbstract(const StatsModel& stat, const int &widthBase,
                  const int &lengthBase, const int &unitP, const QString& url);
	
	//! A constructor.
	/*!
	* Constructor of ModelAbstract class
	* \param stat A StatsModel object.
	* \param widthBase width of the model's base.
	* \param lengthBase length of the model's base.
	* \param unitP Unit power of the model
	* \param url Path of the model image
	* \param figSup DEPRECATED. TODO: Remove
	* \param n Name of the model
	* \param move Movement speed
	* \param weaponS Weapon skills
	* \param balisticS Balistic skills
	* \param streangth Strength of the model
	* \param toughness Toughness of the model
	* \param wounds Wounds of the model
	* \param init Initiative of the model
	* \param attacks Number of attacks of the model
	* \param leadership Leadership value of the model
	* \param save Armor save of the model
	* \param invSave Invulnerable armor save of the model
	* \param p Points of the model
	*/
    ModelAbstract(const QString &n, const QString &move, const QString &weaponS,
                  const QString &balisticS, const QString &strength, const QString &toughness,
                  const QString &wounds, const QString &init, const QString &attacks,
                  const QString &leadership, const QString &save, const QString &invSave, const int points, const int &widthBase,
                  const int &lengthBase, const int &unitP, const QString& url);
	
	//! Copy Constructor.
	/*!
    * Copy constructor of ModelAbstract class
    * Here the copy constructor calls the base constructor of
    * SerializableObject because copy constructor of QObject is
    * disabled. This way, a new QObject is created each time
    * and the identity paradigm from Qt is respected.
	*/
    ModelAbstract(const ModelAbstract &Copy);
	
	//! Destructor.
	/*!
	* Base destructor of ModelAbstract class
	*/
    virtual ~ModelAbstract();
	
	//! Save
	/*!
	* VIRTUAL : Method that initiate the saving of the model object in a file.
	* \param path File path of the file to be saved.
	*/
    virtual void save(const QString path) = 0;
	
	//! setFromFile
	/*!
	* VIRTUAL : Method that loads a model from a previously saved file.
	* \param path File path of the file to be loaded.
	*/
    virtual ModelAbstract* setFromFile(const QString path) = 0;
    
    //! setFromUI
	/*!
	* VIRTUAL : Method that loads a model from a form in the UI.
	* \param params parameter object containing every model possible parameters.
	*/
    virtual ModelAbstract* setFromUI(const ParamsfromUImodel* params) = 0;
    
    //! Load
	/*!
	* VIRTUAL : Method that initiate the loading of the model object from a file.
	* \param path File path of the file to be loaded.
	*/
    virtual void load(const QString path) = 0;
    
    //! displayStringInfo
	/*!
	* VIRTUAL Method that returns a string summerizing the values in the object.
	* \return String containing information.
	*/
    virtual QString displayStringInfo() = 0;
    
    //! displayBaseInfo
	/*!
	* Method that returns a string summerizing the values in the base class object.
	* \return String containing information.
	*/
    QString displayBaseInfo();
    
    //! getHtml
	/*!
	* Virtual Method that returns a string summerizing the values in the object
	* using HTML format. Used principally to export data as pdf files.
	* \return String containing information using HTML.
	*/
    virtual QString getHtml() = 0;
    
    //! getBaseHtml
	/*!
	* Method that returns a string summerizing the values in the base class object
	* using HTML format. Used principally to export data as pdf files.
	* \return String containing information using HTML.
	*/
    QString getBaseHtml();

    //! clone
    /*!
    * VIRTUAL : Method that returns a copy of the object. This is used to copy a pointer
    * to a derived class.
    */
    virtual ModelAbstract* clone() = 0;

    StatsModel getStats() const;
    void setStats(const StatsModel &value);

    int getSquareBaseW() const;
    void setSquareBaseW(int value);

    int getSquareBaseL() const;
    void setSquareBaseL(int value);

    int getUnitPower() const;
    void setUnitPower(int value);

    QList<OptionModel*> getOptions() const;
    void setOptions(const QList<OptionModel *> &value);

    QList<QVariant> getOptionsVariant() const;
    void setOptionsVariant(const QList<QVariant> &value);

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
    
    //! addOption
	/*!
	* Method that adds an option to the list of options
	* \param opt option to be added
	*/
    void addOption(OptionModel *opt);
    
    //! removeOption
	/*!
	* Method that removes an option to the list of options
	* \param opt option to be removed
	*/
    void removeOption(OptionModel *opt);
    
    //! clearOptions
	/*!
	* Method that clears all options of the list of options
	*/
    void clearOptions();

    QString getImagePath() const;
    void setImagePath(const QString &value);

	//! clearOptions
	/*!
	* Virtual method that computes the global number of points of a model
	* included chosen options.
	*/
    virtual int computePoints() = 0;

    int getRegimentPoints();
    int computeBasePoints();

signals:
    void StatsChanged();
    void squareBaseWChanged();
    void squareBaseLChanged();
    void unitPowerChanged();
    void imagePathChanged();
    void optionsChanged();
    void bannerChanged();
    void bannerPointsChanged();
    void musicianChanged();
    void musicianPointsChanged();
    void championChanged();
    void championStatsChanged();

protected:

	//! stats
	/*!
	* StatsModel object of the model
	*/
    StatsModel stats;

    /// Width of the square base in millimeters
    int squareBaseW;

    /// Length of the square base in millimeters
    int squareBaseL;

    /// Unit power of the model
    int unitPower;

    /// Path to the image
    QString imagePath;

    /// List of options possible for model
    QList<OptionModel* > options;

    /// Note : it is more easy to have the banner, musician and champion informations
    /// in the model class because we don't want to enter them each time we make a regiment
    /// If they are in the model, this is just a box to check at regiment creation.

    /// Does the model have a banner ? True if yes, false if not.
    bool banner;

    /// Points for the banner to be added in the regiment.
    int bannerPoints;

    /// Does the model have a musician ? True if yes, false if not.
    bool musician;

    /// Points for the musician to be added to the regiment.
    int musicianPoints;

    /// Does the model have a champion ? True if yes, false if not.
    bool champion;

    /// Stats of the champion that the model can be assigned to.
    StatsModel championStats;
};

#endif // MODELABSTRACT_H
