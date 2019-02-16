#include <iostream>

using namespace std;

int compstr(char* s1, char * s2)
{
	int length = strlen(s1) < strlen(s2) ? strlen(s1) : strlen(s2);

	for (int i = 0; i < length; i++)
	{
		if (*(s1 + i) > *(s2 + i))
			return 1;
		else if (*(s1 + i) < *(s2 + i))
			return -1;
	}

	return 0;
}

int main()
{
	char* s1 = _strdup("Sevada");
	char* s2 = _strdup("Sevada");

	cout << compstr(s1, s2) << endl;
	cout << strcmp(s1, s2) << endl;

	s2 = _strdup("Sevadb");

	cout << compstr(s1, s2) << endl;
	cout << strcmp(s1, s2) << endl;

	s1 = _strdup("Sevadb");
	s2 = _strdup("Sevada");

	cout << compstr(s1, s2) << endl;
	cout << strcmp(s1, s2) << endl;
}