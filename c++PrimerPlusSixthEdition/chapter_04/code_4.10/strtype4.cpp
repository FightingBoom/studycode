#include <iostream>
#include <string>       // C++ 风格标准 string 头文件
#include <cstring>      // C 风格标准 string 头文件

int main()
{
    using namespace std;

    char charr[20];
    string str;

    cout << "Length of string in charr before input: " << strlen(charr) << endl;
    cout << "Length of string in str before input: " << str.size() << endl;

    cout << "Enter a line of text:\n";
    cin.getline(charr, 20);
    cout << "You entered: " << charr << endl;

    cout << "Enter another line of text:\n";
    getline(cin, str);      // string 类型获取整行输入新方式
    cout << "You entered: " << str << endl;

    cout << "Length of string in charr before input: " << strlen(charr) << endl;
    cout << "Length of string in str before input: " << str.size() << endl;

    return 0;
}


/*
Length of string in charr before input: 1
Length of string in str before input: 0
Enter a line of text:
peanut butter
You entered: peanut butter
Enter another line of text:
blueberry jam
You entered: blueberry jam
Length of string in charr before input: 13
Length of string in str before input: 13
*/
