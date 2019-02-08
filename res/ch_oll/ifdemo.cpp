// ifdemo.cpp
// применение оператора if
#include <iostream>
using namespace std;
int main()
{
	system("chcp 1251 > nul");

	int x;
	cout << "Введите число: ";
	cin >> x;
	if(x > 100)
		cout << "Это число больше, чем 100\n ";
	return 0;
}
