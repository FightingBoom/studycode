#include <iostream>

using namespace std;

void showString(string & str, int n = 0);

int main()
{
    string str = "Hello world!";

    cout << "not int member, printf start" << endl;
    showString(str);
    cout << "not int member, printf end" << endl;

    cout << "n = 1, printf start" << endl;
    showString(str, 1);
    cout << "n = 1, printf end" << endl;

    cout << "n = 2, printf start" << endl;
    showString(str, 2);
    cout << "n = 2, printf end" << endl;

    cout << "n = 3, printf start" << endl;
    showString(str, 3);
    cout << "n = 3, printf end" << endl;

    return 0;
}

void showString(string & str, int n)
{
    if (0 == n)
    {
        cout << "not show string, return." << endl;
        return;
    }

    cout << str << endl;
}

/*
not int member, printf start
not show string, return.
not int member, printf end
n = 1, printf start
Hello world!
n = 1, printf end
n = 2, printf start
Hello world!
n = 2, printf end
n = 3, printf start
Hello world!
n = 3, printf end
*/

