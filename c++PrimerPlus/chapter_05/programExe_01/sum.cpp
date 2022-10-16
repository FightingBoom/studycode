#include <iostream>

using namespace std;

int main()
{
    int a = 0;      // 整数1
    int b = 0;      // 整数2
    int sum = 0;    // 求和结果

    cout << "Please enter start a: ";
    cin >> a;
    
    cout << "Please enter end b: ";
    cin >> b;

    cout << "sum = " << a << " ~ " << b << endl;
    for (int i = a; i <= b; ++i)    // 以a开始，到b结束，sum依次与每个值相加
    {
        sum += i;
        cout << "sum = " << sum << endl;
    }
    
    cout << "sum = " << sum << endl;
}


/*
Please enter start a: 2
Please enter end b: 9
sum = 2 ~ 9
sum = 2
sum = 5
sum = 9
sum = 14
sum = 20
sum = 27
sum = 35
sum = 44
sum = 44
*/
