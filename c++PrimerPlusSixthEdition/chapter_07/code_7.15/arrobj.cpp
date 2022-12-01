#include <iostream>
#include <array>
#include <string>

using namespace std;

const int Seasons = 4;
const array<string, Seasons> Snames = 
{
    "Spring",
    "Summer",
    "Fall",
    "Winter"
};

void fill(array<double, Seasons> *pa);
void show(array<double, Seasons> da);

int main()
{
    array<double, Seasons> expenses;
    fill(&expenses);
    show(expenses);

    return 0;
}

void fill(array<double, Seasons> *pa)
{
    for (int i = 0; i < Seasons; i++)
    {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> (*pa)[i];
    }
}

void show(array<double, Seasons> da)
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

# 好像无法保存小数，下一次尝试，看起来是OK的，但是为啥数据丢失了呢？
Enter Spring expenses: 1231.2141
Enter Summer expenses: 241243.1231
Enter Fall expenses: 212131241.121
Enter Winter expenses: 124211.12

EXPENSES
Spring: $1231.21
Summer: $241243
Fall: $2.12131e+08
Winter: $124211
Total Expenses: $2.12498e+08


-----------------------------


Enter Spring expenses: 1.1 
Enter Summer expenses: 2.2
Enter Fall expenses: 3.3
Enter Winter expenses: 4.4

EXPENSES
Spring: $1.1
Summer: $2.2
Fall: $3.3
Winter: $4.4
Total Expenses: $11
*/

