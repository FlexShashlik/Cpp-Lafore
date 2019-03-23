#include <iostream>

using namespace std;

int main()
{
	struct fraction 
	{
		float numerator;
		float denominator;
	};

	fraction f1, f2, result;

	char action, confirmation, dummyChar;

	do
	{
		cout << "Enter two fractions: ";

		cin >> f1.numerator >> dummyChar >> f1.denominator >> action >> f2.numerator >> dummyChar >> f2.denominator;

		cout << "Result: ";

		switch (action)
		{
		case '+':
			result.numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator;
			result.denominator = f1.denominator * f2.denominator;
			break;

		case '-':
			result.numerator = f1.numerator * f2.denominator - f1.denominator * f2.numerator;
			result.denominator = f1.denominator * f2.denominator;
			break;

		case '*':
			result.numerator = f1.numerator * f2.numerator;
			result.denominator = f1.denominator * f2.denominator;
			break;

		case '/':
			result.numerator = f1.numerator * f2.denominator;
			result.denominator = f1.denominator * f2.numerator;
			break;
		}
		cout << result.numerator << "/" << result.denominator << endl;

		cout << "Repeat again (y/n)? ";
		cin >> confirmation;
	} while (confirmation == 'y');
	return 0;
}