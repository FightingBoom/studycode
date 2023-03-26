#include <iostream>
#include "mytime2.h"

int main()
{
    using std::cout;
    using std::endl;

    Time weeding(4, 35);
    Time waxing(2, 47);
    Time total;
    Time diff;
    Time adjusted;

    cout << "weeding time = ";
    weeding.Show();
    cout << endl;

    cout << "waxing time = ";
    waxing.Show();
    cout << endl;

    cout << "total work time = ";
    total = weeding + waxing; // 用重载运算符+
    total.Show();
    cout << endl;

    // diff = weeding - waxing;  // 使用重载运算符-
    diff = waxing - weeding;  // 使用重载运算符-，交换位置测试
    // cout << "weeding time - waxing time = ";
    cout << "waxing time - weeding time = ";
    diff.Show();
    cout << endl;

    adjusted = total * 1.5;   // 使用重载运算符*
    cout << "adjusted work time = ";
    adjusted.Show();
    cout << endl;

    return 0;
}

/*
weeding time = 4 hours, 35 minutes
waxing time = 2 hours, 47 minutes
total work time = 7 hours, 22 minutes
weeding time - waxing time = 1 hours, 48 minutes
adjusted work time = 11 hours, 3 minutes
*/

/* 重载运算符-，交换位置
weeding time = 4 hours, 35 minutes
waxing time = 2 hours, 47 minutes
total work time = 7 hours, 22 minutes
waxing time - weeding time = -1 hours, -48 minutes
adjusted work time = 11 hours, 3 minutes
*/
