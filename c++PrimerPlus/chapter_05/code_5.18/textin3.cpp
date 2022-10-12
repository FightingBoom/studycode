#include <iostream>

using namespace std;

int main()
{
    char ch;
    int count = 0;

    cin.get(ch);

    // while (cin)  // 可以直接替换为 cin
    // while (cin.get(ch))  // 可以直接替换为 cin.get(ch) ，因为该接口返回值也为 cin
    while (cin.fail() == false)
    {
        cout << ch;
        ++count;
        cin.get(ch);    // 此处获取的输入，会临时缓冲，并不会立即发给程序做判断
    }

    cout << endl << count << " characters read\n";  // 神奇，竟然能自动回显出来。

    return 0;
}

/*
The green bird sings in the winter.
The green bird sings in the winter.
Yes, but the crow flies in the dawn.
Yes, but the crow flies in the dawn.
^Z

73 characters read
*/
