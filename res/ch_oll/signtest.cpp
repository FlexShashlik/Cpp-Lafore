// signtest.cpp
// работа со знаковыми / беззнаковыми переменными
#include <iostream>
using namespace std;

int main()
{
	system("chcp 1251 > nul");

	int signedVar = 1500000000;				 // знакова€ переменна€
	unsigned int unsignVar = 1500000000;     // беззнакова€ переменна€

	signedVar = (signedVar * 2) / 3;         // выход за границы диапазона
	unsignVar = (unsignVar * 2) / 3;         // вычислени€ внутри диапазона

	cout << "«накова€ переменна€ равна "    << signedVar << endl; // ошибка
	cout << "Ѕеззнакова€ переменна€ равна " << unsignVar << endl; // правильно

	return 0;
}