#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>

class Stock
{
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; } // C++默认将短小的成员函数作为内联函数

public:
    void acquire(const std::string & co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show(void); // 原文没有void
};

#endif // !STOCK00_H_
