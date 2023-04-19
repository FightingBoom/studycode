#include <iostream>
#include <cstdlib>
#include <ctime>
#include "string1.h"

const int ArSize = 10;
const int MaxLen = 81;

int main()
{
    using namespace std;

    String name;
    cout << "Hi, what's your name?\n>> ";
    cin >> name;
    cout << name << ", please enter up to " << ArSize
        << " short sayings <empty line to quit>:\n";

    String sayings[ArSize];
    char temp[MaxLen];
    int i;

    for (i = 0; i < ArSize; i++)
    {
        cout << i + 1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n')
            continue;
        if (!cin || temp[0] == '\0')
            break;
        else
            sayings[i] = temp;
    }

    int total = i;
    if (total > 0)
    {
        cout << "Here are your sayings:\n";
        for (i = 0; i < total; i++)
            cout << sayings[i] << "\n";

        String * shortest = &sayings[0];
        String * first = &sayings[0]; // 指针指向sayings第一个元素的位置
        for (i = 1; i < total; i++)
        {
            if (sayings[i].length() < shortest->length()) // 指针取值与类对象不同
                shortest = &sayings[i];
            if (sayings[i] < *first)
                first = &sayings[i];
        }

        cout << "Shortest saying:\n" << *shortest << endl;
        cout << "First alphabetically:\n" << *first << endl;

        srand(time(0));
        int choice = rand() % total;
        String * favorite = new String(sayings[choice]);
        cout << "My favorrite saying:\n" << *favorite << endl;
        delete favorite;
    }
    else
    {
        cout << "Not much to say, eh?\n";
    }
    cout << "Bye.\n";
    return 0;
}

/* 注意与sayings1.cpp分开编译，例如这样：g++ .\sayings2.cpp .\string1.cpp -o sayings2
Hi, what's your name?
>> Kirt Rood
Kirt Rood, please enter up to 10 short sayings <empty line to quit>:
1: a friend in need is a friend indeed
2: neither a borrower nor a lender be
3: a stitch in time saves nine
4: a niche in time saves atine
5: it takes a crook to catch a crook
6: cold hands, warm heart
7: 
Here are your sayings:
a friend in need is a friend indeed
neither a borrower nor a lender be
a stitch in time saves nine
a niche in time saves atine
it takes a crook to catch a crook
cold hands, warm heart
Shortest saying:
cold hands, warm heart
First alphabetically:
a friend in need is a friend indeed
My favorrite saying:
a stitch in time saves nine
Bye.
*/
