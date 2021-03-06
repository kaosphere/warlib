#include "DiceRoller.h"

void DiceRoller::initDiceRoller()
{
	//init random generator
	srand(time(NULL));
}

int DiceRoller::rollSingleDie(Dice die)
{
	return computeDiceOutput(die);
}

QList<int> DiceRoller::rollDiceInt(Dice die, int nbDice)
{
	QList<int> l;
	for(int i = 0; i < nbDice; ++i)
	{
		l.append(computeDiceOutput(die));
	}
	return l;
}


QString DiceRoller::rollDiceString(Dice die, int nbDice)
{
	QStringList l;
	for(int i = 0; i < nbDice; ++i)
	{
		l << QString::number(computeDiceOutput(die));
	}
    qSort(l.begin(), l.end(),qLess<QString>());
	QString str;
	QTextStream info(&str);
    info << "<em><font color=\"DimGray\">" << QObject::tr("Lancé ") <<
            QString::number(nbDice) << QObject::tr(" dés : ") << "</em></font>";
	for (int i = 0; i < l.size(); ++i)
          info << l.at(i) << ", ";
    info << endl;
	return str;
}

int DiceRoller::computeDiceOutput(Dice d)
{
    return rand() % d + 1;
}

QPair<QPair<int, QString>, QString> DiceRoller::computeDispersionDice()
{
	// Dispersion
	QPair<int, QString> disp;
	disp.first = rand() % 360 + 1;
	int hit = rand() % 3 + 1;
	if(hit == 1) disp.second = "hit";
	else disp.second = "miss";
	// Deviation
	QPair<QPair<int, QString>, QString> artillery;
    int dev = rand() % 6 + 1;
	if(dev == 6) artillery.second = "Incident de tir";
    else artillery.second = QString::number(dev * 2);
	
	artillery.first = disp;
	
    return artillery;
}

int DiceRoller::getDispersion()
{
    return rand()% 360 + 1;
}


