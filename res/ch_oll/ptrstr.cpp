// ptrstr.cpp
// показ строки, определенной через указатель
#include <iostream>
using namespace std;

int main()
{
	system("chcp 1251 > nul");

	void dispstr(char*);  // прототип функции
	char str[] = "У бездельников всегда есть свободное время.";

	dispstr(str);

	return 0;
}
///////////////////////////////////////////////////////////
void dispstr(char* ps)
{
	while(*ps)            // пока не встретим конец строки
		cout << *ps++;    // будем посимвольно выводить ее на экран
	cout << endl;
}
