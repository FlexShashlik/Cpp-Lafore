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

class book : private publication
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

class tape : private publication
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
	publication p1;
	p1.putdata();
	p1.getdata();
	p1.putdata();

	book b1, b2;
	b1.getdata();
	b2.getdata();

	tape t1;
	t1.getdata();

	b1.putdata();
	b2.putdata();
	t1.putdata();
}