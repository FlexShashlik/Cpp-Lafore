#include <iostream>

using namespace std;

int main()
{
	double dollarsAmount;

	cin >> dollarsAmount;

	cout 
		<< "In pounds: " << dollarsAmount / 1.487 << endl
		<< "In francs: " << dollarsAmount / 0.172 << endl
		<< "In marks: " << dollarsAmount / 0.584 << endl
		<< "In yens: " << dollarsAmount / 0.00955 << endl;
}