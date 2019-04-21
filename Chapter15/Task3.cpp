#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    const int MAX = 20;

    list<int> list_num;

    list<int>::iterator it_front;
    list<int>::iterator it_back;
    
    for(int i = 0; i < MAX; i++)
        list_num.push_back(i);
    
    cout << "RAW OUTPUT:\n" << endl;

    for(it_front = list_num.begin(); it_front != list_num.end(); it_front++)
        cout << *it_front << endl;

    cout << "\nREVERSING...\n";

    it_front = list_num.begin();
    it_back = list_num.end();
    it_back--;

    while(it_front != it_back)
    {
        swap(*it_front, *it_back);
        it_front++;
        
        if(it_front == it_back)
            break;

        it_back--;
    }

    cout << "- - -\nREVERSED OUTPUT:\n\n"; 

    for(it_front = list_num.begin(); it_front != list_num.end(); it_front++)
        cout << *it_front << endl;
}