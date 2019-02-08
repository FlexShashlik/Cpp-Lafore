// comline.cpp
// ƒемонстраци€ работы с аргументами командной строки
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	system("chcp 1251 > nul");

	cout << "\nargc = " << argc << endl;     // число аргументов 

	for(int j = 0; j < argc; j++)            // вывести аргументы
		cout << "јргумент " << j << " = " << argv[j] << endl;

	return 0;
}
