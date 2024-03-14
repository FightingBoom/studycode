#include <iostream>
#include "stacktp.h"

template <template <typename T> class Thing>
class Crab
{
private:
    Thing<int> s1;
    Thing<double> s2;

public:
    Crab() {}

    bool push(int a, double x)
    {
        return s1.push(a) && s2.push(x);
    }

    bool pop(int & a, double & x)
    {
        return s1.pop(a) && s2.pop(x);
    }
};

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    Crab<Stack> nebula;

    int ni;
    double nb;
    cout << "Enter int double pairs, such as 4 3.5 "
        << "(0 0 to end):\n";

    while (cin >> ni >> nb && ni > 0 && nb > 0)
    {
        if (!nebula.push(ni, nb))
            break;
    }

    while (nebula.pop(ni, nb))
        cout << ni << ", " << nb << endl;

    cout << "Done.\n";
    return 0;
}

/*
zhaochen@zhaochendeAir code_14.21 % ./a.out             
Enter int double pairs, such as 4 3.5 (0 0 to end):
50 22.48
25 33.87
60 19.12
0 0
60, 19.12
25, 33.87
50, 22.48
Done.
*/

