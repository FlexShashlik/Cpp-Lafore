#include <iostream>

using namespace std;

const int LEN = 80;

class employee
{
private:
	char name[LEN];
	unsigned long number;
public:
	void getdata()
	{
		cout << "\nEnter name: ";
		cin >> name;
		cout << "Enter number: ";
		cin >> number;
	}

	void putdata()const
	{
		cout << "\nName: " << name;
		cout << "\nNumber: " << number;
	}
};

class employee2 : public employee
{
private:
	double compenstation;
	enum period { HOUR, WEEK, MONTH };
};

class manager : public employee2
{
private:
	char title[LEN];
	double dues;
public:
	void getdata()
	{
		employee::getdata();
		cout << "Enter position: "; cin >> title;
		cout << "Enter dues: "; cin >> dues;
	}
	void putdata() const
	{
		employee::putdata();
		cout << "\nPosition: " << title;
		cout << "\nDues: " << dues;
	}
};

class scientist : public employee2
{
private:
	int pubs;
public:
	void getdata()
	{
		employee::getdata();
		cout << "Enter count of publications: "; cin >> pubs;
	}
	void putdata() const
	{
		employee::putdata();
		cout << "\nCount of publications: " << pubs;
	}
};

class laborer : public employee2
{
};

int main()
{
	manager m1, m2;
	scientist s1;
	laborer l1;

	m1.getdata();
	m2.getdata();

	s1.getdata();

	l1.getdata();

	m1.putdata();
	m2.putdata();

	s1.putdata();

	l1.putdata();
}