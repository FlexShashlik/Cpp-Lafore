#include <iostream>

using namespace std;

template <class T>
T amax(T* arr, int count)
{
    T max = arr[0];

    for(int i = 1; i < count; i++)
        max = max > arr[i] ? max : arr[i];
    
    return max;
}

int main()
{
    int arr[5] = { 15, 12, 25, 6, 8 };
    float farr[10] = { 1.5, 1.2, 2.5, 6.21, 8.3, 8.45, 2.4, 7.1, 8.456, 3.2 };

    cout << amax(arr, 5) << endl;
    cout << amax(farr, 10) << endl;
}
