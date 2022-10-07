#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{    
    double wages[3] = {10000.0, 20000.0, 30000.0};
    short stacks[3] = {3, 2, 1};
    
    double* pw = wages;
    short* ps = &stacks[0];
    
    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    pw = pw + 1;
    cout << "pw + 1\n";
    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    
    cout << "ps = " << ps << ", *ps = " << *ps << endl;
    ps = ps + 1;
    cout << "ps + 1\n";
    cout << "ps = " << ps << ", *ps = " << *ps << endl;
    
    cout << "stacks[0] = " << stacks[0] << ", stacks[1] = " << stacks[1] << endl;
    cout << "*(stack + 1)\n";
    cout << "*stacks = " << *stacks << ", *(stacks + 1) = " << *(stacks + 1) << endl;
    
    cout << sizeof(wages) << endl;
    cout << sizeof(pw) << endl;
}


/* 执行结果
pw = 0x7ffe3692cce0, *pw = 10000
pw + 1
pw = 0x7ffe3692cce8, *pw = 20000
ps = 0x7ffe3692ccd8, *ps = 3
ps + 1
ps = 0x7ffe3692ccda, *ps = 2
stacks[0] = 3, stacks[1] = 2
*(stack + 1)
*stacks = 3, *(stacks + 1) = 2
24
8
*/