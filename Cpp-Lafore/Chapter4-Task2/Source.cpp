#include <iostream>

using namespace std;

int main()
{
	struct point
	{
		int x;
		int y;
	};

	point p1, p2;

	cout << "Enter p1: ";
	cin >> p1.x >> p1.y;

	cout << "Enter p2: ";
	cin >> p2.x >> p2.y;

	cout << "Sum of p1 and p2 equals " << p1.x + p2.x << ", " << p1.y + p2.y << endl;
}