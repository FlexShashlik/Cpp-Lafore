#include <iostream>

using namespace std;

template <class T>
class Fraction
{
private:
	T num;
	T den;

public:
	Fraction() : num(0), den(0) {};
	Fraction(T num, T den) : num(num), den(den) {};

	void getFraction()
	{
        float fnum, fden;

		cout << "Enter numerator: ";
		cin >> fnum;
		cout << "Enter denumerator: ";
		cin >> fden;

        num = (T)fnum;
        den = (T)fden;
	}

	void display()
	{
		lowTerms();
		cout << (float)num << "/" << (float)den << endl;
	}

	Fraction operator+(Fraction f2);
	Fraction operator-(Fraction f2);
	Fraction operator*(Fraction f2);
	Fraction operator/(Fraction f2);

	bool operator==(Fraction f2);

	void lowTerms();
};

template <class T>
Fraction<T> Fraction<T>::operator+(Fraction f2)
{
	num = num * f2.den + den * f2.num;
	den = den * f2.den;

	return Fraction(num, den);
}

template <class T>
Fraction<T> Fraction<T>::operator-(Fraction f2)
{
	num = num * f2.den - den * f2.num;
	den = den * f2.den;

	return Fraction(num, den);
}

template <class T>
Fraction<T> Fraction<T>::operator*(Fraction f2)
{
	num = num * f2.num;
	den = den * f2.den;

	return Fraction(num, den);
}

template <class T>
Fraction<T> Fraction<T>::operator/(Fraction f2)
{
	num = num * f2.den;
	den = den * f2.num;

	return Fraction(num, den);
}

template <class T>
bool Fraction<T>::operator==(Fraction f2) 
{
	return num == f2.num && den == f2.den ? true : false;
}

template <class T>
void Fraction<T>::lowTerms()
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
	Fraction<char> f1, f2, result;

	char action, confirmation;

	do
	{
		f1.getFraction();

		cout << "Enter action: ";
		cin >> action;

		f2.getFraction();

		if (f1 == Fraction<char>(0, 1) || f2 == Fraction<char>(0, 1))
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