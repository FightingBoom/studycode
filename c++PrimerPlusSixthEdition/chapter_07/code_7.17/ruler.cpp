#include <iostream>

using namespace std;

const int Len = 66;
const int Divs = 6;

void subdivide(char ar[], int low, int high, int level);

int main()
{
    char ruler[Len]; // 待递归数组
    int i;
    for (i = 1; i < Len - 2; i++)
        ruler[i] = ' ';

    ruler[Len - 1] = '\0';
    int max = Len - 2;
    int min = 0;
    ruler[min] = ruler[max] = '|';
    cout << ruler << endl;

    for (i = 1; i <= Divs; i++)
    {
        subdivide(ruler, min, max, i);
        cout << ruler << endl;
        for (int j = 1; j < Len - 2; j++)
            ruler[j] = ' ';
    }

    return 0;
}

void subdivide(char ar[], int low, int high, int level)
{
    if (0 == level)
        return;

    int mid = (high + low) / 2;
    ar[mid] = '|';
    subdivide(ar, low, mid, level - 1);
    subdivide(ar, mid, high, level - 1);
}

/*
|                                                               | # 第一行打印，min/max为|
|                               |                               | # 第一层，调用一次函数，打出中间值
|               |               |               |               | # 第二层，调用两次，同样会打印中间值
|       |       |       |       |       |       |       |       | # ...依次类推
|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
*/
