#include <iostream>
using namespace std;

class Array
{
private:
	int* ptr;
	int size;
public:
	Array() : ptr(0), size(0) {}

	Array(int s)
	{
		size = s;
		ptr = new int[s];
	}

	Array(Array &arr)
	{
		delete[] ptr;

		size = arr.size;
		ptr = new int[size];

		for (int j = 0; j < size; j++)
			*(ptr + j) = *(arr.ptr + j);
	}

	Array &operator= (Array &arr)
	{
		delete[] ptr;

		size = arr.size;
		ptr = new int[size];

		for (int j = 0; j < size; j++)
			*(ptr + j) = *(arr.ptr + j);

		return *this;
	}

	~Array()
	{
		delete[] ptr;
	}

	int& operator[](int j)
	{
		return *(ptr + j);
	}
};

int main()
{
	const int ASIZE = 10;
	Array arr(ASIZE);

	for (int j = 0; j < ASIZE; j++)
		arr[j] = j * j;

	for (int j = 0; j < ASIZE; j++)
		cout << arr[j] << ' ';

	cout << endl;

	Array arr2(arr);

	for (int j = 0; j < ASIZE; j++)
		cout << arr2[j] << ' ';

	cout << endl;

	Array arr3, arr4;
	arr4 = arr3 = arr;

	for (int j = 0; j < ASIZE; j++)
		cout << arr3[j] << ' ';

	cout << endl;

	for (int j = 0; j < ASIZE; j++)
		cout << arr4[j] << ' ';
}