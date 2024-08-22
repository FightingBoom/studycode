#include "somedefs.h"
#include <iostream>
#include <functional>

double dub(double x) { return 2.0 * x; }
double square(double x) { return x * x; }

int main()
{
    using std::cout;
    using std::endl;
    using std::function;

    double y = 1.21;

    function<double(double)> ef1 = dub;
    function<double(double)> ef2 = square;
    function<double(double)> ef3 = Fq(10.0);
    function<double(double)> ef4 = Fp(10.0);
    function<double(double)> ef5 =
        [](double u){return u*u;};
    function<double(double)> ef6 =
        [](double u){return u+u/2.0;};

    cout << "Function pointer dub:\n";
    cout << "   " << use_f(y, ef1) << endl;

    cout << "Function pointer square:\n";
    cout << "   " << use_f(y, ef2) << endl;

    cout << "Function object Fq:\n"; // 书本示例错误，应为Fq
    cout << "   " << use_f(y, ef3) << endl;

    cout << "Function object Fp:\n"; // 书本示例错误，应为Fp
    cout << "   " << use_f(y, ef4) << endl;

    cout << "Lambda expression 1:\n";
    cout << "   " << use_f(y, ef5) << endl;

    cout << "Lambda expression 2:\n";
    cout << "   " << use_f(y, ef6) << endl;

    return 0;
}

/*
zhaochen@zhaochendeAir code_18.08 % clang++ wrapped.cpp -std=c++11
zhaochen@zhaochendeAir code_18.08 % ./a.out 
Function pointer dub:
    use_f count = 1, &count = 0x104f40000
2.42
Function pointer square:
    use_f count = 2, &count = 0x104f40000
1.4641
Function object Fq:
    use_f count = 3, &count = 0x104f40000
11.21
Function object Fp:
    use_f count = 4, &count = 0x104f40000
12.1
Lambda expression 1:
    use_f count = 5, &count = 0x104f40000
1.4641
Lambda expression 2:
    use_f count = 6, &count = 0x104f40000
1.815
zhaochen@zhaochendeAir code_18.08 %
*/
