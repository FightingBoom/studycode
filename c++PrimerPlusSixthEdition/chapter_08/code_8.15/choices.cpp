#include <iostream>

using namespace std;

template <typename T>
T lesser(T a, T b)
{
    return a < b ? a : b;
}

int lesser (int a, int b)
{
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    return a < b ? a : b;
}

int main()
{
    int m = 20;
    int n = -30;
    double x = 15.5;
    double y = 25.9;

    cout << lesser(m, n) << endl;      // 优先选择非模板函数
    cout << lesser(x, y) << endl;      // 优先模板函数
    cout << lesser<>(m, n) << endl;    // 强制使用模板函数
    cout << lesser<int>(x, y) << endl; // 显式实例化为int类型，因此double被转换为int型

    return 0;
}

/*
20
15.5
-30
15
*/
