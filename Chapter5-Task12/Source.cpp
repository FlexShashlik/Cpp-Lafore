#include <iostream>

using namespace std;
 
struct Fraction
{
	float num;
	float den;
};

Fraction fAdd(Fraction, Fraction);
Fraction fsub(Fraction, Fraction);
Fraction fmul(Fraction, Fraction);
Fraction fdiv(Fraction, Fraction);

int main()
{
	Fraction f1, f2, result;

	char action, confirmation, dummyChar;

	do
	{
		cout << "Enter two fractions: ";

		cin >> f1.num >> dummyChar >> f1.den >> action >> f2.num >> dummyChar >> f2.den;

		cout << "Result: ";

		switch (action)
		{
		case '+':
			result = fAdd(f1, f2);
			break;

		case '-':
			result = fsub(f1, f2);
			break;

		case '*':
			result = fmul(f1, f2);
			break;

		case '/':
			result = fdiv(f1, f2);
			break;
		}
		cout << result.num << "/" << result.den << endl;

		cout << "Repeat again (y/n)? ";
		cin >> confirmation;
	} while (confirmation == 'y');
	return 0;
}

Fraction fAdd(Fraction f1, Fraction f2)
{
	Fraction result;

	result.num = f1.num * f2.den + f1.den * f2.num;
	result.den = f1.den * f2.den;

	return result;
}

Fraction fsub(Fraction f1, Fraction f2)
{
	Fraction result;

	result.num = f1.num * f2.den - f1.den * f2.num;
	result.den = f1.den * f2.den;

	return result;
}

Fraction fmul(Fraction f1, Fraction f2)
{
	Fraction result;

	result.num = f1.num * f2.num;
	result.den = f1.den * f2.den;

	return result;
}

Fraction fdiv(Fraction f1, Fraction f2)
{
	Fraction result;

	result.num = f1.num * f2.den;
	result.den = f1.den * f2.num;

	return result;
}