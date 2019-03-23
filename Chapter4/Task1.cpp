#include <iostream>

using namespace std;

struct phone
{
	int city;
	int exchange;
	int number;
};

void printPhone(phone p)
{
	cout << "(" << p.city << ") " << p.exchange << "-" << p.number << endl;
}

int main()
{
	phone myPhone = { 212, 767, 8900 }, yourPhone;

	cout << "Enter your phone number:" << endl;
	cin >> yourPhone.city >> yourPhone.exchange >> yourPhone.number;

	cout << "My phone is ";
	printPhone(myPhone);

	cout << "Your phone is ";
	printPhone(yourPhone);
}