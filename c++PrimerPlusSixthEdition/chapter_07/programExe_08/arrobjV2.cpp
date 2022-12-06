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

struct SeasonInfo
{
    double expenses[Seasons];
};


void fill(double *pa);
void show(const double * da);

int main()
{
    SeasonInfo stuSeason;
    fill(stuSeason.expenses);
    show(stuSeason.expenses);

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
Enter Spring expenses: 2122
Enter Summer expenses: 23342
Enter Fall expenses: 123214
Enter Winter expenses: 23532

EXPENSES
Spring: $2122
Summer: $23342
Fall: $123214
Winter: $23532
Total Expenses: $172210

---------------------------

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
*/

