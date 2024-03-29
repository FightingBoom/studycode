#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode {RECT, POL};
    private:
        double x;
        double y;
        double mag;
        double ang;
        Mode mode;

        void set_mag();
        void set_nag();
        void set_x();
        void set_y();
    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT); // 默认使用直角坐标
        ~Vector();

        void reset(double n1, double n2, Mode form = RECT); // 默认使用直角坐标

        double xval() const {return x;}
        double yval() const {return y;}
        double magval() const {return mag;}
        double angval() const {return ang;}

        void polar_mode();
        void rect_mode();

        Vector operator+(const Vector & b) const;
        Vector operator-(const Vector & b) const; // 重载
        Vector operator-() const;
        Vector operator*(double n) const;

        friend Vector operator*(double n, const Vector & a); // 友元函数
        friend std::ostream & operator<<(std::ostream & os, const Vector & v); // 友元
    };
}

#endif // !VECTOR_H_H
