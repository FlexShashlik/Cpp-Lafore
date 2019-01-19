#include <iostream>
#include <conio.h>

using namespace std;

class TollBoth
{
private:
	unsigned int numberOfCars;
	double profit;
public:
	TollBoth() : numberOfCars(0), profit(0) {};

	void PayingCar()
	{
		numberOfCars++;
		profit += 0.5;
	}

	void NoPayCar()
	{
		numberOfCars++;
	}

	void Display()const
	{
		cout << "Number of cars: " << numberOfCars << "\n" <<
			"Profit: " << profit << "\n";
	}
};

int main()
{
	TollBoth tollBoth;
	int input = 0;

	while (input != 27)//27 - ESC
	{
		input = _getch();

		switch (input)
		{
			case 80://P
			case 112://p
				tollBoth.PayingCar();
				break;
			case 78://N
			case 110://n
				tollBoth.NoPayCar();
				break;
			default:
				break;
		}
	}

	tollBoth.Display();
}