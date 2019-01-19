#include <iostream>

using namespace std;

class Int
{
private:
	long double number;
public:
	Int() : number(0) {};
	Int(int number) : number(number) {};

	Int operator+(Int i2)
	{
		number = number + i2.number;

		if (number > 2147483648 || number < -2147483648LL) 
		{
			cout << "\nInteger overflow!!!";
			exit(1);
		}

		return Int(number);
	}

	Int operator-(Int i2)
	{
		number = number - i2.number;

		if (number > 2147483648 || number < -2147483648LL)
		{
			cout << "\nInteger overflow!!!";
			exit(1);
		}

		return Int(number);
	}

	Int operator/(Int i2)
	{
		number = number / i2.number;

		if (number > 2147483648 || number < -2147483648LL)
		{
			cout << "\nInteger overflow!!!";
			exit(1);
		}

		return Int(number);
	}

	Int operator*(Int i2)
	{
		number = number * i2.number;

		if (number > 2147483648 || number < -2147483648LL)
		{
			cout << "\nInteger overflow!!!";
			exit(1);
		}

		return Int(number);
	}

	void display()
	{
		cout << "Number = " << number << endl;
	}
};

int main()
{
	Int a(2147483647);
	Int b(1024242);

	Int c;

	//c = a + b;
	//c.display();
	c = a - b;
	c.display();
	//c = a * b;
	//c.display();
	c = a / b;
	c.display();
}