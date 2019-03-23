#include <iostream>

using namespace std;

void reflexion();

int main()
{
	for (int i = 0; i < 10; i++)
	{
		reflexion();
	}
}

void reflexion()
{
	static int invokeCounts = 0;

	cout << ++invokeCounts << endl;
}