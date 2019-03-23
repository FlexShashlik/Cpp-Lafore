#include <iostream>

using namespace std;

struct Pair
{
	int x, y;
};

class Stack
{
protected:
	enum { MAX = 10 };
	int st[MAX];
	int top;
public:
	Stack()
	{
		top = -1;
	}
	void push(int var)
	{
		st[++top] = var;
	}
	int pop()
	{
		return st[top--];
	}
};

class Stack2 : public Stack
{
public:
	void push(int var)
	{
		if (top >= MAX - 1)
		{
			cout << "\nStack overflow!"; 
			exit(1);
		}
		Stack::push(var);
	}
	int pop()
	{
		if (top < 0)
		{
			cout << "\nStack is empty!\n"; 
			exit(1);
		}
		return Stack::pop();
	}
};

class PairStack : private Stack2
{
public:
	void push(Pair p)
	{
		Stack2::push(p.x);
		Stack2::push(p.y);
	}

	Pair pop()
	{
		Pair temp;
		temp.y = Stack2::pop();
		temp.x = Stack2::pop();

		return temp;
	}
};

int main()
{
	Stack2 s1;

	s1.push(11);
	s1.push(22);
	s1.push(33);

	cout << endl << s1.pop();
	cout << endl << s1.pop();
	cout << endl << s1.pop() << endl;
	//cout << endl << s1.pop();
	
	PairStack ps;

	Pair p{ 1, 5 }, p1{6, 5};
	ps.push(p);
	ps.push(p1);

	p1 = ps.pop();
	p = ps.pop();

	cout << "x: " << p.x << " y: " << p.y << endl;
	cout << "x: " << p1.x << " y: " << p1.y << endl;

	return 0;
}