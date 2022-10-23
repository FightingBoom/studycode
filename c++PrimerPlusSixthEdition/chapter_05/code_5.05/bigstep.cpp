#include <iostream>

int main()
{
    using namespace std;

    cout << "Enter an integer: ";

    int by;
    cin >> by;
    cout << "Counting by " << by << "s:\n";

    for (int i = 0; i < 100; i = i + by)
        cout << "i = " << i << endl;

    return 0;
}

/*
Enter an integer: 17
Counting by 17s:
i = 0
i = 17
i = 34
i = 51
i = 68
i = 85
*/
