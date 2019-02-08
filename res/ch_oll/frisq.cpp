// frisq.cpp
// Дружественная для Distance функция square()
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class Distance                        // Класс английских длин
{
private:
	int feet;
	float inches; 
public:                             // Класс английских длин
	Distance() : feet(0), inches(0.0) // конструктор (без аргументов)
	{  }
	// конструктор (2 аргумента)
	Distance(int ft, float in) : feet(ft), inches(in)  
	{  }
	void showdist()                   // вывести расстояние
	{ 
		cout << feet << "\'-" << inches << '\"'; 
	}
	friend float square(Distance);    // дружественная ф-ция
};
//---------------------------------------------------------
float square(Distance d)                 // вернуть квадрат
{                                        // расстояния
	float fltfeet = d.feet + d.inches / 12;// конвертировать в float 
	float feetsqrd = fltfeet * fltfeet;    // вычислить квадрат
	return feetsqrd;                       // вернуть квадратные футы
}
///////////////////////////////////////////////////////////
int main()
{
	system("chcp 1251 > nul");

	Distance dist(3, 6.0);// конструктор с двумя аргументами (3'-6")
	float sqft;

	sqft = square(dist);                   // вернуть квадрат dist
	// Вывести расстояние и его квадрат
	cout << "\nРасстояние = "; dist.showdist();
	cout << "\nКвадрат расст. = " << sqft << " square feet\n";

	return 0;
}
