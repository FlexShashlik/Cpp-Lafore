// newstr.cpp
// èñïîëüçîâàíèå îïåðàòîðà new äëÿ âûäåëåíèÿ ïàìÿòè ïîä ñòðîêó
#include <iostream>
#include <cstring>     // äëÿ strcpy(), è ò.ä.
using namespace std;
///////////////////////////////////////////////////////////
class String
{
private:
	char* str;                      // óêàçàòåëü íà ñòðîêó
public:
	String(char* s)                 // êîíñòðóêòîð ñ îäíèì ïàðàìåòðîì
	{
		int length = strlen(s);     // âû÷èñëÿåì äëèíó ñòðîêè
		str = new char[length + 1]; // âûäåëÿåì íåîáõîäèìóþ ïàìÿòü
		strcpy(str, s);             // êîïèðóåì ñòðîêó
	}
	~String()                       // äåñòðóêòîð
	{
		cout << "Óäàëÿåì ñòðîêó\n";
		delete[] str;               // îñâîáîæäàåì ïàìÿòü
	}
	void display()                  // ïîêàæåì ñòðîêó íà ýêðàíå
	{
		cout << str << endl;
	}
};
///////////////////////////////////////////////////////////
int main()
{
	system("chcp 1251 > nul");

	String s1 = "Òèøå åäåøü - äàëüøå áóäåøü.";
	cout << "s1 = ";
	s1.display();

	return 0;
}
