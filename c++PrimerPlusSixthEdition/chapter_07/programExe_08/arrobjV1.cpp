#include <iostream>
#include <array>
#include <string>

using namespace std;

const int Seasons = 4;
const int NAME_SIZE = 32;

const char * Snames[Seasons] = 
{
    "Spring",
    "Summer",
    "Fall",
    "Winter"
};

void fill(double *pa);
void show(const double * da);

int main()
{
    double expenses[Seasons];
    fill(expenses);
    show(expenses);

    return 0;
}

void fill(double *pa)
{
    for (int i = 0; i < Seasons; i++)
    {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> pa[i];
    }
}

void show(const double * da)
{
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        cout << Snames[i] << ": $" << da[i] << endl;
        total += da[i];
    }
    cout << "Total Expenses: $" << total << endl;
}

/*
Enter Spring expenses: 212
Enter Summer expenses: 256
Enter Fall expenses: 208
Enter Winter expenses: 244

EXPENSES
Spring: $212
Summer: $256
Fall: $208
Winter: $244
Total Expenses: $920


---------------------------

# 小数点位数，应该跟系统默认设置有关，之前好像在哪看到过
Enter Spring expenses: 123.123
Enter Summer expenses: 234.2345
Enter Fall expenses: 345.34567
Enter Winter expenses: 456.456789

EXPENSES
Spring: $123.123
Summer: $234.234
Fall: $345.346
Winter: $456.457
Total Expenses: $1159.16


-----------------------------


Enter Spring expenses: 1.11 
Enter Summer expenses: 2.22
Enter Fall expenses: 3.33
Enter Winter expenses: 4.44

EXPENSES
Spring: $1.11
Summer: $2.22
Fall: $3.33
Winter: $4.44
Total Expenses: $11.1
*/

