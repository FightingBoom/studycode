#include <iostream>
#include <string>

using namespace std;

const int YEAR = 3;     // 总计三年
const int MONTH = 12;   // 每年12个月

int main()
{
    // string strMonth[YEAR][MONTH] =   // 此方式会导致大量重复代码
    // {
    //     {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"},
    //     {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"},
    //     {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"},
    // };

    string strYear[YEAR] = 
    {
        "First year",       // 第一年
        "Second year",      // 第二年
        "The third year"    // 第三年
    };

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

    int iEveryMonthSales[MONTH] = {0};      // 存储每月销量
    int iEveryYearSumSales[YEAR] = {0};     // 一年总销量
    int iThreeYearSumSales = 0;             // 三年总销量

    for (int j = 0; j < YEAR; j++)
    {
        for (int i = 0; i < MONTH; i++)
        {
            cout << "Please enter the book sales volume in " << strYear[j] << " " << strMonth[i] << ": ";
            cin >> iEveryMonthSales[i];
            iEveryYearSumSales[j] += iEveryMonthSales[i];
        }
        iThreeYearSumSales += iEveryYearSumSales[j];
    }

    for (int i = 0; i < YEAR; i++)
        cout << "the book total sales volume in " << strYear[i] << " is " << iEveryYearSumSales[i] << endl;
    
    cout << "the book total sales volume in three year is " << iThreeYearSumSales << endl;

    return 0;
}


/*
Please enter the book sales volume in First year January: 1
Please enter the book sales volume in First year February: 1
Please enter the book sales volume in First year March: 1
Please enter the book sales volume in First year April: 1
Please enter the book sales volume in First year May: 1
Please enter the book sales volume in First year June: 1
Please enter the book sales volume in First year July: 1
Please enter the book sales volume in First year August: 1
Please enter the book sales volume in First year September: 1
Please enter the book sales volume in First year October: 1
Please enter the book sales volume in First year November: 1
Please enter the book sales volume in First year December: 1
Please enter the book sales volume in Second year January: 1
Please enter the book sales volume in Second year February: 1
Please enter the book sales volume in Second year March: 1
Please enter the book sales volume in Second year April: 1
Please enter the book sales volume in Second year May: 1
Please enter the book sales volume in Second year June: 1
Please enter the book sales volume in Second year July: 1
Please enter the book sales volume in Second year August: 1
Please enter the book sales volume in Second year September: 1
Please enter the book sales volume in Second year October: 1
Please enter the book sales volume in Second year November: 1
Please enter the book sales volume in Second year December: 1
Please enter the book sales volume in The third year January: 1
Please enter the book sales volume in The third year February: 1
Please enter the book sales volume in The third year March: 1
Please enter the book sales volume in The third year April: 1
Please enter the book sales volume in The third year May: 1
Please enter the book sales volume in The third year June: 1
Please enter the book sales volume in The third year July: 1
Please enter the book sales volume in The third year August: 1
Please enter the book sales volume in The third year September: 1
Please enter the book sales volume in The third year October: 1
Please enter the book sales volume in The third year November: 1
Please enter the book sales volume in The third year December: 1
the book total sales volume in First year is 12
the book total sales volume in Second year is 12
the book total sales volume in The third year is 12
the book total sales volume in three year is 36


Please enter the book sales volume in First year January: 12
Please enter the book sales volume in First year February: 312
Please enter the book sales volume in First year March: 4124
Please enter the book sales volume in First year April: 3223
Please enter the book sales volume in First year May: 423
Please enter the book sales volume in First year June: 34
Please enter the book sales volume in First year July: 543
Please enter the book sales volume in First year August: 432
Please enter the book sales volume in First year September: 43
Please enter the book sales volume in First year October: 35
Please enter the book sales volume in First year November: 65
Please enter the book sales volume in First year December: 85
Please enter the book sales volume in Second year January: 345
Please enter the book sales volume in Second year February: 54
Please enter the book sales volume in Second year March: 34
Please enter the book sales volume in Second year April: 554
Please enter the book sales volume in Second year May: 657
Please enter the book sales volume in Second year June: 5
Please enter the book sales volume in Second year July: 44
Please enter the book sales volume in Second year August: 345
Please enter the book sales volume in Second year September: 36
Please enter the book sales volume in Second year October: 34
Please enter the book sales volume in Second year November: 56
Please enter the book sales volume in Second year December: 43
Please enter the book sales volume in The third year January: 78
Please enter the book sales volume in The third year February: 6
Please enter the book sales volume in The third year March: 123
Please enter the book sales volume in The third year April: 24
Please enter the book sales volume in The third year May: 46
Please enter the book sales volume in The third year June: 856
Please enter the book sales volume in The third year July: 32354 
Please enter the book sales volume in The third year August: 543
Please enter the book sales volume in The third year September: 466
Please enter the book sales volume in The third year October: 745
Please enter the book sales volume in The third year November: 325
Please enter the book sales volume in The third year December: 3434
the book total sales volume in First year is 9331
the book total sales volume in Second year is 2207
the book total sales volume in The third year is 39000
the book total sales volume in three year is 50538
*/

