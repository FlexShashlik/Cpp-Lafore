#include <iostream>

using namespace std;

class Fraction
{
private:
	float num;
	float den;

public:
	Fraction() : num(0), den(0) {};
	Fraction(int num, int den) : num(num), den(den) {};

	void getFraction()
	{
		cout << "Enter numerator: ";
		cin >> num;
		cout << "Enter denumerator: ";
		cin >> den;
	}

	void display()
	{
		lowTerms();
		cout << num << "/" << den << endl;
	}

	void fAdd(Fraction, Fraction);
	void fSub(Fraction, Fraction);
	void fMul(Fraction, Fraction);
	void fDiv(Fraction, Fraction);

	void lowTerms();
};

void Fraction::fAdd(Fraction f1, Fraction f2)
{
	num = f1.num * f2.den + f1.den * f2.num;
	den = f1.den * f2.den;
}

void Fraction::fSub(Fraction f1, Fraction f2)
{
	num = f1.num * f2.den - f1.den * f2.num;
	den = f1.den * f2.den;
}

void Fraction::fMul(Fraction f1, Fraction f2)
{
	num = f1.num * f2.num;
	den = f1.den * f2.den;
}

void Fraction::fDiv(Fraction f1, Fraction f2)
{
	num = f1.num * f2.den;
	den = f1.den * f2.num;
}

void Fraction::lowTerms()
{
	long tNum, tDen, temp, gcd;

	tNum = labs(num);
	tDen = labs(den);

	if (tDen == 0)
	{
		cout << "Invalid denumerator!";
		return;
	}
	else if (tNum == 0)
	{
		num = 0;
		den = 1;
		return;
	}

	while (tNum != 0)
	{
		if (tNum < tDen)
		{
			temp = tNum;
			tNum = tDen;
			tDen = temp;
		}

		tNum -= tDen;
	}

	gcd = tDen;
	num = num / gcd;
	den = den / gcd;
}

int main()
{
	Fraction f1, f2, result;

	char action, confirmation;

	do
	{
		f1.getFraction();
		
		cout << "Enter action: ";
		cin >> action;

		f2.getFraction();

		cout << "Result: ";

		switch (action)
		{
		case '+':
			result.fAdd(f1, f2);
			break;

		case '-':
			result.fSub(f1, f2);
			break;

		case '*':
			result.fMul(f1, f2);
			break;

		case '/':
			result.fDiv(f1, f2);
			break;
		}
		
		result.display();

		cout << "Repeat again (y/n)? ";
		cin >> confirmation;
	} while (confirmation == 'y');
	return 0;
}

