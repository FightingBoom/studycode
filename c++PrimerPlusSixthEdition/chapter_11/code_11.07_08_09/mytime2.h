#ifndef MYTIME2_H_
#define MYTIME2_H_

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

    void Show() const;
};

#endif
