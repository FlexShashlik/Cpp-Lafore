// sstrio.cpp
// ввод/вывод для класса string
#include <iostream>
#include <string>								// для строк
using namespace std;

///////////////////////////////////////////////////////////
int main()
{
	system("chcp 1251 > nul");

	string full_name, nickname, address;		// объект строкового типа
	string greeting("Здравствуйте, ");			// объект строкового типа

	cout << "Введите Ваше имя: ";
	getline(cin, full_name);					// чтение, включая пробелы или несколько строк

	cout << "Ваше имя: " << full_name << endl;
	cout << "Введите Ваш псевдоним: ";
	cin >> nickname;							// ввод объекта в виде строки

	greeting += nickname;						// добавление имени к приветствию
	cout << greeting << endl;					// вывод 

	cout << "Введите Ваш адрес в несколько строк\n";
	cout << "Окончание ввода символ '$'\n";
	getline(cin, address, '$');					// чтение, включая пробелы или несколько строк
	cout << "Ваш адрес: " << address << endl;	// вывод 

	return 0;
}