//fahren.cpp 
//применение cin и \n 
#include <iostream> 
using namespace std;
int main() 
{
	system("chcp 1251 > nul");

	int ftemp; // температура по Фаренгейту
	cout << "Введите температуру по Фаренгейту: ";
	cin >> ftemp;
	int ctemp = (ftemp-32)*5 / 9;
	cout << "Температура no Цельсию равна " << ctemp << '\n';
	return 0;
}
