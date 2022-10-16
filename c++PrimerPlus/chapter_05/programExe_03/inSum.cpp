#include <iostream>

using namespace std;

int main()
{
    int a, sum;
    a = sum = 0;
    
    cout << "Enter a num; enter 0 to quit: ";
    cin >> a;

    while (0 != a)
    {
        sum += a;
        cout << "sum = " << sum << endl;

        cout << "Enter a num; enter 0 to quit: ";
        cin >> a;
    }

    cout << "sum = " << sum << endl;

    return 0;
}

/*
Enter a num; enter 0 to quit: 1
sum = 1
Enter a num; enter 0 to quit: 2
sum = 3
Enter a num; enter 0 to quit: 3
sum = 6
Enter a num; enter 0 to quit: 4
sum = 10
Enter a num; enter 0 to quit: 5
sum = 15
Enter a num; enter 0 to quit: 6
sum = 21
Enter a num; enter 0 to quit: 7
sum = 28
Enter a num; enter 0 to quit: 8
sum = 36
Enter a num; enter 0 to quit: 9
sum = 45
Enter a num; enter 0 to quit: 10
sum = 55
Enter a num; enter 0 to quit: 0
sum = 55
*/
