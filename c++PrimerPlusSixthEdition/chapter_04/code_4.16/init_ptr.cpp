#include <iostream>


int main()
{
    using namespace std;

    int higgens = 5;
    int* pt = &higgens;

    cout << "Value of higgens = " << higgens;
    cout << "; Address of higgens = " << &higgens << endl;

    cout << "Value of *pt = " << *pt;           // 指向的内容
    cout << "; Value of pt = " << pt;           // 指针存放的地址，也就是指向内容的地址
    cout << "; Value of &pt = " << &pt << endl; // 指针地址

    return 0;
}


/*
Value of higgens = 5; Address of higgens = 0x61fe1c
Value of *pt = 5; Value of pt = 0x61fe1c; Value of &pt = 0x61fe10
*/
