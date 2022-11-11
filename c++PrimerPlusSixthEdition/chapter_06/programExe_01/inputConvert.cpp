#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    cout << "Enter text for analysis, and type @ to terminate input.\n";

    char ch;
    cin.get(ch);

    while ('@' != ch)
    {
        if (!isdigit(ch))   // 非数字，特殊回显
        {
            if (isupper(ch))
                cout << (char)tolower(ch);
            else if (islower(ch))
                cout << (char)toupper(ch);
            else
                cout << ch;
        }
        // else // 如果需要数字回显，可以放开；
        // {
        //     cout << ch;
        // }

        cin.get(ch);
    }

    return 0;
}


/*
Enter text for analysis, and type @ to terminate input.
hello, this is 11.11
HELLO, THIS IS 11.11
Interview is GOOD!
iNTERVIEW IS good!
input @ to end!!!
INPUT

---------------------------

Enter text for analysis, and type @ to terminate input.
hello, this is 11.11 
HELLO, THIS IS .
Interview is Good! 
iNTERVIEW IS gOOD!
input @ to end!!!
INPUT
*/












