#include <iostream>

double hmean(double a, double b);

int main()
{
    double x, y, z;

    std::cout << "Enter two numbers: ";
    while (std::cin >> x >> y)
    {
        try
        {
            z = hmean(x, y);
        }
        catch(const char * s)
        {
            std::cout << s << std::endl;
            std::cout << "Enter a new pair of number: ";
            continue;
        }

        std::cout << "Harmonic mean of " << x << " and "
            << y << " is " << z << std::endl;

        std::cout << "Enter next set of numbers"
            " <q to quit>: ";
    }

    std::cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
    {
        throw "bad hmean() arguments: a = -b not allowed";
    }
    return 2.0 * a * b / (a + b);
}

/*
zhaochen@zhaochendeAir code_15.09 % ./a.out 
Enter two numbers: 3 6
Harmonic mean of 3 and 6 is 4
Enter next set of numbers <q to quit>: 10 -10 
bad hmean() arguments: a = -b not allowed
Enter a new pair of number: 1 19
Harmonic mean of 1 and 19 is 1.9
Enter next set of numbers <q to quit>: q
Bye!
*/
