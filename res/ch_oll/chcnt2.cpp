// chcnt2.cpp
// подсчет числа слов и символов в строке
#include <iostream>
using namespace std;
#include <conio.h>					 // для getche()

int main()
{
	system("chcp 1251 > nul");

	int chcount = 0;
	int wdcount = 1;				 // пробел между двумя словами
	char ch;

	while((ch = getche()) != '\r')	 // цикл, пока не нажата клавиша Enter
	{
		if(ch == ' ')                // если введен пробел,
			wdcount++;               // инкрементировать счетчик слов
		else                         // иначе
			chcount++;               // инкрементировать число символов
	}								 // вывод результатов
	cout << "\nСлов: " << wdcount << endl;
	cout << "Букв: " << chcount << endl;

	return 0;
}
