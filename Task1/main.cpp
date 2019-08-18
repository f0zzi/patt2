#include <iostream>
#include "Builder.h"
using namespace std;

int main()
{
	BrickBuilder b;
	Director d;
	MoneyBuilder m;
	Plan p;
	d.SetBuilder(b);
	d.SetPlan(p);
	d.Build();
	House * h = b.GetHouse();
	cout << endl;
	h->PrintReport();
	d.SetBuilder(m);
	d.Build();
	cout << endl;
	cout << "House cost:" << endl;
	cout << m.GetMoney() << endl;
	system("pause");
	return 0;
}