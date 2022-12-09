#include <iostream>

using namespace std;

int main()
{
    int rats = 101;
    int & rodents = rats;
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;

    int bunnies = 50;
    rodents = bunnies;
    cout << "bunnies = " << bunnies;
    cout << ", rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "bunnies address = " << &bunnies;
    cout << ", rodents address = " << &rodents << endl;

    return 0;
}

/*
rats = 101, rodents = 101
rats address = 0x61fe14, rodents address = 0x61fe14   
bunnies = 50, rats = 50, rodents = 50
bunnies address = 0x61fe10, rodents address = 0x61fe14
*/

