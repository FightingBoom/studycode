#include <iostream>

using namespace std;

double ProcessAverage(double x, double y);

int main()
{
    double x;
    double y;
    double average;

    cout << "Enter x, y: ";
    cin >> x >> y;
    while ((0 != x) && (0 != y))
    {
        average = ProcessAverage(x, y);
        cout << "x=" << x << ", y=" << y << ", average=" << average << endl;
        cout << "Enter next x, y: ";
        cin >> x >> y;
    }

    cout << "Done." << endl;
    return 0;
}

double ProcessAverage(double x, double y)
{
    return 2.0 * x * y / (x + y);
}

/*
Enter x, y: 1 1
x=1, y=1, average=1
Enter next x, y: 1 2
x=1, y=2, average=1.33333
Enter next x, y: 1 3
x=1, y=3, average=1.5
Enter next x, y: 1212 2131231
x=1212, y=2.13123e+06, average=2422.62
Enter next x, y: 123
243
x=123, y=243, average=163.328
Enter next x, y: 123 0
*/

/*
Enter x, y: 12 213
x=12, y=213, average=22.72
Enter next x, y: 12341
123123
x=12341, y=123123, average=22433.4
Enter next x, y: 241
12120231
x=241, y=1.21202e+07, average=481.99
Enter next x, y: 23
45
x=23, y=45, average=30.4412
Enter next x, y: 21 0
Done.
*/
