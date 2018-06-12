#include <iostream>
#include "Vehicle.h"
using namespace std;

int main()
{
	Truck v("Tesla", "10p", "Blue", 2015, 200000, 20);
	Car c("Tesly", "10p", "Blue", 2015, 200000);
	Motorcycle m("Harley", "200", "Red", 2010, 15000, "Chopper");
	v.details();
	cout << endl;
	c.details();
	cout << endl;
	m.details();
	
	system("pause");
	return 0;
}