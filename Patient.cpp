#include"Patient.h"
#include"AlphaCoronaVirus.h"
#include"BetaCoronaVirus.h"

Patient::Patient()
{
	this->initResistance();
	this->doStart(number_Alpha, number_Beta);
	this->m_state = ALIVE;
}

Patient::~Patient()
{
}

void Patient::initResistance() {//khoi tao de khang
	this->m_resistance = rand() % 8001 + 1000;
	//cout << "Patient initResistance()" << endl;
}


void Patient::doStart(int number_Alpha, int number_Beta) {
	for (int i = 0; i < number_Alpha; i++)
	{
		auto virus = new AlphaCoronaVirus();
		virus->setResistance(Alpha_Resistance);
		this->m_virusList.push_back(virus);
		this->m_state = ALIVE;
	}
	for (int i = 0; i < number_Beta; i++)
	{
		auto virus = new BetaCoronaVirus();
		virus->SetResistance(Beta_Resistance);
		this->m_virusList.push_back(virus);
		this->m_state = ALIVE;
	}
}

void Patient::takeMedicine(int i_medicineResistance) {
	cout << "trong co the nguoi co " << m_virusList.size() << "virus" << endl;
	for (vector<CoronaVirus*>::iterator it = m_virusList.begin(); it < m_virusList.end(); it++)
	{
		cout << "de khang ban dau virut" << (*it)->m_resistance << endl;
		(*it)->reduceResistance(i_medicineResistance);
		if ((*it)->isLive() == false)
		{
			cout << (*it)->m_resistance;

			if (it != m_virusList.end())
			{
				it = m_virusList.erase(it);
			}
			if (it > m_virusList.begin()) it--;
			cout << "a Virus die" << endl;

		}
	}
	if (m_virusList.size() == 1)
	{
		auto it = m_virusList.begin();
		if ((*it)->m_resistance <= i_medicineResistance)
			m_virusList.clear();
	}
	cout << "trong co the nguoi con lai " << m_virusList.size() << "virus" << endl;

	vector <CoronaVirus*> virusnew;
	for (vector<CoronaVirus*>::iterator it = m_virusList.begin(); it < m_virusList.end(); it++)
	{
		auto i = (*it)->doClone();
		if (i.size() == 1)
			virusnew.insert(virusnew.end(), *i.begin());
		else
		{
			for (vector<CoronaVirus*>::iterator j = i.begin(); j < i.end(); j++)
			{
				virusnew.push_back(*j);
			}
		}
	}
	for (vector<CoronaVirus*>::iterator it = virusnew.begin(); it < virusnew.end(); it++)
	{
		m_virusList.push_back(*it);
	}

	cout << "tong sau khi nhan ban " << m_virusList.size() << "virus" << endl;
	int sum = 0;
	for (vector<CoronaVirus*>::iterator it = m_virusList.begin(); it < m_virusList.end(); it++)
	{
		sum += (*it)->m_resistance;
	}
	cout << "de khang virus" << sum << "de khang benh nhan" << this->m_resistance << endl;
	if (sum > this->m_resistance) this->doDie();
	else
	{
		cout << "dont die" << endl;
	}
}

void Patient::doDie() {
	m_state = DIE;
	this->m_virusList.clear();
	//cout << "Patient doDie" << endl;
}

PatientState Patient::getState() {
	//cout << "Patient getState" << endl;
	return m_state;
}