#include"BetaCoronaVirus.h"

BetaCoronaVirus::BetaCoronaVirus()
{
	this->doBorn();
	this->initResistance();
	//log("BetaCoronaVirus Contructor()");
};

BetaCoronaVirus::~BetaCoronaVirus()
{
	this->doDie();
	//log("BetaCoronaVirus Destructor()");
};

void BetaCoronaVirus::doBorn() {
	this->loadADNInfomation();
	if (rand() % 3 == 0) {
		this->m_protein = BetaCoronaVirusProtein::NS3;
	}
	else if (rand() % 3 == 1)
	{
		this->m_protein = BetaCoronaVirusProtein::NS5;
	}
	else
	{
		this->m_protein = BetaCoronaVirusProtein::E;
	}
	//log("BetaCoronaVirus doBorn()");
}

vector<CoronaVirus*> BetaCoronaVirus::doClone() {
	vector<CoronaVirus*> array(2, new BetaCoronaVirus(*this));
	return array;
}

void BetaCoronaVirus::doDie() {

	//log("BetaCoronaVirus doDie()");
}

void BetaCoronaVirus::initResistance() {
	switch (this->m_protein)
	{
	case BetaCoronaVirusProtein::NS3:
		this->m_resistance = rand() % 11;
	case BetaCoronaVirusProtein::NS5:
		this->m_resistance = rand() % 11 + 10;
	case BetaCoronaVirusProtein::E:
		this->m_resistance = rand() % 11 + 20;
	}
	//log("BetaCoronaVirus initResistance()");
}

void BetaCoronaVirus::SetResistance(int resistance) {
	this->m_resistance = resistance;
}