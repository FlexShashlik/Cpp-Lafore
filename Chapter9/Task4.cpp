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

	void putdata()const
	{
		cout << "\nTitle: " << title << "\nPrice: " << price;
	}

	void getdata()
	{
		cout << "\nEnter title: ";
		cin >> title;

		cout << "Enter price: ";
		cin >> price;
	}
};

class sales
{
private:
	enum { MONTH = 3 };
	float salesArr[MONTH];
public:
	void putdata()const
	{
		for (int i = 0; i < MONTH; i++)
		{
			cout << "\nProfit for " << i + 1 << " month - " << salesArr[i];
		}
	}

	void getdata()
	{
		for (int i = 0; i < MONTH; i++)
		{
			cout << "Enter profit for " << i + 1 << " month: ";
			cin >> salesArr[i];
		}
	}
};

class book : private publication, private sales
{
private:
	int pages;
public:
	void putdata()const
	{
		publication::putdata();
		cout << "\nPages: " << pages;
		sales::putdata();
	}

	void getdata()
	{
		publication::getdata();
		cout << "Enter pages: ";
		cin >> pages;
		sales::getdata();
	}
};

class tape : private publication, private sales
{
private:
	float duration;
public:
	void putdata()const
	{
		publication::putdata();
		cout << "\nDuration: " << duration;
		sales::putdata();
	}

	void getdata()
	{
		publication::getdata();
		cout << "Enter duration: ";
		cin >> duration;
		sales::getdata();
	}
};

class disk : private publication, private sales
{
private:
	int diskType;
public:
	void putdata()const
	{
		publication::putdata();
		string type = (diskType == 0) ? "CD" : "DVD";
		cout << "\nDisk Type: " << type;
		sales::putdata();
	}

	void getdata()
	{
		publication::getdata();

		char temp;
		cout << "Enter disk type (c or d): ";
		cin >> temp;

		diskType = (temp == 'c') ? 0 : 1;

		sales::getdata();
	}
};

int main()
{
	disk d;
	tape t;
	
	d.getdata();
	t.getdata();
	d.putdata();
	t.putdata();
}