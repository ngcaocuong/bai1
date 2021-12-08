#include"AlphaCoronaVirus.h"
#include<iostream>
AlphaCoronaVirus::AlphaCoronaVirus()
{
	this->doBorn();
	this->initResistance();
	//log("AlphaCoronaVirus Contructor()");
}

AlphaCoronaVirus::~AlphaCoronaVirus()
{
	this->doDie();
	//log("AlphaCoronaVirus Destructor()");
}

void AlphaCoronaVirus::doBorn()
{
	this->loadADNInfomation();
	this->m_color = (rand() % 2 == 0) ? AlphaCoronaVirrusColor::blue : AlphaCoronaVirrusColor::red;
	//log("AlphaCoronaVirus doBorn()");
}
vector<CoronaVirus*> AlphaCoronaVirus::doClone()
{
	vector<CoronaVirus*> array(1, new AlphaCoronaVirus(*this));
	return array;
};
void AlphaCoronaVirus::doDie()
{
	//log("AlphaCoronaVirus doDie()");
}
void AlphaCoronaVirus::initResistance()
{
	switch (this->m_color)
	{
	case AlphaCoronaVirrusColor::red:
		this->m_resistance = rand() % 11 + 10;
		break;
	case AlphaCoronaVirrusColor::blue:
		this->m_resistance = rand() % 6 + 10;
		break;
	}
	//log("AlphaCoronaVirus initResistance()");
}
void AlphaCoronaVirus::setResistance(int resistance)
{
	this->m_resistance = resistance;
}