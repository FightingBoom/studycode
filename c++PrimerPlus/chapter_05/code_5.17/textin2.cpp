#include <iostream>

using namespace std;

int main()
{
    char ch;
    int count = 0;

    cout << "Enter characters; enter # to quit:\n";
    cin.get(ch);

    while (ch != '#')
    {
        cout << ch;
        ++count;
        cin.get(ch);    // 此处获取的输入，会临时缓冲，并不会立即发给程序做判断
    }

    cout << endl << count << " characters read\n";  // 神奇，竟然能自动回显出来。

    return 0;
}

/*
Enter characters; enter # to quit:
Did you use a #2 pencil?
Did you use a 
14 characters read
*/
