#include <iostream>

using namespace std;

class Int 
{
private:
	int number;
public:
	Int() : number(0) {};
	Int(int number) : number(number) {};

	void addInt(Int i1, Int i2)
	{
		number = i1.number + i2.number;
	}

	void display()
	{
		cout << "Number = " << number << endl;
	}
};

int main()
{
	Int a(5); 
	Int b(10);
	
	Int c;

	c.addInt(a, b);
	c.display();
}