#include <iostream>
#include <string>

int main()
{
    using namespace std;

    string empty;
    string small = "bit";
    string larger = "Elephants are a girl's best friend";

    cout << "Sizes:\n";
    cout << "\tempty: " << empty.size() << endl;
    cout << "\tsmall: " << small.size() << endl;
    cout << "\tlarger: " << larger.size() << endl;

    cout << "Capacities:\n";
    cout << "\tempty: " << empty.capacity() << endl;
    cout << "\tsmall: " << small.capacity() << endl;
    cout << "\tlarger: " << larger.capacity() << endl;

    empty.reserve(50);
    cout << "Capacity after empty.reserve(50): "
        << empty.capacity() << endl;

    return 0;
}

/*
zhaochen@zhaochendeAir code_16.04 % clang++ str2.cpp 
zhaochen@zhaochendeAir code_16.04 % ./a.out 
Sizes:
        empty: 0
        small: 3
        larger: 34
Capacities:
        empty: 22
        small: 22
        larger: 47
Capacity after empty.reserve(50): 63
*/
