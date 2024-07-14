#include <iostream>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    char ch;

    while (cin.get(ch))
    {
        if (ch != '#')
        {
            cout << ch;
        }
        else
        {
            cin.putback(ch);
            break;
        }
    }

    if (!cin.eof())
    {
        cin.get(ch);
        cout << endl << ch << " is next input character.\n";
    }
    else
    {
        cout << "End of file reached.\n";
        std::exit(0);
    }

    while (cin.peek() != '#')
    {
        cin.get(ch);
        cout << ch;
    }

    if (!cin.eof())
    {
        cin.get(ch);
        cout << endl << ch << " is next input character.\n";
    }
    else
    {
        cout << "End of file reached.\n";
    }

    return 0;
}

/*
zhaochen@zhaochendeMacBook-Air code_17.14 % clang++ peeker.cpp 
zhaochen@zhaochendeMacBook-Air code_17.14 % ./a.out 
I used a #3 pencil when I should have used a #2.
I used a 
# is next input character.
3 pencil when I should have used a 
# is next input character.
*/
