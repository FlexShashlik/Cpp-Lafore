// if2.cpp
// использование нескольких операторов в теле цикла if
#include <iostream>
using namespace std;
int main()
{
	system("chcp 1251 > nul");

	int x;
	cout << "¬ведите число: ";
	cin >> x;
	if(x > 100)
	{
		cout << "„исло " << x;
		cout << " больше, чем 100\n";
	}
	return 0;
}
