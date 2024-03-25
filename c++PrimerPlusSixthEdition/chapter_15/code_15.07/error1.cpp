#include <iostream>
#include <cstdlib>

double hmean(double a, double b);

int main()
{
    double x, y, z;

    std::cout << "Enter two numbers: ";
    while (std::cin >> x >> y)
    {
        z = hmean(x, y);
        std::cout << "Harmonic mean of " << x << " and "
            << y << " is " << z << std::endl;
        std::cout << "Enter next set of"
            " numbers <q to quit>: ";
    }

    std::cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
    {
        std::cout << "untenable argments to hmean()\n";
        std::abort();
    }
    return 2.0 * a * b / (a + b);
}

/*
zhaochen@zhaochendeAir code_15.07 % ./a.out 
Enter two numbers: 3 6 
Harmonic mean of 3 and 6 is 4
Enter next set of numbers <q to quit>: 10 -10
untenable argments to hmean()
zsh: abort      ./a.out
*/