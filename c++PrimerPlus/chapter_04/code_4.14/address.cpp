#include <iostream>


int main()
{
    using namespace std;

    int donuts = 6;
    double cups = 4.5;

    cout << "donuts value = " << donuts;
    cout << " and donuts address = " << &donuts << endl;

    cout << "cups value = " << cups;
    cout << " and cups address = " << &cups << endl;

    return 0;
}


/*
donuts value = 6 and donuts address = 0x61fe1c
cups value = 4.5 and cups address = 0x61fe10
*/
