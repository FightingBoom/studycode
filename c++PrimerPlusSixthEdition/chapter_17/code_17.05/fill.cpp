#include <iostream>

int main()
{
    using std::cout;

    cout.fill('*');

    const char * staff[2] =
    {
        "Waldo Whipsnade", "Wilmarie Wooper"
    };

    long bonus[2] = {900, 1350};

    for (int i = 0; i < 2; i++)
    {
        cout << staff[i] << ": $";
        cout.width(7);
        cout << bonus[i] << "\n";
    }

    return 0;
}

/*
zhaochen@zhaochendeMacBook-Air code_17.05 % clang++ fill.cpp 
zhaochen@zhaochendeMacBook-Air code_17.05 % ./a.out 
Waldo Whipsnade: $****900
Wilmarie Wooper: $***1350
*/
