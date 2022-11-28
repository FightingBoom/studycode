#include <iostream>

using namespace std;

char * buildstr(char c, int n);

int main()
{
    int times;
    char ch;

    cout << "Enter a character: ";
    cin >> ch; // 输入字符
    cout << "Enter an integer: ";
    cin >> times; // 输入重复次数
    char *ps = buildstr(ch, times);
    cout << ps << endl;
    delete [] ps;

    ps = buildstr('+', 20);
    cout << ps << "-DONE-" << ps << endl;
    delete [] ps;
    ps = NULL; // 指针用完之后，置空

    return 0;
}

char * buildstr(char c, int n)
{
    char *pStr = new char[n + 1];
    pStr[n] = '\0';
    while (n-- > 0)
        pStr[n] = c;

    return pStr; // 返回指针地址
}

/*
Enter a character: V
Enter an integer: 46
VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV
++++++++++++++++++++-DONE-++++++++++++++++++++
*/