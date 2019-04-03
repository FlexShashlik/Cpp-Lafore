#include <iostream>
#include <string.h>
#include "str.h"

using namespace std;

// maximum digits in verylongs
const int SZ = 100000;

class verylong
{
private:
    char vlstr[SZ];
    int vlen;

    verylong multdigit(const int) const;
    verylong mult10(const verylong) const;
public:
    verylong() : vlen(0)
    {
        vlstr[0]='\0'; 
    }

    verylong(const char s[SZ])
    {
        strcpy(vlstr, s); 
        vlen = strlen(s);
    }

    verylong(const unsigned long n)
    {
        snprintf(vlstr, SZ, "%ld", n);
        strrev(vlstr);
        vlen = strlen(vlstr);
    }

    void putvl() const;
    void getvl();
    
    verylong operator+(const verylong);
    verylong operator*(const verylong);
};