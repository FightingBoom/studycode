#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    cout << "Enter text for analysis, and type @ to terminate input.\n";

    char ch;
    int whitespace = 0;
    int digits = 0;
    int chars = 0;
    int punct = 0;
    int others = 0;

    cin.get(ch);
    while ('@' != ch)
    {
        if (isalpha(ch))        // 字符
            chars++;
        else if (isspace(ch))   // 空格、回车、换行符等
            whitespace++;
        else if (isdigit(ch))   // 数字
            digits++;
        else if (ispunct(ch))   // 标点符号
            punct++;
        else
            others++;
        
        cin.get(ch);
    }

    cout << chars << " letters, "
        << whitespace << " whitespace, "
        << digits << " digits, "
        << punct << " punctuations, "
        << others << " others.\n";
    
    return 0;
}

/*
Enter text for analysis, and type @ to terminate input.
This is a test
next new line.
input @ to stop.
27 letters, 8 whitespace, 0 digits, 1 punctuations, 0 others.
*/
