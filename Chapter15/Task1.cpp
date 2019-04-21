#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    const int MAX = 20;
    float arr[MAX];

    for(int i = 0; i < MAX; i++)
        *(arr + i) = rand() / (RAND_MAX / 100.0);

    cout << "RAW OUTPUT:\n" << endl;

    for(int i = 0; i < MAX; i++)
        cout << *(arr + i) << endl;
    
    cout << "\nSORTING...\n";

    sort(arr, arr + MAX);

    cout << "- - -\nSORTED OUTPUT:\n\n"; 

    for(int i = 0; i < MAX; i++)
        cout << *(arr + i) << endl;
}