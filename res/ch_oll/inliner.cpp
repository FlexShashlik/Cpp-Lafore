// inliner.cpp
// применение встроенных функций
#include <iostream>
using namespace std;

// функци€ lbstokg()
// переводит фунты в килограммы
inline float lbstokg(float pounds)
{
	return 0.453592 * pounds;
}
//--------------------------------------------------------
int main()
{
	system("chcp 1251 > nul");

	float lbs;
	cout << "\n¬ведите вес в фунтах: ";
	cin >> lbs;
	cout << " " << lbstokg(lbs) << endl;

	return 0;
}
