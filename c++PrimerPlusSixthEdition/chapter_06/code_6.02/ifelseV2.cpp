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
            cout << ch + 1; // ++ch -> ch + 1, cout 会检测为 int 类型

        cin.get(ch);
    }

    cout << "\nPlease excuse the slight confusion.\n";

    return 0;
}

/*
Type, and I shall repeat.
An ineffable joy suffused me as I beheld
66111331061111021031039899109102331071121223311611810310311811610210133110102339811633743399102105102109101
the wonders of modern computing.
11710510233120112111101102115116331121033311011210110211511133100112110113118117106111104
Please excuse the slight confusion.
*/
