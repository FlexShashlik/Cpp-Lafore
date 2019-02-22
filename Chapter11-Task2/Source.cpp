#include <iostream>
#include <string>

using namespace std;

class publication
{
private:
	string title;
	float price;
public:
	publication() : title("NaN"), price(0) {}

	virtual void putdata()const
	{
		cout << "\nTitle: " << title << "\nPrice: " << price;
	}

	virtual void getdata()
	{
		cout << "\nEnter title: ";
		cin >> title;

		cout << "Enter price: ";
		cin >> price;
	}
};

class book : public publication
{
private:
	int pages;
public:
	void putdata()const
	{
		publication::putdata();
		cout << "\nPages: " << pages;
	}

	void getdata()
	{
		publication::getdata();
		cout << "Enter pages: ";
		cin >> pages;
	}
};

class tape : public publication
{
private:
	float duration;
public:
	void putdata()const
	{
		publication::putdata();
		cout << "\nDuration: " << duration;
	}

	void getdata()
	{
		publication::getdata();
		cout << "Enter duration: ";
		cin >> duration;
	}
};

int main()
{
	publication* parr[3];
	parr[0] = new publication;
	parr[1] = new book;
	parr[2] = new tape;

	for (int i = 0; i < 3; i++)
		parr[i]->getdata();

	for (int i = 0; i < 3; i++)
		parr[i]->putdata();
}