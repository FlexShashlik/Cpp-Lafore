// ipers.cpp
// Чтение объекта из файла
#include <fstream>      // для файловых потоков
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class person            // класс person
{
protected:
	char name[80];      // Имя человека
	short age;          // его возраст
public:
	void showData()     // вывести данные
	{
		cout << "Имя: " << name << endl;
		cout << "Возраст: " << age << endl;
	}
};
///////////////////////////////////////////////////////////
int main()
{
	system("chcp 1251 > nul");

	person pers;        // переменная типа person

	// создать поток
	ifstream infile("PERSON.DAT", ios::binary);

	// чтение потока
	infile.read(reinterpret_cast<char*>(&pers), sizeof(pers)); 

	pers.showData();    // вывести данные

	return 0;
}
