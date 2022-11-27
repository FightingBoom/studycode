#include <iostream>

using namespace std;

const int ArSize = 8;

int sum_arr(const int * begin, const int * end);

int main()
{
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};

    cout << cookies << " = arrays address, ";
    cout << sizeof cookies << " = sizeof cookies\n";

    int sum = sum_arr(cookies, cookies + ArSize);
    cout << "Total cookies eaten: " << sum << endl;

    sum = sum_arr(cookies, cookies + 3);
    cout << "First three eaters ate " << sum << " cookies.\n";

    sum = sum_arr(cookies + 4, cookies + ArSize);
    cout << "Last four eaters ate " << sum << " cookies.\n";

    return 0;
}

// 传递数组起始、结束位置
int sum_arr(const int * begin, const int * end)
{
    const int * pt;
    int total = 0;

    for (pt = begin; pt != end; pt++)
    {
        total = total + *pt;
        cout << pt << endl; // 增加打印，展示pt不同的地址
    }
    return total;
}


/*
0x61fdf0 = arrays address, 32 = sizeof cookies
Total cookies eaten: 255
First three eaters ate 7 cookies.
Last four eaters ate 240 cookies.


# 增加pt指针地址打印
0x61fdf0 = arrays address, 32 = sizeof cookies
0x61fdf0
0x61fdf4
0x61fdf8
0x61fdfc
0x61fe00
0x61fe04
0x61fe08
0x61fe0c
Total cookies eaten: 255
0x61fdf0
0x61fdf4
0x61fdf8
First three eaters ate 7 cookies.
0x61fe00
0x61fe04
0x61fe08
0x61fe0c
Last four eaters ate 240 cookies.
*/

