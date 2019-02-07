#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class String
{
private:
	enum { SZ = 80 };
	char str[SZ];
public:
	String()
	{
		strcpy_s(str, "");
	}

	String(const char* s)
	{
		strcpy_s(str, s);
	}

	void display() const
	{
		cout << str;
	}

	String operator+=(String ss) const
	{
		String temp;

		if (strlen(str) + strlen(ss.str) < SZ)
		{
			strcpy_s(temp.str, str);
			strcat_s(temp.str, ss.str);
		}
		else
		{
			cout << "\nOverflow!";
			exit(1);
		}
		return temp;
	}
};

int main()
{
	String s1 = "\nMerry Christmas! ";
	String s2 = "Happy New Year!";
	String s3;

	s1.display();
	s2.display();
	s3.display();

	s3 = s1 += s2;
	cout << endl;

	return 0;
}