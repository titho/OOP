#include "ex1.h"
#include <iostream>
using namespace std;

int main()
{
	ElectricDevice dev("Hairdrier", 75), dev2("Toaster", 50), dev3("Lamp", 10);
	ElectricNet net(300);
	net + dev;
	net += dev2;
	net += dev3;
	net.print();

	++net;
	cout << !net << endl;
	net -= "Toaster";
	net.print();

	--net;
	--net;
	--net;
	net.print();
	--net;
	net.print();
	ElectricDevice dev4("Ivan", 110);
	net + dev4;
	system("pause");
	return 0;

}