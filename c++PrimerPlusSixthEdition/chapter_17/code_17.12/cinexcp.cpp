#include <iostream>
#include <exception>

using namespace std;

int main()
{
    cin.exceptions(ios_base::failbit);
    cout << "Enter numbers: ";

    int sum = 0;
    int input;

    try
    {
        while (cin >> input) // 读取到非int类型时，会抛出异常
        {
            sum += input;
        }
    }
    catch (ios_base::failure & bf)
    {
        cout << bf.what() << endl;
        cout << "O! the horror!\n";
    }

    cout << "Last value entered = " << input << endl;
    cout << "Sum = " << sum << endl;

    return 0;
}

/*
zhaochen@zhaochendeMacBook-Air code_17.12 % clang++ cinexcp.cpp 
zhaochen@zhaochendeMacBook-Air code_17.12 % ./a.out 
Enter numbers: 20 30 40 pi 6
ios_base::clear: unspecified iostream_category error
O! the horror!
Last value entered = 0
Sum = 90
*/
