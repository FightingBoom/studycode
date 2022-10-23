#include <iostream>

using namespace std;

int main()
{
    int iTotalLine = 0; // 用户输入需显示的总行数

    cout << "Please enter total line: ";
    cin >> iTotalLine;

    for (int i = 1; i <= iTotalLine; i++)   // 行循环
    {
        for (int j = 1; j <= iTotalLine - i; j++)   // 打印每行应显示的.
            cout << ".";

        for (int k = 1; k <= i; k++)    // 打印每行应显示的*
            cout << "*";
        
        cout << endl;   // 行尾换行
    }

    return 0;
}


/*
Please enter total line: 8
.......*
......**
.....***
....****
...*****
..******
.*******
********
*/
