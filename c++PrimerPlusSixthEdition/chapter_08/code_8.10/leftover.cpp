#include <iostream>

using namespace std;

unsigned long left(unsigned long num, unsigned ct);
char * left(const char * str, int n = 1);

int main()
{
    char * trip = (char *)"Hawaii!!"; // 增加强制转换，解决 -Wwrite-strings 编译警告
    unsigned long n = 12345678;
    int i;
    char * temp;

    for (i = 1; i < 10; i ++)
    {
        cout << left(n, i) << endl;
        temp = left(trip, i);
        cout << temp << endl;
        delete [] temp;
    }

    return 0;
}

unsigned long left(unsigned long num, unsigned ct)
{
    unsigned digits = 1;
    unsigned long n = num;

    if (0 == ct || 0 == num)
        return 0;
    
    while (n /= 10)
        digits++;

    if (digits > ct)
    {
        ct = digits - ct;
        while (ct--)
            num /= 10;
        return num;
    }
    else
    {
        return num;
    }
}

char *  left(const char * str, int n)
{
    if (n < 0)
        n = 0;

    char * p = new char[n + 1];

    int i;
    for (i = 0; i < n && str[i]; i++)
        p[i] = str[i];

    while (i <= n)
        p[i++] = '\0';

    return p;
}

/*
leftover.cpp: In function 'int main()':
leftover.cpp:10:19: warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
     char * trip = "Hawaii!!";
                   ^~~~~~~~~~
1
H
12
Ha
123
Haw
1234
Hawa
12345
Hawai
123456
Hawaii
1234567
Hawaii!
12345678
Hawaii!!
12345678
Hawaii!!
*/

/*
1
H
12
Ha
123
Haw
1234
Hawa
12345
Hawai
123456
Hawaii
1234567
Hawaii!
12345678
Hawaii!!
12345678
Hawaii!!
*/
