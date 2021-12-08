#pragma once
#ifndef _PATIENT_H__
#define _PATIENT_H__
#include<vector>
#include"CoronaVirus.h"
enum PatientState
{
	DIE,
	ALIVE
};

class Patient
{
public:
	Patient();
	~Patient();
	int number_Alpha = 0;
	int number_Beta = 10;
	int Alpha_Resistance = 100;
	int Beta_Resistance = 100;
	int m_resistance;
	PatientState getState();
	void initResistance();
	void doStart(int number_Alpha, int number_Beta);
	void takeMedicine(int i_medicineResistance);
	void doDie();
	PatientState m_state = PatientState::ALIVE;
	vector<CoronaVirus*> m_virusList;

	void SetResistance(int resistance) {
		this->m_resistance = resistance;
	}
private:

};

#endif // !_PATIENT_H__

