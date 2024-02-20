#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <string>
#include <valarray>

class Student
{
private:
    // 私有类型定义，仅能在类内使用
    typedef std::valarray<double> ArrayDb;

    std::string name;
    ArrayDb scores;

    // 私有接口，格式化打印valarray数据
    std::ostream & arr_out(std::ostream & os) const;

public:
    Student()
        : name("Null Student"), scores(){}

    // explicit禁止隐式调用构造函数，但允许显式调用
    explicit Student(const std::string & s)
        : name(s), scores() {}

    explicit Student(int n)
        : name("Nully"), scores(n) {}

    Student(const std::string & s, int n)
        : name(s), scores(n) {}

    Student(const std::string & s, const ArrayDb & a)
        : name(s), scores(a) {}

    Student(const char * str, const double * pd, int n)
        : name(str), scores(pd, n) {}

    ~Student() {}

    double Average() const;
    const std::string & Name() const;
    double & operator[](int i);
    double operator[](int i) const;

    // 友元函数 输入字符
    friend std::istream & operator>>(std::istream & is, Student & stu);
    // 输入一行
    friend std::istream & getling(std::istream & is, Student & stu);
    // 输出
    friend std::ostream & operator<<(std::ostream & os, const Student & stu);
};

#endif
