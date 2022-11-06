#include <iostream>

using namespace std;

enum
{
    red,
    orange,
    yellow,
    green,
    blue,
    violet,
    indigo,
};

int main()
{
    cout << "Enter color code (0-6): ";
    int code;
    cin >> code;
    while (code >= red && code <= indigo)
    {
        switch (code)
        {
            case red    : cout << "Her lips were red.\n"; break;
            case orange : cout << "Her hair was orange.\n"; break;
            case yellow : cout << "Her shoes were yellow.\n"; break;
            case green  : cout << "Her nails were green.\n"; break;
            case blue   : cout << "Her sweatsuit was blue.\n"; break;
            case violet : cout << "Her eyes were violet.\n"; break;
            case indigo : cout << "Her mood was indigo.\n"; break;
            default     : cout << "That's not a goog choice.\n"; break; // 即使走不到，也应该有异常处理，避免遗忘
        }

        cout << "Enter color code (0-6): ";
        cin >> code;
    }

    cout << "Bye\n";
    return 0;
}

/*
1、如果所有的选项都可以使用整数常量来标识，则可以使用 switch 语句或者 if else 语句。由于 switch 语句
    是专门为这种情况设计的，因此，如果选项超过两个，则就代码长度和执行速度而言，switch 语句的效率更高。
2、如果既可以使用 if else if 语句，也可以使用 switch 语句，则当选项不少于 3 个时，应使用 switch 语句。
*/

/*
Enter color code (0-6): 3
Her nails were green.
Enter color code (0-6): 5
Her eyes were violet.
Enter color code (0-6): 2
Her shoes were yellow.
Enter color code (0-6): 8
Bye
*/
