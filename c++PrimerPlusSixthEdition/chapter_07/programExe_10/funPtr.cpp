#include <iostream>

using namespace std;

typedef double (*pFun)(double, double); // 定义为类型，比较方便理解

double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double calculate(double x, double y, pFun pFuntion);

int main()
{
    pFun pFunArray[3];
    pFunArray[0] = add;
    pFunArray[1] = subtract;
    pFunArray[2] = multiply;

    int x;
    int y;
    cout << "Enter x and y: ";

    while (1)
    {
        while (!(cin >> x >> y)) // 输入错误，非数字输入
        {
            cin.clear(); // 清空输入缓冲区
            while (cin.get() != '\n') // 循环读取，并丢弃无效的字符串
                continue;
            cout << "Bad input; Please enter number, x and y: ";
            // 无论此处是否跳出，外层循环一直都在；
        }
        double addNum = calculate(x, y, pFunArray[0]);
        cout << "add num = " << addNum << endl;

        double subtractNum = calculate(x, y, pFunArray[1]);
        cout << "subtract num = " << subtractNum << endl;

        double multiplyNum = calculate(x, y, pFunArray[2]);
        cout << "multiply num = " << multiplyNum << endl;

        cout << "Enter next x and y: ";
    }

    return 0;
}

double add(double x, double y)
{
    return x + y;
}

double subtract(double x, double y)
{
    return x - y;
}

double multiply(double x, double y)
{
    return x * y;
}

double calculate(double x, double y, pFun pFuntion)
{
    double result;
    result = pFuntion(x, y);
    return result;
}


/*
# 没有做其他退出手段
Enter x and y: 20 6
add num = 26
subtract num = 14
multiply num = 120
Enter next x and y: 34 2
add num = 36
subtract num = 32
multiply num = 68
Enter next x and y: 2 4
add num = 6
subtract num = -2
multiply num = 8
Enter next x and y: q
*/
