#include <iostream>

using namespace std;

int main()
{
    char ch;
    int spaces = 0; // 输入空格数量
    int total = 0;  // 输入总字符数量

    cin.get(ch);
    while ('.' != ch)
    {
        if (' ' == ch)
            ++spaces;
        ++total;
        cin.get(ch);
    }

    cout << spaces << " spaces, " << total << " characters total in sentence\n";

    return 0;
}

/*
The balloonist was an airhead
with lofty goals.
6 spaces, 46 characters total in sentence
*/
