#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d;
	char dummyChar;

	cout << "Enter first fraction: ";
	cin >> a >> dummyChar >> b;

	cout << "Enter second fraction: ";
	cin >> c >> dummyChar >> d;

	cout << "Sum = " << (a * d + b * c) << "/" << b * d;
}