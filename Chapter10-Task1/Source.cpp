#include <iostream>

using namespace std;

int main()
{
	const int COUNT = 10;
	float arr[COUNT];

	float sum = 0;

	for (int i = 0; i < COUNT; i++)
	{
		cout << "Enter " << i + 1 << " element: ";
		cin >> *(arr + i);
	}

	for (int i = 0; i < COUNT; i++)
		sum += *(arr + i);
	
	cout << "Average = " << sum / COUNT;
}