#include <iostream>

using namespace std;

const int MAX = 10;

template <class T>
class queue
{
private:
    T q[MAX];
 
    int head;
    int tail;
public:
    queue() : head(0), tail(0) {};
 
    void put(T var)
    {
        if (tail == MAX)
        {
            tail = 0;
        }
 
        q[tail++] = var;
    }
 
    T get()
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
    queue<int> int_queue;

    for(int i = 0; i < MAX; i++)
    {
        int_queue.put(i);
    }

    for(int i = 0; i < MAX; i++)
    {
        cout << int_queue.get() << endl;
    }

    queue<float> float_queue;

    float_queue.put(1.23456);
    float_queue.put(2.34567);
    float_queue.put(3.45678);

    for(int i = 0; i < 3; i++)
    {
        cout << float_queue.get() << endl;
    }
    
}