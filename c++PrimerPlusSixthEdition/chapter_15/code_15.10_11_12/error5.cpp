#include  <iostream>
#include <cmath>
#include <string>

#include "exc_mean.h"

class demo
{
private:
    std::string word;

public:
    demo(const std::string & str)
    {
        word = str;
        std::cout << "demo " << word << " created\n";
    }
    ~demo()
    {
        std::cout << "demo " << word << " destroyed\n";
    }

    // 函数后的const将this指针转换为常量指针
    void show() const
    {
        std::cout << "demo " << word << " lives!\n";
    }
};

double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    // 单独一个代码块，测试函数/类析构后的表现
    {
        demo d1("found in block in main()");
        cout << "Enter two numbers: ";

        while (cin >> x >> y)
        {
            try
            {
                z = means(x, y);
                cout << "The mean mean of " << x <<
                    " and " << y << " is " << z << endl;
                cout << "Enter next pair: ";
            }
            catch(bad_hmean & bg)
            {
                bg.mesg();
                cout << "Try again.\n";
                continue;
            }
            catch (bad_gmean & hg)
            {
                cout << hg.mesg();
                cout << "Values used: " << hg.v1 << ", "
                    << hg.v2 << endl;
                cout << "Sorry, you don't get to play "
                    "any more.\n";
                break;
            }
        }

        d1.show();
        // 代码块结束后，局部变量进入析构函数
    }

    cout << "Bye!\n";
    cin.get();
    cin.get();  // 获取输入，避免结果窗口消失

    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean(a, b);

    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);

    return std::sqrt(a * b);
}

double means(double a, double b)
{
    double am, hm, gm;
    demo d2("found in means()");

    am = (a + b) / 2.0;

    try
    {
        hm = hmean(a, b);
        gm = gmean(a, b);
    }
    catch (bad_hmean & bg)
    {
        bg.mesg();
        std::cout << "Caught in means()\n";
        throw;
    }

    d2.show();

    return (am + hm + gm) / 3.0;
}

/*
zhaochen@zhaochendeAir code_15.10_11_12 % ./a.out 
demo found in block in main() created
Enter two numbers: 6 12
demo found in means() created
demo found in means() lives!
demo found in means() destroyed
The mean mean of 6 and 12 is 8.49509
Enter next pair: 6 -6
demo found in means() created
hmean(6, -6): invalid arguments: a = -b
Caught in means()
demo found in means() destroyed
hmean(6, -6): invalid arguments: a = -b
Try again.
6 -8
demo found in means() created
demo found in means() destroyed
gmean() arguments should be >= 0
Values used: 6, -8
Sorry, you don't get to play any more.
demo found in block in main() lives!
demo found in block in main() destroyed
Bye!

zhaochen@zhaochendeAir code_15.10_11_12 %
*/
