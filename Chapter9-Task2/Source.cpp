#include <iostream>
#include <string.h>

using namespace std;

class String
{
protected:
	enum { SZ = 80 };
	char str[SZ];
public:
	String() { str[0] = '\x0'; }
	String(const char s[]) { strcpy_s(str, s); }

	void Display()const { cout << str; }

	operator char*() { return str; }
};

class Pstring : public String
{
public:
	Pstring(const char s[])
	{
		if (strlen(s) >= SZ)
		{
			for (int i = 0; i < SZ-1; i++)
			{
				str[i] = s[i];
			}
			
			str[SZ - 1] = '\x0';
		}
		else 
		{
			strcpy_s(str, s);
		}
	}
};

int main()
{
	String s1;

	char xstr[] = "WowOWoowOW!";
	s1 = xstr;
	s1.Display();

	String s2 = "LoL :D";

	cout << static_cast<char*>(s2);

	Pstring ps = "1234567950";
	ps.Display();

	Pstring ps1 = "1234567891011121314151617181920212223242526272829303132333435363738394041424344454647484950";
	ps1.Display();
}