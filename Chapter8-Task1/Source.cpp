#include <iostream>

using namespace std;

class Distance
{
private:
	int feet;
	float inches;
public:
	Distance() :feet(0), inches(0) { }
	Distance(int f, float i) : feet(f), inches(i) { }

	void getdist()
	{
		cout << "\nEnter feet: ";
		cin >> feet;
		cout << "Enter inches: ";
		cin >> inches;
	}

	void showdist()
	{
		cout << feet << "\'-" << inches << "\"";
	}

	
	Distance operator+(Distance d2) const;
	Distance operator-(Distance d2) const;
};

Distance Distance::operator+(Distance d2) const
{
	int f = feet + d2.feet;
	float i = inches + d2.inches;

	if (i >= 12)
	{
		i -= 12;
		f++;
	}

	return Distance(f, i);
}

Distance Distance::operator-(Distance d2) const
{
	int f = feet - d2.feet;
 
	float i;

	i = inches - d2.inches;

	if (d2.inches > inches)
	{
		f--;
		i += 12;
	}

	return Distance(f, i);
}

int main()
{
	Distance d1, d3, d4;
	d1.getdist();

	Distance d2(11, 6.25);

	d3 = d1 + d2;

	d4 = d1 + d2 + d3;

	cout << "d1 = "; d1.showdist(); cout << endl;
	cout << "d2 = "; d2.showdist(); cout << endl;
	cout << "d3 = "; d3.showdist(); cout << endl;
	cout << "d4 = "; d4.showdist(); cout << endl;

	Distance d5(15, 2), d6(5, 3);

	cout << "d5 - d6 = "; Distance(d5-d6).showdist(); cout << endl;
}