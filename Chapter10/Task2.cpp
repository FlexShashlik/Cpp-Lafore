#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

class String
{
private:
	char* str;
public:
	String(const char* s)
	{
		int length = strlen(s);
		str = new char[length + 1];
		strcpy(str, s);
	}
	~String()
	{
		cout << "Delete string\n";
		delete[] str;
	}
	void upit()
	{
		int length = strlen(str) + 1;
		char* tempstr = new char[length];

		for (int i = 0; i < length; i++)
		{
			if (islower(*(str + i)))
				*(tempstr + i) = toupper(*(str + i));
			else
				*(tempstr + i) = *(str + i);
		}

		*(tempstr + length) = '\0';

		strcpy(str, tempstr);
	}
	void display()
	{
		cout << str << endl;
	}
};

int main()
{
	String s1 = "This is just an example.";
	cout << "s1 = ";
	s1.display();
	
	s1.upit();

	cout << "s1 = ";
	s1.display();

	return 0;
}