#include <iostream>

using namespace std;

class Time
{
private:
	int h, m, s;
public:
	Time() : h(0), m(0), s(0) {}
	Time(int h, int m, int s) : h(h), m(m), s(s) {}

	Time operator+(Time t2)
	{
		Time temp;
		temp.s = (s + t2.s) % 60;
		temp.m = ((m + t2.m) + (s + t2.s) / 60) % 60;
		temp.h = ((h + t2.h) + (m + t2.m) / 60) % 12;

		return temp;
	}

	Time operator++()
	{
		return Time(++h % 12, m, s);
	}

	Time operator++(int)
	{
		return Time(h++ % 12, m, s);
	}

	Time operator--()
	{
		return Time(--h % 12, m, s);
	}

	Time operator--(int)
	{
		return Time(h-- % 12, m, s);
	}

	void Display()const
	{
		cout << h << ":" << m << ":" << s << endl;
	}
};

int main()
{
	Time t1(5, 59, 59), t2(4, 30, 30);
	Time t3;

	t3 = t1 + t2;
	t3.Display();
	t3++;
	t3.Display();

	t1 = ++t2;

	t1.Display();
	t2.Display();

	t1 = t2--;

	t1.Display();
	t2.Display();
}