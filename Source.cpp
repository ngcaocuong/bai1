#include"CoronaVirus.h"
#include"AlphaCoronaVirus.h"
#include"BetaCoronaVirus.h"
#include"Patient.h"
#include"Defintion.h"

int main() {
	Patient p;
	p.SetResistance(1000);
	const int k_m = 1;
	while (p.getState() != DIE) {
		p.takeMedicine(k_m);
	}
	return 0;
}