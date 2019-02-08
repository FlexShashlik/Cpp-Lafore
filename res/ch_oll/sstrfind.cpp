// sstrfind.cpp
// поиск подстрок
#include <iostream>
#include <string>
using namespace std;
///////////////////////////////////////////////////////////
int main()
{
	system("chcp 1251 > nul");

	string s1 = "¬ лесу родилась елочка, в лесу она росла.";
	int n;

	n = s1.find("елочка");
	cout << "≈лочка найдена: " << n << endl;

	n = s1.find_first_of("умка");
	cout << "ѕервый из умка: " << n << endl;

	n = s1.find_first_not_of("абвгдјЅ¬√ƒ");
	cout << "ѕервый не из: " << n << endl;

	return 0;
}
