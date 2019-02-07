#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	unsigned long n;

	cout << "Enter a number: ";
	cin >> n;

	for (int i = 1; i <= 200; i++)
	{
		cout << setw(5) << i * n;
		if (i % 10 == 0) 
		{
			cout << endl;
		}
	}

	return 0;
}