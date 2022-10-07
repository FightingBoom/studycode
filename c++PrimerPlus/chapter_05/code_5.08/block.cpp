#include <iostream>

int main()
{
    using namespace std;

    cout << "The Amazing Accounto will sum and average five numbers for you.\n";
    cout << "Please enter five values:\n";

    double number;
    double sum = 0.0;

    for (int i = 1; i <= 5; i++)
    {
        cout << "Value " << i << ": ";
        cin >> number;
        sum += number;
    }

    cout << "Five exquisite choices indeed! They sum to " << sum << endl;
    cout << "and average to " << sum / 5 << ".\n";
    cout << "The Amazing Accounto bids you adieu!\n";

    return 0;
}


/*
The Amazing Accounto will sum and average five numbers for you.
Please enter five values:
Value 1: 1942
Value 2: 1948
Value 3: 1957
Value 4: 1974
Value 5: 1980
Five exquisite choices indeed! They sum to 9801
and average to 1960.2.
The Amazing Accounto bids you adieu!
*/
