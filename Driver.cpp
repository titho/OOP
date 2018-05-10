#include <iostream>
#include "Stack.h"
using namespace std;
double calculate(char arr[100])
{
	Stack values;
	int count = 0, j = 0;
	while(arr[j] != '\0') // Counts the chars in the array
	{
		if (arr[j] == ' ')
		{
			count++;
		}
		else
		{
			count++;
		}
		j++;
	}
	double a = 0, b, c, mut = 10;
	bool undefined = false;
	for (int i = 0; i < count ; i++)
	{
		if (isdigit(arr[i]))
		{
			if (arr[i+1] == ' ') // If its a num < 9
			{
				a = arr[i] - '0';
				values.push(a);
			}
			else
			{
				

				}
				if (arr[i + 1] == '.')
				{
					a = arr[i] - '0';
				//	cout << "Time to get partial " << endl;
					i++;
					while (isdigit(arr[i + 1]))
					{
					//	cout << "Doing " << a << " + " << (arr[i + 1] - '0') / mut << endl;
						a = a + (arr[i + 1] - '0') / mut;
						mut *= 10;
						i++;
					}
					mut = 10;
				}
				values.push(a);
				continue;

				a = (arr[i] - '0') * 10 + (arr[i + 1] - '0'); // Pushes it once to make it > 9 
				i++;
				while (isdigit(arr[i + 1])) // If it is still not enough
				{	
					a = a * 10 + (arr[i + 1] - '0');
					i++;
				//	cout << "The number is now " << a << endl;
				}
				
				values.push(a);
		}
		else
		{
			switch (arr[i])
			{
			case '+':
				b = values.peek();
				values.pop();
				a = values.peek();
				values.pop();
				values.push(a + b);
				break;
			case'-':
				b = values.peek();
				values.pop();
				a = values.peek();
				values.pop();
				values.push(a - b);
				break;
			case'*':
				b = values.peek();
				values.pop();
				a = values.peek();
				values.pop();
				values.push(a*b);
				break;
			case '/':
				b = values.peek();
				values.pop();
				if (b == 0)
					undefined = true;
				else
				{
					a = values.peek();
					values.pop();
					values.push(a / b);
				}
				break;
			case '^':
				b = values.peek();
				values.pop();
				a = values.peek();
				values.pop();
				values.push(pow(a, b));
				break;
			
			}
		}
	}
	if (undefined) {
		cout << "No!" << endl;
	}
	else
	{
		return values.peek();
	}

}
int main()
{
	char* i;
	i = new char[100];
	cin.getline(i, 100);
	double n;
	n = calculate(i);
	cout << n << endl; 
	
	system("pause");
	return 0;
}