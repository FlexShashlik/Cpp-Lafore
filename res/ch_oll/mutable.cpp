// mutable.cpp
#include <iostream>
#include <string>
using namespace std;
///////////////////////////////////////////////////////////
class scrollbar
{
private:
	int size;				// релевантный для константы
	mutable string owner;	// не релевантный для константы
public:
	scrollbar(int sz, string own) : size(sz), owner(own)
	{ }
	void setSize(int sz)	// изменения размера
	{ 
		size = sz;
	}
	void setOwner(string own) const // изменения владелеца
	{ 
		owner = own;
	}
	int getSize() const		// возвраты размера
	{ 
		return size; 
	}
	string getOwner() const	// возвраты владелеца
	{ 
		return owner;
	}
};
///////////////////////////////////////////////////////////
int main()
{
	system("chcp 1251 > nul");

	const scrollbar sbar(60, "Приложение 1");

	// sbar.setSize(100);			// не может быть изменен в объекте-константе
	sbar.setOwner("Приложение 2");	// может быть изменен даже если объект—константа

	cout << sbar.getSize() << ", " << sbar.getOwner() << endl;

	return 0;
}
