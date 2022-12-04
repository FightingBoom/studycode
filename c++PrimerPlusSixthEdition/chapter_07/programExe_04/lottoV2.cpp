#include <iostream>

using namespace std;

long double probability(unsigned numbers, unsigned picks);

int main()
{
    int count = 0;
    long double lastChoices;
    long double currentChoices;
    double total, choices;
    cout << "Enter the total number of choices on the game card and\n"
            "the number of picks allowed:\n";

    while ((cin >> total >> choices) && (choices <= total))
    {
        cout << "You have one chance in ";
        currentChoices = probability(total, choices);
        cout << currentChoices;
        cout << " of winning.\n";

        count++;
        if (count % 2)
        {
            lastChoices = currentChoices;
        }
        else if (0 == (count % 2))
        {
            cout << "You have one chance in " << currentChoices * lastChoices << " of winning.\n";
            lastChoices = currentChoices = 0;
        }

        cout << "Next two numbers (q to quit): ";
    }

    cout << "bye\n";
    return 0;
}

long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;
    long double n;
    unsigned p;

    for (n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p;

    return result;
}

/*
Enter the total number of choices on the game card and
the number of picks allowed:
3 1
You have one chance in 3 of winning.
Next two numbers (q to quit): 4 1
You have one chance in 4 of winning.
You have one chance in 12 of winning.
Next two numbers (q to quit): 47 5
You have one chance in 1.53394e+06 of winning.
Next two numbers (q to quit): 27 1
You have one chance in 27 of winning.
You have one chance in 4.14164e+07 of winning.
Next two numbers (q to quit): q
bye
*/
