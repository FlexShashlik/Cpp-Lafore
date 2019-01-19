#include <iostream>

using namespace std;

int main()
{
	struct fraction
	{
		int numerator;
		int denominator;
	};

	fraction f1, f2, sum;

	char dummyChar;

	cout << "Enter first fraction: ";
	cin >> f1.numerator >> dummyChar >> f1.denominator;

	cout << "Enter second fraction: ";
	cin >> f2.numerator >> dummyChar >> f2.denominator;

	sum.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
	sum.denominator = f1.denominator * f2.denominator;

	cout << "Sum = " << sum.numerator << "/" << sum.denominator;
}