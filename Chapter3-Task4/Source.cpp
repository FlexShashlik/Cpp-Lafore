#include <iostream>

using namespace std;

int main()
{
	float a, b, c, d;
	char action, confirmation;

	float result;

	do
	{
		cout << "Enter first operand, operation and second operand: ";

		cin >> a >> action >> b;

		cout << "Result: ";

		switch (action)
		{
			case '+':
				result = a + b;
				break;

			case '-':
				result = a - b;
				break;

			case '*':
				result = a * b;
				break;

			case '/':
				result = a / b;
				break;
		}

		cout << result << endl;

		cout << "Repeat again (y/n)? ";
		cin >> confirmation;
	} while (confirmation == 'y');
	return 0;
}