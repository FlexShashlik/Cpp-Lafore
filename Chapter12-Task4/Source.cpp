#include <iostream>
#include <fstream>

using namespace std;

class Employee
{
private:
	char firstName[40];
	char middleName[40];
	char lastName[40];
	unsigned long id;
public:
	void getData()
	{
		cout << "Enter first name: ";
		cin >> firstName;
		cout << "Enter middle name: ";
		cin >> middleName;
		cout << "Enter last name: ";
		cin >> lastName;
		cout << "Enter id: ";
		cin >> id;
	}

	friend ostream& operator << (ostream& s, Employee e)
	{
		s << "\n\nFirst name: " << e.firstName << '\n'
			<< "Middle name: " << e.middleName << '\n'
			<< "Last name: " << e.lastName << '\n' 
			<< "Id: "<< e.id;
		return s;
	}
};

int main()
{
	ofstream outputFile("outputemp.dat");

	if (!outputFile)
	{
		cout << "Unable to open ofstream" << endl;
		return -1;
	}
	
	char ans;

	do 
	{
		Employee e;
		e.getData();

		outputFile << e;

		cout << "Continue y/n? ";
		cin >> ans;
	} while (ans == 'y');

	outputFile.close();

	ifstream inputFile("outputemp.dat");

	if (!inputFile)
	{
		cout << "Unable to open ifstream" << endl;
		return -1;
	}

	cout << inputFile.rdbuf();
}
