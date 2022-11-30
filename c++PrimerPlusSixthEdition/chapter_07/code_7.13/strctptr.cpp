#include <iostream>
#include <cmath>

using namespace std;

struct polar
{
    double distance;
    double angle;
};

struct rect
{
    double x; // 距原点横向距离
    double y; // 距原点纵向距离
};


void rect_to_polar(const rect *pxy, polar *pda);
void show_polar(const polar *dapos);

int main()
{
    rect rplace;
    polar pplace;

    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y)
    {
        rect_to_polar(&rplace, &pplace); // 传递原始数据指针
        show_polar(&pplace);
        cout << "Next two numbers (q to quit): "; // 实际只要为非数字输入，都会终止退出
    }
    cout << "Done.\n";
    return 0;
}

void rect_to_polar(const rect *pxy, polar *pda)
{
    pda->distance = sqrt(pxy->x * pxy->x + pxy->y * pxy->y);
    pda->angle = atan2(pxy->y, pxy->x);
}

void show_polar(const polar *dapos)
{
    const double Rad_to_deg = 57.29577951;

    cout << "distance = " << dapos->distance;
    cout << ", angle = " << dapos->angle * Rad_to_deg;
    cout << " degrees\n";
}

/*
Enter the x and y values: 30 40
distance = 50, angle = 53.1301 degrees
Next two numbers (q to quit): -100 100
distance = 141.421, angle = 135 degrees
Next two numbers (q to quit): q
Done.
*/
