#include <iostream>
#include <cmath>
#include "exc_mean.h"

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try
        {
            z = hmean(x, y);

            cout << "Harmonic mean of " << x << " and "
                << y << " is " << z << endl;

            cout << "Geometric mean of " << x << " and "
                << y << " is " << gmean(x, y) << endl;

            cout << "Enter next set of numbers "
                "<q to quit>: ";
        }
        catch (bad_hmean & bg)
        {
            bg.mesg();
            cout << "Try again.\n";
            continue;
        }
        catch (bad_gmean & hg)
        {
            cout << hg.mesg();
            cout << "Values used: " << hg.v1 << ", "
                << hg.v2 << endl;
            cout << "Sorry, you don't get to "
                "play any more.\n";
            break;
        }
    }

    cout << "Bye!\n";

    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean(a, b);

    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);

    return std::sqrt(a * b);
}

/*
zhaochen@zhaochendeAir code_15.10_11 % ./a.out
Enter two numbers: 4 12
Harmonic mean of 4 and 12 is 6
Geometric mean of 4 and 12 is 6.9282
Enter next set of numbers <q to quit>: 5 -5
hmean(5, -5): invalid arguments: a = -b
Try again.
5 -2
Harmonic mean of 5 and -2 is -6.66667
Geometric mean of 5 and -2 is gmean() arguments should be >= 0
Values used: 5, -2
Sorry, you don't get to play any more.
Bye!
*/
