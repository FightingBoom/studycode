#include <iostream>
#include "mytime3.h"

int main()
{
    using std::cout;
    using std::endl;

    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;

    cout << "Aida and Tosca:\n";
    cout << aida << "; " << tosca << endl; // friend operator<<
    temp = aida + tosca; // operator+()
    cout << "Aida + Tosca: " << temp << endl; // friend operator<<
    temp = aida * 1.17;  // operator*()
    cout << "Aida * 1.17: " << temp << endl; // friend operator<<
    cout << "10.0 * Tosca: " << 10.0 * tosca << endl; // friend operator<<

    return 0;
}

/*
3 hours, 35 minutes; 2 hours, 48 minutes
Aida + Tosca: 6 hours, 23 minutes
Aida * 1.17: 4 hours, 11 minutes
10.0 * Tosca: 28 hours, 0 minutes
*/

