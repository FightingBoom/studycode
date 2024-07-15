#include <iostream>

const int SLEN = 10;

inline void eatline()
{
    while (std::cin.get() != '\n')
        continue;
}

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    char name[SLEN];
    char title[SLEN];
    cout << "Enter your name: ";
    cin.get(name, SLEN);

    if (cin.peek() != '\n')
    {
        cout << "Sorry, we only have enough room for "
            << name << endl;
    }

    eatline();

    cout << "Dear " << name << ", enter your title: \n";
    cin.get(title, SLEN);
    if (cin.peek() != '\n')
        cout << "We were forced to truncate your title.\n";

    eatline();

    cout << " Name: " << name
        << "\nTitle: " << title << endl;

    return 0;
}

/*
zhaochen@zhaochendeMacBook-Air code_17.15 % clang++ truncate.cpp 
zhaochen@zhaochendeMacBook-Air code_17.15 % ./a.out 
Enter your name: Ella Fishsniffer
Sorry, we only have enough room for Ella Fish
Dear Ella Fish, enter your title: 
Executive Adjunct
We were forced to truncate your title.
 Name: Ella Fish
Title: Executive
*/
