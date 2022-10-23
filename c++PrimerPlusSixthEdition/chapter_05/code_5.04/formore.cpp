#include <iostream>

const int ArSize = 16;  // 定义阶乘的个数

int main()
{
    long long factorials[ArSize];

    factorials[1] = factorials[0] = 1LL;    // 初始化

    for (int i = 2; i < ArSize; i++)        // 计算阶乘
        factorials[i] = i * factorials[i - 1];
    
    for (int i = 0; i < ArSize; i++)        // 打印结果
        std::cout << i << "! = " << factorials[i] << std::endl;
    
    return 0;
}

/*
0! = 1
1! = 1
2! = 2
3! = 6
4! = 24
5! = 120
6! = 720
7! = 5040
8! = 40320
9! = 362880
10! = 3628800
11! = 39916800
12! = 479001600
13! = 6227020800
14! = 87178291200
15! = 1307674368000
*/
