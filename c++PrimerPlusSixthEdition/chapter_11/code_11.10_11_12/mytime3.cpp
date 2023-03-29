#include <iostream>
#include "mytime3.h"

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

Time Time::operator+(const Time & t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes; // 计算两个对象总分钟
    sum.hours = hours + t.hours + sum.minutes / 60; // 利用分钟整除，求出小时
    sum.minutes %= 60; // 计算剩余分钟数（未满一小时）
    return sum;
}

Time Time::operator-(const Time & t) const
{
    Time diff;
    int tot1, tot2;
    tot1 = t.minutes + 60 * t.hours;
    tot2 = minutes + 60 * hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

Time Time::operator*(double mult) const
{
    Time result;
    long totalminutes = hours * mult * 60 + minutes * mult; // 计算当前时间乘以影响因子
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

// 友元函数，并不在Time类的作用范围内
std::ostream & operator<<(std::ostream & os, const Time & t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os; // os为引用对象，因此返回的还是传入的参数；
}

