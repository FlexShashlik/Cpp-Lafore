// sort.cpp
// сортирует массив целых чисел
#include <iostream>
#include <algorithm>
using namespace std;
// массив чисел
int arr[] = { 45, 2, 22, -17, 0, -30, 25, 55 };

int main()
{
	system("chcp 1251 > nul");

	sort(arr, arr + 8);        // сортировка

	for(int j = 0; j < 8; j++) // вывести отсортированный
		cout << arr[j] << ' '; // массив

	cout << endl;

	return 0;
}
