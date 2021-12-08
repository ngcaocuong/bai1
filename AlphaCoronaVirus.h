#pragma once
#ifndef _ALPHACORONAVIRUS_H__
#define _ALPHACORONAVIRUS_H__
#include"CoronaVirus.h"
#include<vector>
enum AlphaCoronaVirrusColor {
	blue = 0x0000ff,
	red = 0xff0000,
};

class AlphaCoronaVirus : public CoronaVirus
{
public:
	AlphaCoronaVirus();
	~AlphaCoronaVirus();
	void doBorn() override;
	vector<CoronaVirus*> doClone() override;
	void doDie() override;
	void initResistance() override;
	void setResistance(int resistance);

private:
	AlphaCoronaVirrusColor m_color;
};

#endif // !_ALPHACORONAVIRUS_H__

