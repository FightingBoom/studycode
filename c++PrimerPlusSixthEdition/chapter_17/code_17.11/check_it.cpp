#include <iostream>

using namespace std;

int main()
{
    cout << "Enter numbers: ";

    int sum = 0;
    int input;
    while (cin >> input) // 遇到非数字输入时，返回false退出
    {
        sum += input;
    }

    cout << "Last value entered = " << input << endl;
    cout << "Sum = " << sum << endl;
    return 0;
}

/*
zhaochen@zhaochendeMacBook-Air code_17.11 % clang++ check_it.cpp 
zhaochen@zhaochendeMacBook-Air code_17.11 % ./a.out 
Enter numbers: 200
10 -50 -123Z 60
Last value entered = 0
Sum = 37
*/
