#include <iostream>

using namespace std;

int main()
{
	float decPounds, decFrac;

	int pounds;
	float shillings;

	const char J = 156;

	cout << "Decimal pounds: ";
	cin >> decPounds;

	pounds = static_cast<int>(decPounds);

	decFrac = decPounds - pounds;

	shillings = decFrac * 20;

	cout << "In old system: " << J << pounds << '.' << shillings;
}