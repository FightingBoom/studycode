#include <iostream>
#include "stonewt.h"

using std::cout;

void display(const Stonewt & st, int n);

int main()
{
    Stonewt incognito = 275; // 使用类自动转换，初始化
    Stonewt wolfe(285.7);    // 等同于第一种
    Stonewt taft(21, 8);     // 等同于前两种方法

    cout << "The celebrity weighed ";
    incognito.show_stn();

    cout << "The detective weighed ";
    wolfe.show_stn();

    cout << "The Persident weighed ";
    taft.show_lbs();

    incognito = 276.8;
    taft = 325;
    cout << "After dinner, the celebrity weighed ";
    incognito.show_stn();
    cout << "After dinner, the Persident weighed ";
    taft.show_lbs();
    display(taft, 2);
    cout << "The wrrestler weighed even more.\n";
    display(422, 2);  // 将422转换为double类型，然后调用对应的Stonewt构造函数
    cout << "No stone left unearned\n";

    return 0;
}

void display(const Stonewt & st, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Wow! ";
        st.show_stn();
    }
}

/*
The celebrity weighed 19 stone, 9 pounds
The detective weighed 20 stone, 5.7 pounds
The Persident weighed 302 pounds
After dinner, the celebrity weighed 19 stone, 10.8 pounds
After dinner, the Persident weighed 325 pounds
Wow! 23 stone, 3 pounds
Wow! 23 stone, 3 pounds
The wrrestler weighed even more.
Wow! 30 stone, 2 pounds
Wow! 30 stone, 2 pounds
No stone left unearned
*/
