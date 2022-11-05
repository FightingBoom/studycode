#include <iostream>

using namespace std;

const int ArSize = 6;

int main()
{
    float naaq[ArSize];

    cout << "Enter the NAAQs (New Age Awareness Quotients) "
        << "of\nyour neighbors. Program terminates "
        << "when you make\n" << ArSize << " entries "
        << "or enter a negative value.\n";
    
    int i = 0;
    float temp;

    cout << "First value: ";
    cin >> temp;

    while (i < ArSize && temp >= 0)
    {
        naaq[i] = temp;
        ++i;
        if (i < ArSize)
        {
            cout << "Next value: ";
            cin >> temp;
        }
    }

    if (0 == i)
        cout << "No data--bye\n";
    else
    {
        cout << "Enter your NAAQ: ";
        float you;
        cin >> you;
        int count = 0;
        for (int j = 0; j < i; j++)
        {
            if (naaq[j] > you)
                ++count;
        }
        cout << count;
        cout << " of your neighbors have greater awareness of\n"
            << "the New Age than you do.\n";
    }

    return 0;
}


/*
Enter the NAAQs (New Age Awareness Quotients) of
your neighbors. Program terminates when you make
6 entries or enter a negative value.
First value: 43
Next value: 5235
Next value: 43
Next value: 2342
Next value: 354
Next value: 3463
Enter your NAAQ: 1000
3 of your neighbors have greater awareness of
the New Age than you do.


Enter the NAAQs (New Age Awareness Quotients) of
your neighbors. Program terminates when you make
6 entries or enter a negative value.
First value: -1
No data--bye


Enter the NAAQs (New Age Awareness Quotients) of
your neighbors. Program terminates when you make
6 entries or enter a negative value.
First value: 43
Next value: 5235
Next value: 43
Next value: 2342
Next value: 354
Next value: 3463
Enter your NAAQ: 1000
3 of your neighbors have greater awareness of
the New Age than you do.
*/

