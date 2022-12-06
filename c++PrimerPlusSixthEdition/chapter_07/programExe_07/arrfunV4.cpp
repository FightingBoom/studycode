#include <iostream>

using namespace std;

const int Max = 5;

double * fill_array(double ar[], double * end);
void show_array(const double ar[], double * end);
void revalue(double r, double ar[], double * end);

int main()
{
    double properties[Max];

    double *pEnd = fill_array(properties, properties + Max);
    show_array(properties, pEnd);
    if (pEnd > properties)
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
        revalue(factor, properties, pEnd);
        show_array(properties, pEnd);
    }

    cout << "Done.\n";
    // cin.get(); // 清空输入缓冲区的换行符
    // cin.get(); // 保持窗口输入，避免无法看到结果窗口就消失了

    return 0;
}

double * fill_array(double ar[], double * end)
{
    double temp;

    while (ar < end)
    {
        cout << "Enter value: ";
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
        *ar = temp; // 成功获取输入
        ar++;
    }

    return ar; // 返回实际输入的数组个数
}

void show_array(const double ar[], double * end)
{
    for (; ar < end; ar++)
    {
        cout << "Property: $";
        cout << *ar << endl;
    }
}

void revalue(double r, double ar[], double * end)
{
    for (; ar < end; ar++)
        *ar *= r;
}

/*
# 正常输入
Enter value: 100000
Enter value: 80000
Enter value: 222000
Enter value: 240000
Enter value: 118000
Property: $100000
Property: $80000
Property: $222000
Property: $240000
Property: $118000
Enter revaluation factor: 0.8
Property: $80000
Property: $64000
Property: $177600
Property: $192000
Property: $94400
Done.


# 输入负数
Enter value: 20000
Enter value: 84000
Enter value: 160000
Enter value: -2
exit cin
Property: $20000
Property: $84000
Property: $160000
Enter revaluation factor: 1.3
Property: $26000
Property: $109200
Property: $208000
Done.

# 数组输入非数字
Enter value: werwf  
Bad input; input process terminated.
Done.


# 计算因子输入非数字
Enter value: 123
Enter value: 234
Enter value: 345
Enter value: 456
Enter value: 567
Property: $123
Property: $234
Property: $345
Property: $456
Property: $567
Enter revaluation factor: a
Bad input; Please enter a number: a
Bad input; Please enter a number: fssfe
Bad input; Please enter a number: -1
Property: $-123
Property: $-234
Property: $-345
Property: $-456
Property: $-567
Done.
*/

