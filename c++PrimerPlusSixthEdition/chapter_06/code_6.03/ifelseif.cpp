#include <iostream>

using namespace std;

const int FAVE = 22;

int main()
{
    int n;

    cout << "Enter a number in the range 1-100 to find my favorite number: ";

    do
    {
        cin >> n;

        if (n < FAVE)
            cout << "Too low -- guess again: ";
        else if (n > FAVE)
            cout << "Too high -- guess again: ";
        else
            cout << FAVE << " is right!\n";
    } while (FAVE != n);    // 常量在前

    return 0;
}

/*
Enter a number in the range 1-100 to find my favorite number: 50
Too high -- guess again: 25
Too high -- guess again: 13
Too low -- guess again: 20
Too low -- guess again: 23
Too high -- guess again: 22
22 is right!
*/
