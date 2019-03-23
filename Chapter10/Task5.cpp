#include <iostream>

using namespace std;

const int LENGTH = 5;

void addarrays(float* arr1, float* arr2, float* arrsum);

int main()
{
	float arr1[LENGTH] = { 2.6, 35, 7.4, 1.5, 8.72 };
	float arr2[LENGTH] = { 1.4, 2, 5.6, 1.5, 1.28 };
	float arr3[LENGTH];

	addarrays(arr1, arr2, arr3);

	for (int i = 0; i < LENGTH; i++)
	{
		cout << *(arr3 + i) << endl;
	}
}

void addarrays(float* arr1, float* arr2, float* arrsum)
{
	for (int i = 0; i < LENGTH; i++)
	{
		*(arrsum + i) = *(arr1 + i) + *(arr2 + i);
	}
}