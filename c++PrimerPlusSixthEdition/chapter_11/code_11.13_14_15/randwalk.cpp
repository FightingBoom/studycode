#include <iostream>
#include <cstdlib>  // rand() srand() prototypes
#include <ctime>    // time() prototype
#include "vector.h"

int main()
{
    using namespace std;
    using VECTOR::Vector;

    srand(time(0)); // 使用系统时间初始化随机数
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    
    cout << "Enter target distance (q to quit): ";
    while (cin >> target) // 目标距离
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep)) // 步长
            break;
        
        while (result.magval() < target) // 未达到目标距离
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL); // 初始化为向量方式
            result = result + step;
            steps++;
        }

        cout << "After " << steps << " steps, the subject "
            "has the following location:\n";
        cout << result << endl; // 默认用RECT，直角坐标系显示
        result.polar_mode();    // 显式设置为POL，向量方式
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step = "
            << result.magval() / steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }

    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;

    return 0;
}

/*
Enter target distance (q to quit): 50
Enter step length: 2
After 250 steps, the subject has the following location:
(x,y) = (-47.6886, -19.0347)
 or
(m, a) = (51.3471, -158.241)
Average outward distance per step = 0.205388
Enter target distance (q to quit): 50
Enter step length: 2
After 302 steps, the subject has the following location:
(x,y) = (-18.7946, 48.1892)
 or
(m, a) = (51.7246, 111.307)
Average outward distance per step = 0.171274
Enter target distance (q to quit): 50
Enter step length: 1
After 2613 steps, the subject has the following location:
(x,y) = (-48.7345, -14.2857)
 or
(m, a) = (50.7852, -163.662)
Average outward distance per step = 0.0194356
Enter target distance (q to quit): q
Bye!
*/
