#include <iostream>

using namespace std;

int main()
{
    int iCount = 0;
    unsigned int uiCount = 0;

    iCount = INT32_MAX;     // 有符号数，加一，会变为负数
    iCount += 1;
    cout << "MAX:" << INT32_MAX << " iCount(MAX + 1) = " << iCount << endl;

    uiCount = INT32_MAX;
    uiCount += 1;
    cout << "MAX:" << INT32_MAX << ", uiCount(MAX + 1) = " << uiCount << endl;

    uiCount = UINT32_MAX;   // 无符号数，加一，从0开始
    uiCount += 1;
    cout << "MAX:" << INT32_MAX << ", uiCount(MAX + 1) = " << uiCount << endl;


    cout << "iCount = " << iCount << ", uiCount = " << uiCount << endl;

    return 0;
}


/*
MAX:2147483647 iCount(MAX + 1) = -2147483648
MAX:2147483647, uiCount(MAX + 1) = 2147483648
MAX:2147483647, uiCount(MAX + 1) = 0
iCount = -2147483648, uiCount = 0
*/
