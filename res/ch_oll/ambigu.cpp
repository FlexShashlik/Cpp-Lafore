// ambigu.cpp
// демонстрация неопределенности при множественном наследовании
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class A
{
public:
	void show() { cout << "Класс A\n"; }
};
class B
{
public:
	void show() { cout << "Класс B\n"; }
};
class C : public A, public B
{
};
///////////////////////////////////////////////////////////
int main()
{
	system("chcp 1251 > nul");

	C objC;         // объект класса C
	// objC.show(); // так делать нельзя - программа не скомпилируется
	objC.A::show(); // так можно
	objC.B::show(); // так можно

	return 0;
}
