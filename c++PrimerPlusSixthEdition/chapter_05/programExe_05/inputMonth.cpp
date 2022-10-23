#include <iostream>
#include <string>

using namespace std;

const int MONTH = 12;

int main()
{
    string strMonth[MONTH] = 
    {
        "January",      // 一月
        "February",     // 二月
        "March",        // 三月
        "April",        // 四月
        "May",          // 五月
        "June",         // 六月
        "July",         // 七月
        "August",       // 八月
        "September",    // 九月
        "October",      // 十月
        "November",     // 十一月
        "December"      // 十二月
    };

    int iEveryMonthSales[MONTH] = {0};  // 存储每月销量
    int iSumSales = 0;                  // 总销量

    for (int i = 0; i < MONTH; i++)
    {
        cout << "Please enter the book sales volume in " << strMonth[i] << ": ";
        cin >> iEveryMonthSales[i];
        iSumSales += iEveryMonthSales[i];
    }

    cout << "the book total sales volume is " << iSumSales << endl;

    return 0;
}


/*
Please enter the book sales volume in January: 1
Please enter the book sales volume in February: 2
Please enter the book sales volume in March: 3
Please enter the book sales volume in April: 4
Please enter the book sales volume in May: 5
Please enter the book sales volume in June: 6
Please enter the book sales volume in July: 7
Please enter the book sales volume in August: 8
Please enter the book sales volume in September: 9
Please enter the book sales volume in October: 10
Please enter the book sales volume in November: 11
Please enter the book sales volume in December: 12
the book total sales volume is 78
*/

