#include <iostream>

using namespace std;

const int LENGTH = 10;

float fmemory[LENGTH];
int pmemory[LENGTH];

int fmem_top = 0, pmem_top = 0;

class Float
{
private:
	int addr = -1;
public:
	Float(float val)
	{
		*(fmemory+fmem_top) = val;
		addr = fmem_top++;
	}

	int operator&()
	{
		return addr;
	}
};

class PtrFloat
{
private:
	int addr = -1;
public:
	PtrFloat(int val)
	{
		*(pmemory+pmem_top) = val;
		addr = pmem_top++;
	}
	float& operator*()
	{
		return *(fmemory+*(pmemory+addr));
	}
};

int main()
{
	Float var1 = 1.234;
	Float var2 = 5.678;

	PtrFloat ptr1 = &var1;
	PtrFloat ptr2 = &var2;

	cout << "*ptr1 = " << *ptr1 << endl;
	cout << "*ptr2 = " << *ptr2 << endl;
	
	cout << endl;

	*ptr1 = 7.123;
	*ptr2 = 8.456;

	cout << "*ptr1 = " << *ptr1 << endl;
	cout << "*ptr2 = " << *ptr2 << endl;
}