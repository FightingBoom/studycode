#include <iostream>

using namespace std;

int main()
{
    cout << "This program may reformat your hard disk\n"
            "and destroy all your data.\n"
            "Do you wish to continue? <y/n> ";
    
    char ch;
    cin >> ch;

    if ('y' == ch || 'Y' == ch)
        cout << "You were warned!\a\a\n";
    else if ('n' == ch || 'N' == ch)
        cout << "A wise choice ... bye\n";
    else
        cout << "That wasn't a y or n! Apparently you "
                "can't follow\ninstructions, so "
                "I'll trash your disk anyway.\a\a\a\n";

    return 0;
}

/*
This program may reformat your hard disk
Do you wish to continue? <y/n> y
You were warned!

This program may reformat your hard disk
Do you wish to continue? <y/n> Y
You were warned!

This program may reformat your hard disk
Do you wish to continue? <y/n> n
A wise choice ... bye

This program may reformat your hard disk
and destroy all your data.
Do you wish to continue? <y/n> N
A wise choice ... bye

This program may reformat your hard disk
and destroy all your data.
Do you wish to continue? <y/n> Yes
You were warned!

This program may reformat your hard disk
and destroy all your data.
Do you wish to continue? <y/n> No
A wise choice ... bye
*/
