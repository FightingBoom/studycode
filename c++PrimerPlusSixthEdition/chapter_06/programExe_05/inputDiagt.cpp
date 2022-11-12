#include <iostream>

using namespace std;

int main()
{
    int currentSalary = 0;
    int currentTax = 0;

    cout << "Enter your salary(tvarps): ";
    cin >> currentSalary;
    while (!cin.fail() && (currentSalary >= 0)) // 大于等于0的数字，一直循环要求输入
    {
        if (currentSalary <= 5000)
        {
            currentTax = 0;
        }
        else if ((5000 < currentSalary) && (currentSalary <= 15000))
        {
            currentTax += (currentSalary - 5000) * 0.1;
        }
        else if ((15000 < currentSalary) && (currentSalary <= 35000))
        {
            currentTax += 10000 * 0.1;
            currentTax += (currentSalary - 15000) * 0.15;
        }
        else
        {
            currentTax += 10000 * 0.1;
            currentTax += 20000 * 0.15;
            currentTax += (currentSalary - 35000) * 0.20;
        }

        cout << "currentTax = " << currentTax << " tvarps" << endl;
        currentTax = 0;

        cout << "Enter your next salary(tvarps): ";
        cin >> currentSalary;
    }

    return 0;
}


/*
Enter your salary(tvarps): 38000
currentTax = 4600 tvarps
Enter your next salary(tvarps): 20000
currentTax = 1750 tvarps
Enter your next salary(tvarps): -1

-------------------------------------

Enter your salary(tvarps): 38000
currentTax = 4600 tvarps
Enter your next salary(tvarps): 30000
currentTax = 3250 tvarps
Enter your next salary(tvarps): hello
*/

