#include <iostream>
#include <climits>

using namespace std;

bool is_int(double);

int main()
{
    double num;

    cout << "Yo, dude! Enter an integer value: ";
    cin >> num;
    while (!is_int(num))
    {
        cout << "Out of range -- please try again: ";
        cin >> num;
    }

    int val = int (num);
    cout << "You've entered the integer " << val << "\nBye\n";
    return 0;
}

bool is_int(double x)
{
    if (x <= INT_MAX && x >= INT_MIN)
        return true;
    else
        return false;
}

/*
Yo, dude! Enter an integer value: 1234567890
You've entered the integer 1234567890
Bye

Yo, dude! Enter an integer value: 9876543210
Out of range -- please try again: -8239429394239
Out of range -- please try again: 9999
You've entered the integer 9999
Bye
*/

