#include <iostream>

using namespace std;

class queue
{
private:
	static const int MAX = 10;

	int q[MAX];

	int head;
	int tail;
public:
	queue() : head(0), tail(0) {};

	void put(int var)
	{
		if (tail == MAX)
		{
			tail = 0;
		}

		q[tail++] = var;
	}

	int get()
	{
		if (head == MAX)
		{
			head = 0;
		}

		return q[head++];
	}
};

int main()
{
	queue q;

	q.put(10);
	q.put(20);

	cout << q.get() << endl;
	cout << q.get() << endl;

	q.put(40);
	q.put(50);
	q.put(60);
	q.put(70);

	cout << q.get() << endl;
	cout << q.get() << endl;
	cout << q.get() << endl;
	cout << q.get() << endl;

	q.put(80);
	q.put(90);
	q.put(100);
	q.put(0);

	cout << q.get() << endl;
	cout << q.get() << endl;
	cout << q.get() << endl;
	cout << q.get() << endl;

	q.put(1002);
	cout << q.get() << endl;

	q.put(80);
	q.put(90);
	q.put(100);
	q.put(0);
	q.put(80);
	q.put(90);
	q.put(100);
	q.put(0);

	cout << q.get() << endl;
	cout << q.get() << endl;
	cout << q.get() << endl;
	cout << q.get() << endl;
	cout << q.get() << endl;
	cout << q.get() << endl;
	cout << q.get() << endl;
	cout << q.get() << endl;
}