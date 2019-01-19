#include <iostream>

using namespace std;

const int LIMIT = 100;

class SafeArray 
{
private:
	int arr[LIMIT];

	int lowerLimit = 0, upperLimit = LIMIT;
public:
	int& operator[](int n)
	{
		if (n < lowerLimit || n >= upperLimit)
		{
			cout << "Wrong index!";
			exit(1);
		}
		
		return arr[n];
	}

	void SetLimits(int _lowerLimit, int _upperLimit) 
	{
		lowerLimit = _lowerLimit % LIMIT;
		upperLimit = _upperLimit % LIMIT;
	}
};

int main()
{
	SafeArray sa;

	sa.SetLimits(100, 175);

	for (int i = 0; i < LIMIT; i++)
	{
		sa[i] = i * 10;
		cout << "Elemenet " << i << " equals " << sa[i] << endl;
	}

	return 0;
}