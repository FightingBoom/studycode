#include <iostream>

using namespace std;

struct job
{
    char name[40];
    double salary;
    int floor;
};

template <typename T>
void Swap(T &a, T &b);

template <> void Swap<job>(job &j1, job &j2);
void Show(job &j);

int main()
{
    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);

    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap(i, j);
    cout << "Now i, j = " << i << ", " << j << ".\n";

    job sue = {"Susan Yaffee", 73000.60, 7};
    job sidney = {"Sidney Taffee", 78060.72, 9};
    cout << "Before job swapping:\n";
    Show(sue);
    Show(sidney);
    Swap(sue, sidney);
    cout << "After job swapping:\n";
    Show(sue);
    Show(sidney);

    return 0;
}

// 显式实例化，通用的函数模板定义，只是提前传入类型；template 即可
template <typename T>
void Swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

// 显式具体化，函数模板，在定义模板时，直接明确类型，需要<>
template <> void Swap<job>(job &j1, job &j2)
{
    double t1;
    t1 = j1.salary;
    j1.salary = j2.salary;
    j2.salary = t1;

    int t2;
    t2 = j1.floor;
    j1.floor = j2.floor;
    j2.floor = t2;
}

void Show(job &j)
{
    cout << j.name << ": $" << j.salary << " on floor " << j.floor << endl;
}

/*
i, j = 10, 20.
Using compiler-generated int swapper:
Now i, j = 20, 10.
Before job swapping:
Susan Yaffee: $73000.60 on floor 7
Sidney Taffee: $78060.72 on floor 9
After job swapping:
Susan Yaffee: $78060.72 on floor 9
Sidney Taffee: $73000.60 on floor 7
*/
