#include <iostream>
#include <string>       // C++ 风格标准 string 头文件
#include <cstring>      // C 风格标准 string 头文件

int main()
{
    using namespace std;

    char charr1[20];
    char charr2[20] = "jaguar";
    string str1;
    string str2 = "panther";

    str1 = str2;
    strcpy(charr1, charr2);

    str1 += " paste";
    strcat(charr1, " juice");

    int len1 = str1.size();
    int len2 = strlen(charr1);

    cout << "The string " << str1 << " contains " << len1 << " characters.\n";
    cout << "The string " << charr1 << " contains " << len2 << " characters.\n";
    
    return 0;
}


/*
The string panther paste contains 13 characters.
The string jaguar juice contains 12 characters.
*/
