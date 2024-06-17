#include <iostream>
#include <valarray>
#include <cstdlib>

const int SIZE = 12;

typedef std::valarray<int> vint;

void show(const vint & v, int cols);

int main()
{
    // valarray数组切片
    // slice(<起始位置>, <大小/元素个数>, <步长>)
    using std::slice;
    using std::cout;
    vint valint(SIZE);

    int i;
    for (i = 0; i < SIZE; ++i)
    {
        valint[i] = std::rand() % 10;
    }
    cout << "Original array:\n";
    show(valint, 3); // 原始数据输出三行展示

    // 从索引1开始，大小为4，步长为3的切片
    vint vcol(valint[slice(1,4,3)]);    // 第二列
    cout << "Second column:\n";
    show(vcol, 1);

    // 从索引3开始，大小为3，步长为1的切片
    vint vrow(valint[slice(3,3,1)]);    // 第二行
    cout << "Second row:\n";
    show(vrow, 3);

    // 将从索引2开始，大小为4，步长为3的切片，改为10
    valint[slice(2,4,3)] = 10;  // 第三列数据改为10
    cout << "Set last column to 10:\n";
    show(valint, 3);

    // 第一例设置为第二三列的和
    cout << "Set first column to sum of next two:\n";
    valint[slice(0,4,3)] = vint(valint[slice(1,4,3)])
        + vint(valint[slice(2,4,3)]);
    show(valint, 3);

    return 0;
}

void show(const vint & v, int cols)
{
    using std::cout;
    using std::endl;

    int lim = v.size();
    for (int i = 0; i < lim; ++i)
    {
        cout.width(3);
        cout << v[i];
        if (i % cols == cols - 1)
            cout << endl;
        else
            cout << ' ';
    }

    if (lim % cols != 0)
        cout << endl;
}

/*
zhaochen@zhaochendeMacBook-Air code_16.21 % clang++ vslice.cpp 
zhaochen@zhaochendeMacBook-Air code_16.21 % ./a.out 
Original array:
  7   9   3
  8   0   2
  4   8   3
  9   0   5
Second column:
  9
  0
  8
  0
Second row:
  8   0   2
Set last column to 10:
  7   9  10
  8   0  10
  4   8  10
  9   0  10
Set first column to sum of next two:
 19   9  10
 10   0  10
 18   8  10
 10   0  10
*/
