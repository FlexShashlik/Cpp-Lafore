#include <iostream>

using namespace std;

template <class T>
void swaps(T& var1, T& var2)
{
    T temp = var1;
    var1 = var2;
    var2 = temp;
}

int main()
{
    int var1 = 10, var2 = 5;
    float x = 12.4, y = 33.2422;

    swaps(var1, var2);
    swaps(x, y);

    cout << var1 << ' ' << var2 << endl;
    cout << x << ' ' << y << endl;
}