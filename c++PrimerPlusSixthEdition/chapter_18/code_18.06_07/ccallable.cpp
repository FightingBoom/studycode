#include "somedefs.h"
#include <iostream>

double dub(double x) { return 2.0 * x; }
double square(double x) { return x * x; }

int main()
{
    using std::cout;
    using std::endl;

    double y = 1.21;
    cout << "Function pointer dub:\n";
    cout << "   " << use_f(y, dub) << endl;

    cout << "Function pointer square:\n";
    cout << "   " << use_f(y, square) << endl;

    cout << "Function object Fp:\n";
    cout << "   " << use_f(y, Fp(5.0)) << endl;

    cout << "Function object Fq:\n";
    cout << "   " << use_f(y, Fq(5.0)) << endl;

    cout << "Lambda expression 1:\n";
    cout << "   "
        << use_f(y, [](double u) {return u*u;}) << endl;

    cout << "Lambda expression 2:\n";
    cout << "   "
        << use_f(y, [](double u) {return u+u/2.0;}) << endl;

    return 0;
}

/*
zhaochen@zhaochendeAir code_18.06_07 % clang++ ccallable.cpp -std=c++11
zhaochen@zhaochendeAir code_18.06_07 % ./a.out 
Function pointer dub:
    use_f count = 1, &count = 0x100614000
2.42
Function pointer square:
    use_f count = 2, &count = 0x100614000
1.4641
Function object Fp:
    use_f count = 1, &count = 0x100614004
6.05
Function object Fq:
    use_f count = 1, &count = 0x100614008
6.21
Lambda expression 1:
    use_f count = 1, &count = 0x10061400c
1.4641
Lambda expression 2:
    use_f count = 1, &count = 0x100614010
1.815
zhaochen@zhaochendeAir code_18.06_07 %
*/
