#include <iostream>

using namespace std;

template <class T>
T average(T* arr, int count)
{
    T result, sum = 0;

    for(int i = 0; i < count; i++)
    {
        sum += arr[i];
    }
    
    result = sum / count;
}

int main()
{
    const int arr_size = 5;

    int int_arr[arr_size] = { 4, 5, 2, 5, 2 };
    float float_arr[arr_size] = { 2.5, 3.5, 4.8, 5.2, 1.34 };
    long long_arr[arr_size] = { 23242425, 35, 428, 5222, 1442424234 };
    char char_arr[arr_size] = { 7, 5, 2, 64, 2 };

    cout << "int array avg = " << average(int_arr, arr_size) << endl;
    cout << "float array avg = " << average(float_arr, arr_size) << endl;
    cout << "long array avg = " << average(long_arr, arr_size) << endl;
    cout << "char array avg = " << (int)average(char_arr, arr_size) << endl;
}