#include <iostream>

using namespace std;    // 无此语句，则需要按标准格式使用：std::cin / std::cout

int main()
{
    char ch;

    cout << "Type, and I shall repeat.\n";

    cin.get(ch);
    while ('.' != ch)
    {
        if ('\n' == ch)
            cout << ch;
        else
            cout << ++ch;

        cin.get(ch);
    }

    cout << "\nPlease excuse the slight confusion.\n";

    return 0;
}

/*
Type, and I shall repeat.
An ineffable joy suffused me as I beheld
Bo!jofggbcmf!kpz!tvggvtfe!nf!bt!J!cfifme
the wonders of modern computing.
uif!xpoefst!pg!npefso!dpnqvujoh
Please excuse the slight confusion.
*/
