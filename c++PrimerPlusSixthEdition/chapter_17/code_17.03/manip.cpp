#include <iostream>

int main()
{
    using namespace std;
    cout << "Enter an integer: ";
    int n;
    cin >> n;

    cout << "n      n*n\n";
    cout << n << "      " << n * n << " (decimal)\n";

    cout << hex;
    cout << n << "      ";
    cout << n * n << " (hexadecimal)\n";

    cout << oct << n << "       " << n * n << " (octal)\n";

    dec(cout);
    cout << n << "      " << n * n << " (decimal)\n";

    return 0;
}

/*
zhaochen@zhaochendeMacBook-Air code_17.03 % clang++ manip.cpp 
zhaochen@zhaochendeMacBook-Air code_17.03 % ./a.out 
Enter an integer: 13
n      n*n
13      169 (decimal)
d      a9 (hexadecimal)
15       251 (octal)
13      169 (decimal)
*/
