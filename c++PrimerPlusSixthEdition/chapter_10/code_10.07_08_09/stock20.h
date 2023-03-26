#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>

class Stock
{
private:
    std::string company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; } // C++默认将短小的成员函数作为内联函数

public:
    Stock();
    Stock(const std::string & co, long n = 0, double pr = 0.0);
    ~Stock();

    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show(void) const; // 原文没有void
    const Stock & topval(const Stock & s) const; // 将const关键字放在函数的括号后边，保证函数不会修改调用对象；
};

#endif // !STOCK00_H_
