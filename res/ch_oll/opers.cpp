// opers.cpp
// —охранение объекта в файле
#include <fstream>        // дл€ файловых потоков
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class person              // класс person
{
protected:
	char name[80];        // им€ человека
	short age;            // возраст
public:
	void getdata()        // получить данные о человеке
	{
		cout << "¬ведите им€: "; cin >> name;
		cout << "¬ведите возраст: "; cin >> age;
	}
};
///////////////////////////////////////////////////////////
int main()
{
	system("chcp 1251 > nul");

	person pers;          // создать объект
	pers.getdata();       // получить данные

	// создать объект ofstream
	ofstream outfile("PERSON.DAT", ios::binary);

	// записать в него
	outfile.write(reinterpret_cast<char*>(&pers), sizeof(pers));

	return 0;
}
