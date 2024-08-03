#include <iostream>

using namespace std;

inline double f(double tf)
{
    return 5.0 * (tf - 32.0) / 9.0;
}

int main()
{
    double tc = 21.5;
    double && rd1 = 7.07;
    double && rd2 = 1.8 * tc + 32.0;
    double && rd3 = f(rd2);

    cout << " tc value and address: " << tc << ", "
        << &tc << endl;

    cout << "rd1 value and address: " << rd1 << ", "
        << &rd1 << endl;

    cout << "rd2 value and address: " << rd2 << ", "
        << &rd2 << endl;

    cout << "rd3 value and address: " << rd3 << ", "
        << &rd3 << endl;

    cin.get();
    return 0;
}

/* 必须显式指定C++11
zhaochen@zhaochendeAir code_18.01 % clang++ rvref.cpp -std=c++11
zhaochen@zhaochendeAir code_18.01 % 
zhaochen@zhaochendeAir code_18.01 % ./a.out 
 tc value and address: 21.5, 0x16d3a3360
rd1 value and address: 7.07, 0x16d3a3350
rd2 value and address: 70.7, 0x16d3a3340
rd3 value and address: 21.5, 0x16d3a3330

zhaochen@zhaochendeAir code_18.01 %
*/
