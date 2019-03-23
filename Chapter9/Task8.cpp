#include <iostream>
#include <string.h>

using namespace std;
//209
class String
{
protected:
	enum { SZ = 80 };
	char str[SZ];
public:
	String() { str[0] = '\x0'; }
	String(const char s[]) { strcpy_s(str, s); }

	void Display()const { cout << str << endl; }

	operator char*() { return str; }
};

class Pstring : public String
{
public:
	Pstring(const char s[])
	{
		if (strlen(s) >= SZ)
		{
			for (int i = 0; i < SZ - 1; i++)
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

class Pstring2 : public String
{
public:
	Pstring2(const char s[])
	{
		if (strlen(s) >= SZ)
		{
			for (int i = 0; i < SZ - 1; i++)
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

	void left(Pstring2 s1, int n)
	{
		for (int i = strlen(str), j = 0; j < n; i++, j++)
		{
			if (i < SZ - 1) 
			{
				str[i] = s1[j];

				if (j == n - 1)
				{
					str[i + 1] = '\x0';
				}
			}
		}
	}

	void mid(Pstring2 s1, int s, int n)
	{
		for (int i = strlen(str), j = 0; j < n; i++, j++)
		{
			if (i < SZ - 1)
			{
				str[i] = s1[j+s];

				if (s - j == n - 1)
				{
					str[i + 1] = '\x0';
				}
			}
		}
	}

	void right(Pstring2 s1, int n)
	{
		for (int i = strlen(str), j = 0; j < n; i++, j++)
		{
			if (i < SZ - 1)
			{
				str[i] = s1[strlen(s1)-j-1];

				if (j == n - 1)
				{
					str[i + 1] = '\x0';
				}
			}
		}
	}
};

int main()
{
	Pstring2 ps1 = "Test", ps2 = "Kek";
	ps1.Display();
	ps1.left(ps2, 2);
	ps1.Display();

	Pstring2 ps3 = "Lel", ps4 = "Bishkeke";
	ps3.Display();
	ps3.mid(ps4, 4, 3);
	ps3.Display();

	Pstring2 ps5 = "Test", ps6 = "keK";
	ps5.Display();
	ps5.right(ps6, 3);
	ps5.Display();
}