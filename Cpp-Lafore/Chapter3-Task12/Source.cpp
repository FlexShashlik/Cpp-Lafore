#include <iostream>

using namespace std;

int main()
{
	float a, b, c, d;
	char action, confirmation, dummyChar;

	float resultA = 0, resultB = 0;

	do
	{
		cout << "Enter two fractions: ";

		cin >> a >> dummyChar >> b >> action >> c >> dummyChar >> d;

		cout << "Result: ";

		switch (action)
		{
		case '+':
			resultA = a*d + b*c;
			resultB = b * d;
			break;

		case '-':
			resultA = a*d - b*c;
			resultB = b * d;
			break;

		case '*':
			resultA = a * c;
			resultB = b * d;
			break;

		case '/':
			resultA = a * d;
			resultB = b * c;
			break;
		}
		cout << resultA << "/"<< resultB << endl;

		cout << "Repeat again (y/n)? ";
		cin >> confirmation;
	} while (confirmation == 'y');
	return 0;
}