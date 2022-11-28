#include <iostream>

using namespace std;

unsigned int c_in_str(const char * str, char ch);

int main()
{
    char mmm[15] = "minimum";
    // char *wail = "ululate";
    char *wail = (char *)"ululate"; // 增加强制转换，解决C++编译警告

    unsigned int ms = c_in_str(mmm, 'm');
    unsigned int us = c_in_str(wail, 'u');
    cout << ms << " m characters in " << mmm << endl;
    cout << us << " u characters in " << wail << endl;

    return 0;
}

unsigned int c_in_str(const char * str, char ch)
{
    unsigned int count = 0;
    while (*str)
    {
        if (*str == ch)
            count++;
        str++;
    }
    return count;
}

/*
strgfun.cpp: In function 'int main()':
strgfun.cpp:10:18: warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
     char *wail = "ululate";
                  ^~~~~~~~~
3 m characters in minimum
2 u characters in ululate

# 增加强制转换后，编译无警告
3 m characters in minimum
2 u characters in ululate
*/

