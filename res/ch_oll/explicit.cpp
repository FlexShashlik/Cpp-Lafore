// explicit.cpp
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class Distance			// класс для английских мер длины
{
private:
	const float MTF; 	// метры к футам
	int feet;
	float inches;
public: 				// конструктор без аргументов
	Distance() : feet(0), inches(0.0), MTF(3.280833F)
	{ }					// ЯВНЫЙ (EXPLICIT) конструктор с одним аргументом
	explicit Distance(float meters) : MTF(3.280833F)
	{
		float fltfeet = MTF * meters;
		feet = int(fltfeet);
		inches = 12 * (fltfeet - feet);
	}
	void showdist()		// показать расстояние
	{ cout << feet << "\'-" << inches << '\"'; }
};
///////////////////////////////////////////////////////////
int main()
{
	system("chcp 1251 > nul");

	void fancyDist(Distance); 	// объявление
	Distance  dist1(2.35F); 	// конструктор с 1 аргументом
		// преобразовывает метры в Расстояние
	// Distance dist1 = 2.35F;    // ОШИБКА, если ctor является явным(EXPLICIT)
	cout << "\ndist1 = "; dist1.showdist();

	float mtrs = 3.0F;
	cout << "\nDist1 ";
	// fancyDist(mtrs);		// ОШИБКА, если ctor является явным(EXPLICIT)

	return 0;
}
///////////////////////////////////////////////////////////
void fancyDist(Distance d)
{
	cout << "(в футах и дюймах) = ";
	d.showdist();
	cout << endl;
}
