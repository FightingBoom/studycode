#include <iostream>

using namespace std;

const int ArSize = 20;

int main()
{
    char name[ArSize];

    cout << "Your first name, please: ";
    cin >> name;
    cout << "Here is your name, verticalized and ASCIIized:\n";

    int i = 0;
    while ('\0' != name[i])
    {
        cout << name[i] << ": " << int(name[i]) << endl;
        i++;
    }

    return 0;
}


/*
Your first name, please: Muffy
Here is your name, verticalized and ASCIIized:
M: 77
u: 117
f: 102
f: 102
y: 121
*/
