#include <iostream>

using namespace std;

const int MAX = 80;

void reversit(char str[MAX])
{
	for (int i = strlen(str) - 1; i >= 0; i--)
	{
		cout << str[i];
	}
}

int main()
{
	//system("chcp 1251");

	char str[MAX];

	cin.get(str, MAX);

	reversit(str);
}