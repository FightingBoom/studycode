#include <iostream>


int main()
{
    using namespace std;

    int nights = 1001;
    int* pt = new int;
    *pt = 1001;

    cout << "nights value = ";
    cout << nights << ": location " << &nights << endl;         // 打印出nights的值及地址
    cout << "int ";
    cout << "value = " << *pt << ": location = " << pt << endl;

    double* pd = new double;
    *pd = 10000001.0;

    cout << "double ";
    cout << "value = " << *pd << ": location = " << pd << endl;
    cout << "location of pointer pd: " << &pd << endl;
    cout << "size of pt = " << sizeof(pt);  // win10 64位系统，地址
    cout << ": size of *pt = " << sizeof(*pt) << endl;
    cout << "size of pd = " << sizeof pd;   // win10 64位系统，地址
    cout << ": size of *pd = " << sizeof(*pd) << endl;

    return 0;
}


/*
nights value = 1001: location 0x61fe14
int value = 1001: location = 0xee1790
double value = 1e+07: location = 0xee17b0
location of pointer pd: 0x61fe08
size of pt = 8: size of *pt = 4
size of pd = 8: size of *pd = 8
*/
