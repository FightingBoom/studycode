#include <iostream>

int main()
{
    using std::cout;
    float price1 = 20.40;
    float price2 = 1.9 + 8.0 / 9.0;

    cout << "\"Furry Friends\" is $" << price1 << "!\n";
    cout << "\"Fiery Friends\" is $" << price2 << "!\n";

    cout.precision(2);
    cout << "\"Furry Friends\" is $" << price1 << "!\n";
    cout << "\"Fiery Friends\" is $" << price2 << "!\n";

    return 0;
}

/*
zhaochen@zhaochendeMacBook-Air code_17.06 % clang++ precise.cpp 
zhaochen@zhaochendeMacBook-Air code_17.06 % ./a.out 
"Furry Friends" is $20.4!
"Fiery Friends" is $2.78889!
"Furry Friends" is $20!
"Fiery Friends" is $2.8!
*/
