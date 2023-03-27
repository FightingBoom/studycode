#ifndef MYTIME3_H_
#define MYTIME3_H_

#include <iostream>

class Time
{
private:
    int hours;
    int minutes;

public:
    Time();
    Time(int h, int m = 0);

    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);

    Time operator+(const Time & t) const; // 将const关键字放在函数的括号后边，保证函数不会修改调用对象；
    Time operator-(const Time & t) const;
    Time operator*(double n) const;

    friend Time operator*(double m, const Time & t)
    {
        return t * m; // 调用内置重载
    }

    friend std::ostream & operator<<(std::ostream & os, const Time & t); // 返回值为ostream，方便输出非Time类型的打印

    // void Show() const; // 重载<<后，可以不需要show
};

#endif
