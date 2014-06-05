/*********************************************************************//**
* modelabstract.h
* StatsModel class
*
* AUTEUR: Alexandre Jumeline
* DATE: 03-04-2014
*************************************************************************/

#ifndef STATSMODEL_H
#define STATSMODEL_H

#include <QObject>
#include <QtCore>
#include <QtWidgets>
#include <QDataStream>
#include <QTextStream>

#include "defines.h"
#include "core/serializableobject.h"


//! StatsModel class
/*!
* This class holds all the common attributes of a model.
*/
class StatsModel : public SerializableObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString m READ getM WRITE setM NOTIFY mChanged)
    Q_PROPERTY(QString ws READ getWs WRITE setWs NOTIFY wsChanged)
    Q_PROPERTY(QString bs READ getBs WRITE setBs NOTIFY bsChanged)
    Q_PROPERTY(QString s READ getS WRITE setS NOTIFY sChanged)
    Q_PROPERTY(QString t READ getT WRITE setT NOTIFY tChanged)
    Q_PROPERTY(QString w READ getW WRITE setW NOTIFY wChanged)
    Q_PROPERTY(QString i READ getI WRITE setI NOTIFY iChanged)
    Q_PROPERTY(QString a READ getA WRITE setA NOTIFY aChanged)
    Q_PROPERTY(QString ld READ getLd WRITE setLd NOTIFY ldChanged)
    Q_PROPERTY(QString svg READ getSvg WRITE setSvg NOTIFY svgChanged)
    Q_PROPERTY(QString svgInv READ getSvgInv WRITE setSvgInv NOTIFY svgInvChanged)
    Q_PROPERTY(int points READ getPoints WRITE setPoints NOTIFY pointsChanged)

public:
    //! Constructor.
	/*!
    * Base constructor of StatsModel class
	*/
    StatsModel();
    
    //! Copy Constructor.
	/*!
	* Copy constructor of StatsModel class
	*/
    StatsModel(const StatsModel&);
    
    //! Constructor.
	/*!
	* Constructor of StatsModel class
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
    StatsModel(const QString &n, const QString &move, const QString &weaponS, const QString &balisticS,
               const QString &strength, const QString &toughness, const QString &wounds,
               const QString &init, const QString &attacks, const QString &leadership,
               const QString &save, const QString &invSave, int p);
	
	//! Destructor.
	/*!
	* Base destructor of StatsModel class
	*/
    virtual ~StatsModel();
	
	//! operator=
	/*!
	* Overload of operator= for StatsModel class
	* \param s StatsModel whose values will be assigned from.
	*/
    StatsModel& operator=(const StatsModel&);
	
	//! operator==
	/*!
	* Overload of operator== for StatsModel class
	* \param s StatsModel whose values will be compared to.
	*/
    bool operator==(const StatsModel&);
	
	//! displayString
	/*!
	* Method that returns a string summerizing the values in the object.
	* \return String containing information.
	*/
    QString displayString() const;
    
    //! getHtml
	/*!
	* Virtual Method that returns a string summerizing the values in the object
	* using HTML format. Used principally to export data as pdf files.
	* \return String containing information using HTML.
	*/
    QString getHtml() const;
	
	//! getName
	/*!
	* get accessor for name value.
	* \return name Returns the name of the model.
	*/
    QString getName() const;
    void setName(const QString &value);

	//! getM
	/*!
	* get accessor for m value.
	* \return name Returns the movement speed of the model.
	*/
    QString getM() const;
    void setM(const QString &value);
	
	//! getWs
	/*!
	* get accessor for ws value.
	* \return name Returns the movement weapon skills of the model.
	*/
    QString getWs() const;
    void setWs(const QString &value);

	//! getBs
	/*!
	* get accessor for bs value.
	* \return name Returns the movement balistic skills of the model.
	*/
    QString getBs() const;
    void setBs(const QString &value);

	//! getS
	/*!
	* get accessor for ws value.
	* \return name Returns the movement strength of the model.
	*/
    QString getS() const;
    void setS(const QString &value);
	
	//! getT
	/*!
	* get accessor for ws value.
	* \return name Returns the toughness of the model.
	*/
    QString getT() const;
    void setT(const QString &value);
	
	//! getW
	/*!
	* get accessor for ws value.
	* \return name Returns the wounds of the model.
	*/
    QString getW() const;
    void setW(const QString &value);
	
	//! getI
	/*!
	* get accessor for ws value.
	* \return name Returns the initiative of the model.
	*/
    QString getI() const;
    void setI(const QString &value);
	
	//! getA
	/*!
	* get accessor for ws value.
	* \return name Returns the number of attacks of the model.
	*/
    QString getA() const;
    void setA(const QString &value);

	//! getLd
	/*!
	* get accessor for ws value.
	* \return name Returns the leadership of the model.
	*/
    QString getLd() const;
    void setLd(const QString &value);
	
	//! getSvg
	/*!
	* get accessor for ws value.
	* \return name Returns the armor save of the model.
	*/
    QString getSvg() const;
    void setSvg(const QString &value);
	
	//! getSvgInv
	/*!
	* get accessor for ws value.
	* \return name Returns the invulnerable armor save of the model.
	*/
    QString getSvgInv() const;
    void setSvgInv(const QString &value);
	
	//! getPoints
	/*!
	* get accessor for ws value.
	* \return name Returns the points of the model.
	*/
    int getPoints() const;
    void setPoints(int value);

    //! initStatsModelMetaType
    /*!
    * Init metatype information of the class so that it can be
    * serialized by Qt property system.
    */
    static void initStatsModelMetaType();

signals:
    void nameChanged();
    void mChanged();
    void wsChanged();
    void bsChanged();
    void sChanged();
    void tChanged();
    void wChanged();
    void iChanged();
    void aChanged();
    void ldChanged();
    void svgChanged();
    void svgInvChanged();
    void pointsChanged();

protected:

    QString name;	/// Name of the model
    QString m;      /// Movement of the model
    QString ws;     /// Weapon skill of the model
    QString bs;     /// Balistic skill of the model
    QString s;      /// Strength of the model
    QString t;      /// Toughtness of the model
    QString w;      /// Wounds of the model
    QString i;      /// Initiative of the model
    QString a;      /// Attacks of the model
    QString ld;     /// Leadership of the model
    QString svg;    /// Armor save of the model
    QString svgInv; /// Invulnerable armor save of the model

    int points;     /// Points of the model
};

Q_DECLARE_METATYPE(StatsModel)

#endif // STATSMODEL_H
