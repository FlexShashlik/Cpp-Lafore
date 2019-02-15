#include <iostream>
using namespace std;
const int DAYS = 7;

void bsort(char** ptr)
{
	void order(char**, char**);

	for (int i = 0; i < DAYS - 1; i++)
		for (int j = i + 1; j < DAYS; j++)
			order(ptr + i, ptr + j);
}

void order(char** str1, char** str2)
{
	if (strcmp(*str1, *str2) > 0)
	{
		char* tempptr = *str1;
		*str1 = *str2;
		*str2 = tempptr;
	}
}

int main()
{
	char* arrptrs[DAYS] = { _strdup("Sunday"), _strdup("Monday"), _strdup("Tuesday"), _strdup("Wednesday"), _strdup("Thursday"), _strdup("Friday"), _strdup("Saturday") };

	for (int i = 0; i < DAYS; i++)
		cout << *(arrptrs + i) << endl;

	cout << "Sorting..." << endl;

	bsort(arrptrs);

	for (int i = 0; i < DAYS; i++)
		cout << *(arrptrs + i) << endl;

	return 0;
}