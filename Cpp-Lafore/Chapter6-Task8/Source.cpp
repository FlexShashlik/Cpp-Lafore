#include <iostream>

using namespace std;

class Obj
{
private:
	static int count;
	int id;
public:
	Obj() { id = ++count; }

	void Display()
	{
		cout << "My id is " << id << endl;
	}
};

int Obj::count = 0;

int main()
{
	Obj o1, o2, o3;

	o1.Display();
	o2.Display();
	o3.Display();
}