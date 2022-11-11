#include <iostream>
#include <array>

using namespace std;

const int MAX_SIZE = 10;

int main()
{
    int totalInput = 0; // 输入总数据个数
    int validInput = 0; // 大于平均值的有效数据个数
    double dSum = 0.0;  // 输入总数据之和
    array<double, MAX_SIZE> doubleBuffer;

    for (totalInput = 0; totalInput < MAX_SIZE; totalInput++)
    {
        cin >> doubleBuffer[totalInput];
        if (cin.fail())
            break;

        dSum += doubleBuffer[totalInput];
    }

    double dAverage = dSum / totalInput;    // 计算输入数据平均值
    cout << "dAverage = " << dAverage << endl;;

    for (int i = 0; i < totalInput; i++)
    {
        if (doubleBuffer[i] > dAverage)
            validInput++;
    }

    cout << "Total input " << totalInput << " numbers, dAverage = "
        << dAverage << ", Have " << validInput << " is greater than dAverage.\n";

    return 0;
}

/*
1.1 2.2 3.3 4.4 5.5 6.6 end
dAverage = 3.85
Total input 6 numbers, dAverage = 3.85, Have 3 is greater than dAverage.

------------------

1 3 5 8.8 9 100 231 150 325 323 234
dAverage = 115.58
Total input 10 numbers, dAverage = 115.58, Have 4 is greater than dAverage.
*/
