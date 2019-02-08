// ichar.cpp
// Посимвольный файловый ввод
#include <fstream>               // для файловых функций
#include <iostream>
using namespace std;

int main()
{
	system("chcp 1251 > nul");

	char ch;                     // символ для считывания
	ifstream infile("TEST.TXT"); // входной файл
	while(infile)                // читать до EOF или ошибки
	{
		infile.get(ch);          // считать символ
		cout << ch;              // и вывести его
	}
	cout << endl;

	return 0;
}
