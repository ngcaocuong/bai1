#include"CoronaVirus.h"

using namespace std;

CoronaVirus::CoronaVirus()
{
	doBorn();
	initResistance();
	//log("CoronaVirus Contructor()");
};

CoronaVirus::~CoronaVirus()
{
	this->doDie();
	//log("CoronaVirus Destructor()");
};
