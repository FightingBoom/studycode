#include <iostream>

int main()
{
    using namespace std;

    cout << "What year was your house built?\n";
    
    int year;
    // cin >> year;    // 原始方法

    // cin >> year;    // 方法一
    // cin.get();      // 方法一

    (cin >> year).get();    // 方法二

    cout << "What is its street address?\n";
    char address[80];
    cin.getline(address, 80);

    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;
    cout << "Done!\n";

    return 0;
}


/* 原始方法
What year was your house built?
1966
What is its street address?
Year built: 1966
Address:
Done!
*/


/* 方法一
What year was your house built?
1966
What is its street address?
43821 Unsigned Short Street
Year built: 1966
Address: 43821 Unsigned Short Street
Done!
*/


/* 方法二
What year was your house built?
1966
What is its street address?
43821 Unsigned Short Street
Year built: 1966
Address: 43821 Unsigned Short Street
Done!
*/


/*
1、cin 输入会把换行符留在输入缓冲区，因此第二次获取输入时，首先获取到的就是换行符，导致还没输入就直接结束了；
2、加上后边习题的经验，有两种方法
（1）获取输入之后，再次 get 一次，把换行符读出来，保持输入缓冲区无其他内容；
（2）获取输入之后，clear 清空缓冲区，然后 sync 同步缓冲区更改，这样也能保证缓冲区无其他内容；
*/
