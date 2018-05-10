int const MAX = 100;

class Stack
{
private:
	double arr[MAX];	
	int top;	 

	bool full() const;

public:

	Stack();
	bool empty() const;
	double peek() const;
	void push(double);
	double pop();
};
