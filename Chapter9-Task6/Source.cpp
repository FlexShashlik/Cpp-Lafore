#include <iostream>

using namespace std;

const int LIMIT = 100;

class safearray
{
private:
	int arr[LIMIT];
public:
	int lowerLimit = 0, upperLimit = LIMIT;

	int& operator[](int n)
	{
		if (n < lowerLimit || n >= upperLimit)
		{
			cout << "\nWrong index!"; 
			exit(1);
		}
		return arr[n];
	}
};

class safehilo : public safearray
{
public:
	void SetLimits(int _ll, int _ul)
	{
		lowerLimit = _ll % LIMIT;
		upperLimit = _ul % LIMIT;
	}
};

int main()
{
	safehilo sa1;
	sa1.SetLimits(100, 250);

	for (int i = 0; i < LIMIT; i++)
	{
		sa1[i] = i * 10;
		cout << "Elemenet " << i << " equals " << sa1[i] << endl;
	}

	return 0;
}