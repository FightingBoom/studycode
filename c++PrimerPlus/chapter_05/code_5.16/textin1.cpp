#include <iostream>

using namespace std;

int main()
{
    char ch;
    int count = 0;
    cout << "Enter characters; enter # to quit:\n";
    cin >> ch;

    while (ch != '#')
    {
        cout << ch;
        ++count;
        cin >> ch;  // 此处获取的输入，会临时缓冲，并不会立即发给程序做判断
    }

    cout << endl << count << " characters read\n";  // 神奇，竟然能自动回显出来。

    return 0;
}

/*
Enter characters; enter # to quit:
see ken run#really fast
seekenrun
9 characters read
*/
