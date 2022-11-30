#include <iostream>

using namespace std;

const int Max = 5;

int fill_array(double ar[], int limit);
void show_array(const double ar[], int n);
void revalue(double r, double ar[], int n);

int main()
{
    double properties[Max];

    int size = fill_array(properties, Max);
    show_array(properties, size);
    if (size > 0)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor)) // 输入错误，非数字输入
        {
            cin.clear(); // 清空输入缓冲区
            while (cin.get() != '\n') // 循环读取，并丢弃无效的字符串
                continue;
            cout << "Bad input; Please enter a number: ";
        }
        revalue(factor, properties, size);
        show_array(properties, size);
    }

    cout << "Done.\n";
    // cin.get(); // 清空输入缓冲区的换行符
    // cin.get(); // 保持窗口输入，避免无法看到结果窗口就消失了

    return 0;
}

int fill_array(double ar[], int limit)
{
    double temp;
    int i;

    for (i = 0; i < limit; i++)
    {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin) // 输入错误，非数字输入
        {
            cin.clear(); // 清空输入缓冲区
            while (cin.get() != '\n') // 循环读取，并丢弃无效的字符串
                continue;
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0)
        {
            cout << "exit cin\n";
            break;
        }
        ar[i] = temp;
    }

    return i; // 返回实际输入的数组个数
}

void show_array(const double ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Property #" << (i + 1) << ": $";
        cout << ar[i] << endl;
    }
}

void revalue(double r, double ar[], int n)
{
    for (int i = 0; i < n; i++)
        ar[i] *= r;
}

/*
# 正常输入
Enter value #1: 100000
Enter value #2: 80000
Enter value #3: 222000
Enter value #4: 240000
Enter value #5: 118000
Property #1: $100000
Property #2: $80000
Property #3: $222000
Property #4: $240000
Property #5: $118000
Enter revaluation factor: 0.8
Property #1: $80000
Property #2: $64000
Property #3: $177600
Property #4: $192000
Property #5: $94400
Done.


# 输入负数
Enter value #1: 20000
Enter value #2: 84000
Enter value #3: 160000
Enter value #4: -2
exit cin
Property #1: $20000
Property #2: $84000
Property #3: $160000
Enter revaluation factor: 1.2 
Property #1: $24000
Property #2: $100800
Property #3: $192000
Done.


# 数组输入非数字
Enter value #1: sfa
Bad input; input process terminated.
Done.


# 计算因子输入非数字
Enter value #1: 12310
Enter value #2: 12412341
Enter value #3: 2131
Enter value #4: 124214
Enter value #5: 214325352
Property #1: $12310
Property #2: $1.24123e+07
Property #3: $2131
Property #4: $124214
Property #5: $2.14325e+08
Enter revaluation factor: a
Bad input; Please enter a number: fsd
Bad input; Please enter a number: 12
Property #1: $147720
Property #2: $1.48948e+08
Property #3: $25572
Property #4: $1.49057e+06
Property #5: $2.5719e+09
Done.
*/

