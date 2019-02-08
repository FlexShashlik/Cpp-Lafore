// setrange.cpp
// Тестирование работы с диапазонами во множестве.
#pragma warning (disable:4786) // для работы с множествами
							   // (только для компиляторов Microsoft)
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	system("chcp 1251 > nul");

	// множество объектов string
	set<string, less<string> > organic;

	// итератор множества
	set<string, less<string> >::iterator iter;

	// вставка компонентов класса organic
	organic.insert("Curine");   
	organic.insert("Xanthine");
	organic.insert("Curarine");
	organic.insert("Melamine");
	organic.insert("Cyanimide");
	organic.insert("Phenol");
	organic.insert("Aphrodine");
	organic.insert("Imidazole");
	organic.insert("Cinchonine");
	organic.insert("Palmitamide");
	organic.insert("Cyanimide");

	iter = organic.begin();     // вывод множества
	while(iter != organic.end())
		cout << *iter++ << '\n';

	string lower, upper;        // вывод значений из диапазона
	cout << "\nВведите диапазон (например, C Czz): ";
	cin >> lower >> upper;
	iter = organic.lower_bound(lower);
	while(iter != organic.upper_bound(upper))
		cout << *iter++ << '\n';

	return 0;
}
