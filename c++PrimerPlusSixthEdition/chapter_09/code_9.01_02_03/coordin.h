#ifndef COORDIN_H_
#define COORDIN_H_

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

polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif // !COORDIN_H_