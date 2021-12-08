#pragma once
#ifndef _BETACORONAVIRUS_H__
#define _BETACORONAVIRUS_H__
#include"CoronaVirus.h"
#include<vector>
enum BetaCoronaVirusProtein
{
	NS3,
	NS5,
	E,
};

class BetaCoronaVirus :public CoronaVirus
{
public:
	BetaCoronaVirus();
	~BetaCoronaVirus();
	void doBorn() override;
	vector<CoronaVirus*> doClone() override;
	void doDie() override;
	void initResistance() override;
	void SetResistance(int resistance);
private:
	BetaCoronaVirusProtein m_protein;
};

#endif // !_BETACORONAVIRUS_H__

