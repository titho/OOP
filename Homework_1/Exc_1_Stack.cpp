#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack()
{
	top = -1; 
}

bool Stack::empty() const 
{
	return top == -1;
}

double Stack::peek() const 
{
	if (empty()) {
		cout << "The stack is empty!\n";
		return 0;
	}

	return arr[top];
}

void Stack::push(double x) {
	if (full()) {
		cout << "The stack is full!\n";
	}
	else
		arr[++top] = x;
}

bool Stack::full() const {
	return top == MAX - 1;
}

double Stack::pop() {
	if (empty()) {
		cout << "The stack is empty!\n";
		return 0;
	}
	return arr[top--];
}


	
