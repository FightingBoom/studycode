#include <iostream>

const int ArSize = 10;

void strcount(const char * str);

int main()
{
    using namespace std;
    char input[ArSize];
    char next;

    cout << "Enter a line:\n";
    cin.get(input, ArSize);
    while (cin)
    {
        cin.get(next);
        while (next != '\n')
            cin.get(next);
        strcount(input);

        cout << "Enter next line (empty line to quit):\n";
        cin.get(input, ArSize);
    }

    cout << "Bye\n";
    return 0;
}

void strcount(const char * str)
{
    using namespace std;
    static int total = 0; // 静态变量，只在开始初始化一次
    int count = 0;

    cout << "\"" << str << "\" contains ";
    while (*str++)
        count ++;

    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}

/*
Enter a line:
nice pants
"nice pant" contains 9 characters
9 characters total
Enter next line (empty line to quit):
thanks
"thanks" contains 6 characters
15 characters total
Enter next line (empty line to quit):
partiing is such sweet sorrow
"partiing " contains 9 characters
24 characters total
Enter next line (empty line to quit):
ok
"ok" contains 2 characters
26 characters total
Enter next line (empty line to quit):
q
"q" contains 1 characters
27 characters total
Enter next line (empty line to quit):

Bye
*/
