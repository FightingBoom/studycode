#include <iostream>
#include <string>

using namespace std;

void strcount(string str);

int main()
{
    string strInput;
    char next;

    cout << "Enter a line:\n";
    getline(cin, strInput);
    while (!strInput.empty())
    {
        strcount(strInput);
        cout << "Enter next line (empty line to quit):\n";
        getline(cin, strInput);
    }

    cout << "Bye\n";
    return 0;
}

void strcount(string str)
{
    static int total = 0; // 静态变量，只在开始初始化一次
    cout << "\"" << str.c_str() << "\" contains ";
    total += str.length();
    cout << str.length() << " characters\n";
    cout << total << " characters total\n";
}

/*
Enter a line:
1 3 5 7    
"1 3 5 7" contains 7 characters
7 characters total
Enter next line (empty line to quit):
hhhh hhhh hhhhhhh 
"hhhh hhhh hhhhhhh" contains 17 characters
24 characters total
Enter next line (empty line to quit):
ni hao
"ni hao" contains 6 characters
30 characters total
Enter next line (empty line to quit):

Bye
*/
