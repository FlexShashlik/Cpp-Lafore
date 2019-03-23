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

	Fraction operator+(Fraction f2);
	Fraction operator-(Fraction f2);
	Fraction operator*(Fraction f2);
	Fraction operator/(Fraction f2);

	bool operator==(Fraction f2);

	void lowTerms();
};

Fraction Fraction::operator+(Fraction f2)
{
	num = num * f2.den + den * f2.num;
	den = den * f2.den;

	return Fraction(num, den);
}

Fraction Fraction::operator-(Fraction f2)
{
	num = num * f2.den - den * f2.num;
	den = den * f2.den;

	return Fraction(num, den);
}

Fraction Fraction::operator*(Fraction f2)
{
	num = num * f2.num;
	den = den * f2.den;

	return Fraction(num, den);
}

Fraction Fraction::operator/(Fraction f2)
{
	num = num * f2.den;
	den = den * f2.num;

	return Fraction(num, den);
}

bool Fraction::operator==(Fraction f2) 
{
	return num == f2.num && den == f2.den ? true : false;
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

		if (f1 == Fraction(0, 1) || f2 == Fraction(0, 1))
		{
			return 1;
		}

		cout << "Result: ";

		switch (action)
		{
		case '+':
			result = f1 + f2;
			break;

		case '-':
			result = f1 - f2;
			break;

		case '*':
			result = f1 * f2;
			break;

		case '/':
			result = f1 / f2;
			break;
		}

		result.display();

		cout << "Repeat again (y/n)? ";
		cin >> confirmation;
	} while (confirmation == 'y');
	return 0;
}