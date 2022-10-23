#include <iostream>

int main()
{
    using namespace std;

    int x;

    cout << "The expression x = 100 has the value ";
    cout << (x = 100) << endl;
    cout << "Now x = " << x << endl;

    cout << "The expression x < 3 has the value ";
    cout << (x < 3) << endl;

    cout << "The expression x > 3 has the value ";
    cout << (x > 3) << endl;

    cout.setf(ios_base::boolalpha);     // 设置 cout 以 bool 格式（true / false）显示状态

    cout << "The expression x < 3 has the value ";
    cout << (x < 3) << endl;

    cout << "The expression x > 3 has the value ";
    cout << (x > 3) << endl;

    return 0;
}

/*
The expression x = 100 has the value 100
Now x = 100
The expression x < 3 has the value 0
The expression x > 3 has the value 1
The expression x < 3 has the value false
The expression x > 3 has the value true
*/
