#include <iostream>
using namespace std;

class Counter
{
protected:
	unsigned int count;
public:
	Counter() : count()
	{ }
	Counter(int c) : count(c)
	{ }
	unsigned int get_count() const
	{
		return count;
	}
	Counter operator++()
	{
		return Counter(++count);
	}
};

class CountDn : public Counter
{
public:
	CountDn() : Counter()
	{ }
	CountDn(int c) : Counter(c)
	{ }
	CountDn operator--()             
	{
		return CountDn(--count);
	}
};

class CountPost : public Counter
{
public:
	CountPost() : Counter()
	{ }
	CountPost(int c) : Counter(c)
	{ }
	CountPost operator--()
	{
		return CountPost(--count);
	}
	CountPost operator++()
	{
		return CountPost(++count);
	}
	CountPost operator--(int)
	{
		return CountPost(count--);
	}
	CountPost operator++(int)
	{
		return CountPost(count++);
	}
};

int main()
{
	CountDn c1;
	CountDn c2(100);

	cout << "\nc1 = " << c1.get_count();
	cout << "\nc2 = " << c2.get_count();

	++c1; ++c1; ++c1;
	cout << "\nc1 = " << c1.get_count();

	--c2; --c2;
	cout << "c2 = " << c2.get_count();

	CountDn c3 = --c2;
	cout << "\nc3 = " << c3.get_count();

	CountPost cp(100), cp1(1);

	cout << "\n" << cp++.get_count() << endl;
	cout << cp.get_count();
	cp1 = --cp;
	cout << "\n" << cp1.get_count() << endl;
}