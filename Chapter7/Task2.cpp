#include <iostream>
#include <string>

using namespace std;

class employee
{
private:
	string	name;
	long	id;
public:
	void getdata()
	{
		cout << "Enter employee name: ";
		cin >> name;

		cout << "Enter employee id: ";
		cin >> id;
	}

	void putdata()
	{
		cout << "Name: " << name << endl << "Id: " << id << endl;
	}
};

int main()
{
	employee employeesArr[100];

	int employeesCount;

	cout << "Enter employees count: ";
	cin >> employeesCount;

	for (int i = 0; i < employeesCount; i++)
	{
		employeesArr[i].getdata();
	}

	cout << endl;

	for (int i = 0; i < employeesCount; i++)
	{
		employeesArr[i].putdata();
	}
}