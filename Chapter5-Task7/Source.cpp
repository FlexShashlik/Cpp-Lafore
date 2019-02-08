#include <iostream>

using namespace std;

double	power(double n, int p);
char	power(char n, int p);
int		power(int n, int p);
long	power(long n, int p);
float	power(float n, int p);

int main()
{
	double	dNumber;
	char	cNumber;
	int		iNumber;
	long	lNumber;
	float	fNumber;

	int p;

	cout << "Enter double number: ";
	cin >> dNumber;

	cout << "Enter char number: ";
	cin >> cNumber;

	cout << "Enter int number: ";
	cin >> iNumber;

	cout << "Enter long number: ";
	cin >> lNumber;

	cout << "Enter float number: ";
	cin >> fNumber;

	cout << "Enter power: ";
	cin >> p;

	cout << power(dNumber, p) << endl;
	cout << power(cNumber, p) << endl;
	cout << power(iNumber, p) << endl;
	cout << power(lNumber, p) << endl;
	cout << power(fNumber, p) << endl;
}

double power(double n, int p)
{
	double answer = 1;

	for (int i = 0; i < p; i++)
	{
		answer *= n;
	}

	return answer;
}

char power(char n, int p)
{
	char answer = 1;

	for (int i = 0; i < p; i++)
	{
		answer *= n;
	}

	return answer;
}

int power(int n, int p)
{
	int answer = 1;

	for (int i = 0; i < p; i++)
	{
		answer *= n;
	}

	return answer;
}

long power(long n, int p)
{
	long answer = 1;

	for (int i = 0; i < p; i++)
	{
		answer *= n;
	}

	return answer;
}

float power(float n, int p)
{
	float answer = 1;

	for (int i = 0; i < p; i++)
	{
		answer *= n;
	}

	return answer;
}