#include <iostream>

using namespace std;

const double * f1(const double ar[], int n);
const double * f2(const double [], int n);
const double * f3(const double *, int n);

int main()
{
    double av[3] = {1112.3, 1542.6, 2227.9};

    const double *(*p1)(const double *, int) = f1; // C原始写法
    auto p2 = f2; // C++11简化写法
    cout << "Using pointers to functions:\n";
    cout << " Address  Value\n";
    cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl; // 函数所在指针，函数执行结果的返回值
    cout << p2(av, 3) << ": " << *p2(av, 3) << endl; // 同上，只是两种不同写法


    const double *(*pa[3])(const double *, int) = {f1, f2, f3};
    auto pb = pa;
    cout << "\nUsing an array of pointers to functions:\n";
    cout << " Address  Value\n";
    for (int i = 0; i < 3; i++)
        cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl; // 依次执行三个函数，打印出函数所在指针及函数返回值
    cout << "\nUsing a pointer to a pointer to a function:\n";
    cout << " Address  Value\n";
    for (int i = 0; i < 3; i++)
        cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << endl;


    cout << "\nUsing pointers to an array of pointers:\n";
    cout << " Address  Value\n";
    auto pc = &pa; // C++简化写法，但是原型不太好理解…………
    cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;
    const double *(*(*pd)[3])(const double *, int) = &pa; // C原始写法
    const double * pdb = (*pd)[1](av, 3);
    cout << pdb << ": " << *pdb << endl;
    cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;


    return 0;
}

const double * f1(const double * ar, int n)
{
    return ar;
}

const double * f2(const double ar[], int n)
{
    return ar + 1;
}

const double * f3(const double ar[], int n)
{
    return ar + 2;
}

/*
 Address Value
0x61fdc0: 1112.3
0x61fdc8: 1542.6

Using an array of pointers to functions:
 Address Value
0x61fdc0: 1112.3
0x61fdc8: 1542.6
0x61fdd0: 2227.9

Using a pointer to a pointer to a function:
 Address Value
0x61fdc0: 1112.3
0x61fdc8: 1542.6
0x61fdd0: 2227.9

Using pointers to an array of pointers:
 Address Value
0x61fdc0: 1112.3
0x61fdc8: 1542.6
0x61fdd0: 2227.9
*/

/*
Using pointers to functions:
 Address  Value
0x61fdc0: 1112.3
0x61fdc8: 1542.6

Using an array of pointers to functions:
 Address  Value
0x61fdc0: 1112.3
0x61fdc8: 1542.6
0x61fdd0: 2227.9

Using a pointer to a pointer to a function:
 Address  Value
0x61fdc0: 1112.3
0x61fdc8: 1542.6
0x61fdd0: 2227.9

Using pointers to an array of pointers:
 Address  Value
0x61fdc0: 1112.3
0x61fdc8: 1542.6
0x61fdd0: 2227.9
*/

