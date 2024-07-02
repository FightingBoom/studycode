#include <iostream>

int main()
{
    using std::cout;
    using std::endl;
    using std::ios_base;

    int temperature = 63;

    cout << "Today's water temperature: ";
    cout.setf(ios_base::showpos);
    cout << temperature << endl;

    cout << "For our programming friends, that's\n";
    cout << std::hex << temperature << endl;
    cout.setf(ios_base::uppercase);
    cout.setf(ios_base::showbase);
    cout << "or\n";
    cout << temperature << endl;
    cout << "How " << true << "!    oop -- How ";
    cout.setf(ios_base::boolalpha);// 以字符串显示布尔值
    cout << true << "!\n";

    return 0;
}

/*
zhaochen@zhaochendeMacBook-Air code_17.08 % ./a.out 
Today's water temperature: +63
For our programming friends, that's
3f
or
0X3F
How 0X1!    oop -- How true!
*/
