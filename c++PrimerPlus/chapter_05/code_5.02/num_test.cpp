#include <iostream>

int main()
{
    using namespace std;

    cout << "Enter the starting countdown value: ";

    int limit;
    cin >> limit;

    int i;
    for (i = limit; i; i--)
        cout << "i = " << i << endl;

    cout << "Done now that i = " << i << endl;
    return 0;
}

/*
Enter the starting countdown value: 4
i = 4
i = 3
i = 2
i = 1
Done now that i = 0
*/
