#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    cout << "The larger of " << a << " and " << b;
    int c = a > b ? a : b;
    cout << " is " << c << endl;

    return 0;
}

/*
Enter two integers: 213 2142
The larger of 213 and 2142 is 2142
*/