#include <iostream>
#include "mytime0.h"

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60; // 利用整除，计算小时
    minutes %= 60; // 利用求模，计算分钟
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time Time::Sum(const Time & t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes; // 计算两个对象总分钟
    sum.hours = hours + t.hours + sum.minutes / 60; // 利用分钟整除，求出小时
    sum.minutes %= 60; // 计算剩余分钟数（未满一小时）
    return sum;
}

void Time::Show() const
{
    std::cout << hours << " hours, " << minutes << " minutes";
}

