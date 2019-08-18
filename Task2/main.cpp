#include <iostream>
#include <vector>
#include "Units.h"
using namespace std;

int main()
{
	Barrack* war = new MilitaryAcademy;
	Barrack* sci = new TechnicalAcademy;
	Barrack* med = new MedicalAcademy;

	vector<Unit*>squad;
	squad.push_back(war->CreateUnit());
	squad.push_back(war->CreateUnit());
	squad.push_back(sci->CreateUnit());
	squad.push_back(med->CreateUnit());

	cout << "Unit#\t" << "Type:\t" << "HP:\t" << "Damage:\t" << "Ability:" << endl;
	for (size_t i = 0; i < squad.size(); i++)
	{
		cout << "Unit " << i + 1 << ":\t" 
			 << squad[i]->GetTypeStr() << "\t" 
			 << squad[i]->GetHp() << "\t" 
			 << squad[i]->GetDamage() << "\t"
			 << squad[i]->Ability() << endl;
	}
	system("pause");
	return 0;
}