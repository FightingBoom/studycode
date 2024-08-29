#include <iostream>
#include <string>

// 无参数
void show_list() {}

// 一个参数
template<typename T>
void show_list(const T & value)
{
    std::cout << value << '\n';
}

// 2个以上参数
template<typename T, typename... Args>
void show_list(const T & value, const Args&... args)
{
    std::cout << value << ", ";
    show_list(args...);
}

int main()
{
    int n = 14;
    double x = 2.71828;
    std::string mr = "Mr. String objects!";
    show_list(n, x);
    show_list(x * x, '!', 7, mr);

    return 0;
}

/*
zhaochen@zhaochendeAir code_18.10 % clang++ variadic2.cpp -std=c++11
zhaochen@zhaochendeAir code_18.10 % ./a.out 
14, 2.71828
7.38905, !, 7, Mr. String objects!
zhaochen@zhaochendeAir code_18.10 %
*/
