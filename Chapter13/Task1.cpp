#include "verylong.h"

int main()
{
    unsigned long numb, j;
    verylong fact = 1;

    cout << "Enter number: ";
    cin >> numb;

    for(j = numb; j > 0; j--)
        fact = fact * j;

    cout << "Factorial is ";
    fact.putvl();
    cout << endl;
    
    verylong result, num1, num2;
    char action;

    cout << "Enter first num: ";
    num1.getvl();

    cout << "Enter action: ";
    cin >> action;

    cout << "Enter second num: ";
    num2.getvl();

    switch (action)
    {
        case '*':
            result = num1 * num2;
            result.putvl();
            break;
    
        case '+':
            result = num1 + num2;
            result.putvl();
            break;

        default:
            cout << "Unknown action!";
            break;
    }

    cout << endl;

    return 0;
}