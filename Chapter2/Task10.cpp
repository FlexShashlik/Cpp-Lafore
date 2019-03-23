#include <iostream>

using namespace std;

int main()
{
	float oldPounds, oldShillings, oldPennies;

	const char J = 156;

	cout << "Pounds: ";
	cin >> oldPounds;

	cout << "Shillings: ";
	cin >> oldShillings;

	cout << "Pennies: ";
	cin >> oldPennies;

	oldShillings += oldPennies / 12;

	cout << "Decimal pounds: " << J << oldPounds + oldShillings / 20;
}