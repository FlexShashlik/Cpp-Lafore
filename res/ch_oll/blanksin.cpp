// blanksin.cpp
// ввод строки с пробелами
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
int main()
{
	system("chcp 1251 > nul");

	const int MAX = 80; // максимальная длина строки
	char str[MAX];      // сама строка

	cout << "\nВведите строку: ";
	cin.get(str, MAX);
	cout << "Вы ввели: " << str << endl;

	return 0;
}
