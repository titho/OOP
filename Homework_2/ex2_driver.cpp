#include "Ex_2.h"

int main()
{
	Pair<int> a(120, "Inty");
	Pair<int> c(3, "Inty2");

	Settings<int> s;
	/*s.add(a);
	s.add(c);*/
	s.print();
	
	s.set("first", 5);
	s.set("secondy", 10);
	s.print();
	s.set("first", 15);
	s.print();
	
	int val = 42;
	cout << s.get("first", val) << endl;
	cout << val << endl;

	system("pause");
	return 0;
	
}