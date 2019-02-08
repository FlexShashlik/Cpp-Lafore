#include <iostream>

using namespace std;

double power(double n, int p);

int main()
{
	double number;
	int p;

	cout << "Enter number: ";
	cin >> number;

	cout << "Enter power: ";
	cin >> p;

	cout << power(number, p);
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