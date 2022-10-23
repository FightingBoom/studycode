#include <iostream>
#include <vector>
#include <array>

int main()
{
    using namespace std;

    double a1[4] = {1.0, 1.1, 1.2, 1.3};

    vector<double> a2(4);
    a2[0] = 2.0;
    a2[1] = 2.1;
    a2[2] = 2.2;
    a2[3] = 2.3;

    array<double, 4> a3 = {3.0, 3.1, 3.2, 3.3};
    array<double, 4> a4;
    a4 = a3;

    cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
    cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;

    a1[-2] = 20.2;  // a1[-2] = *(a1 - 2)

    cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;

    return 0;
}

/*
a1[2]: 1.2 at 0x61fdf0
a2[2]: 2.2 at 0xd917a0
a3[2]: 3.2 at 0x61fdb0
a4[2]: 3.2 at 0x61fd90
a1[-2]: 20.2 at 0x61fdd0
a3[2]: 3.2 at 0x61fdb0
a4[2]: 3.2 at 0x61fd90
*/

