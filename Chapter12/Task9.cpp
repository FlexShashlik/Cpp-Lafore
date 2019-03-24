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

    friend istream& operator>>(istream&, Fraction&);
    friend ostream& operator<<(ostream&, Fraction&);

	Fraction operator+(Fraction);
	Fraction operator-(Fraction);
	Fraction operator*(Fraction);
	Fraction operator/(Fraction);

	bool operator==(Fraction f2);

	void lowTerms();
};

#pragma region funcs implementations
istream& operator>>(istream& s, Fraction& f)
{
    cout << "Enter numerator: ";
    cin >> f.num;
    cout << "Enter denumerator: ";
    cin >> f.den;
}

ostream& operator<<(ostream& s, Fraction& f)
{
    f.lowTerms();
    cout << f.num << "/" << f.den << endl;
}

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
#pragma endregion

int main()
{
	Fraction f1, f2, result;

	char action, confirmation;

	do
	{
		cin >> f1 >> action >> f2;

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

		cout << result;

		cout << "Repeat again (y/n)? ";
		cin >> confirmation;
	} while (confirmation == 'y');
	return 0;
}