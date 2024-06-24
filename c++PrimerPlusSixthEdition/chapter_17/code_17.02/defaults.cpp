#include <iostream>

int main()
{
    using std::cout;
    cout << "12345678901234567890\n";

    char ch = 'K';
    int t = 273;
    cout << ch << ":\n";
    cout << t << ":\n";
    cout << -t << ":\n";

    double f1 = 1.200;
    cout << f1 << ":\n";
    cout << (f1 + 1.0 / 9.0) << ":\n";

    double f2 = 1.67E2;
    cout << f2 << ":\n";
    f2 += 1.0 / 9.0;
    cout << f2 << ":\n";
    cout << (f2 * 1.0e4) << ":\n";

    double f3 = 2.3e-4;
    cout << f3 << ":\n";
    cout << f3 / 10 << ":\n";

    return 0;
}

/*
zhaochen@zhaochendeMacBook-Air code_17.02 % clang++ defaults.cpp 
zhaochen@zhaochendeMacBook-Air code_17.02 % ./a.out 
12345678901234567890
K:
273:
-273:
1.2:
1.31111:
167:
167.111:
1.67111e+06:
0.00023:
2.3e-05:
*/

