#pragma once
#ifndef __CORONAVIRUS_H__
#define __CORONAVIRUS_H__
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include <cstdlib>
#include <ctime>
#include<list>
using namespace std;


class CoronaVirus
{
public:
	CoronaVirus();
	~CoronaVirus();
	string m_dra;
	int m_resistance;

	void loadADNInfomation() {
		ifstream f;
		f.open("D:/ATGX.bin");
		getline(f, m_dra);
		f.close();
		//log("CoronaVirus LoadADNInfomation()");
	}

	void reduceResistance(int i_medicineResistance) {
		m_resistance = m_resistance - i_medicineResistance;
	}

	bool isLive()
	{
		cout << "virus song" << endl;
		return this->m_resistance > 0;
	}

	virtual vector<CoronaVirus*> doClone() = 0;
	virtual void doBorn() {};
	virtual void initResistance() {};
	virtual void doDie() {};
private:

};

#endif // !__CORONAVIRUS_H__
