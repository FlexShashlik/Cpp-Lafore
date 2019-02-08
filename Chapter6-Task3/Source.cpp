#include <iostream>

using namespace std;

class Time
{
private:
	int h, m, s;
public:
	Time() : h(0), m(0), s(0) {}
	Time(int h, int m, int s) : h(h), m(m), s(s) {}

	void AddTime(Time t1, Time t2)
	{
		s = (t1.s + t2.s) % 60;
		m = ((t1.m + t2.m) + (t1.s + t2.s) / 60) % 60;
		h = ((t1.h + t2.h) + (t1.m + t2.m) / 60) % 12;
	}

	void Display()const
	{
		cout << h << ":" << m << ":" << s << endl;
	}
};

int main()
{
	const Time t1(5, 59, 59), t2(4, 30, 30);
	Time t3;
	
	t3.AddTime(t1, t2);
	t3.Display();
}