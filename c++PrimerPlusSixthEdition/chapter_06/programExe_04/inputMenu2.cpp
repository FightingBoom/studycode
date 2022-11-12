#include <iostream>

using namespace std;

const int strsize = 32;
const int numbers = 5;

struct bop
{
    char fullname[strsize]; // real name
    char title[strsize];    // job title
    char bopname[strsize];  // secret BOP name
    int preference;         // 0 = fullname, 1 = title, 2 = bopname
};

bop bAllInfo[numbers] = 
{
    {"Wimp Macho", "Wimp", "Macho", 0},
    {"Raki Rhodes", "Raki", "Rhodes", 1},
    {"Celia Laiter", "Celia", "Laiter", 1},
    {"Hoppy Hipman", "Hoppy", "Hipman", 2},
    {"Pat Hand", "Pat", "Hand", 2}
};

void showmenu();
void aPrintFullname();
void bPrintTitle();
void cPrintBopname();
void dPrintPreference();

int main()
{
    char choice;


    showmenu();

    cout << "Enter your choice: ";
    cin >> choice;
    while ('q' != choice)
    {
        switch (choice) // 根据输入字符，显示对应内容
        {
            case 'a':
                aPrintFullname();
                break;
            case 'b':
                bPrintTitle();
                break;
            case 'c':
                cPrintBopname();
                break;
            case 'd':
                dPrintPreference();
                break;
            default:
                // cout << "That's not a choice.\n";
                break;
        }

        cout << "Next choice: ";
        cin >> choice;
    }

    cout << "Bye!\n";
    return 0;
}

void showmenu()
{
    cout << "Benevolent Order of Programmers Report\n";
    cout << "a. display by name     b. display by title\n"
            "c. display by bopname  d. display by preference\n"
            "q. quit";
}

void aPrintFullname()
{
    for (int i = 0; i < numbers; i++)
    {
        cout << bAllInfo[i].fullname << endl;
    }
}

void bPrintTitle()
{
    for (int i = 0; i < numbers; i++)
    {
        cout << bAllInfo[i].title << endl;
    }
}

void cPrintBopname()
{
    for (int i = 0; i < numbers; i++)
    {
        cout << bAllInfo[i].bopname << endl;
    }
}

void dPrintPreference()
{
    for (int i = 0; i < numbers; i++)
    {
        switch (bAllInfo[i].preference)
        {
            case 0:
                cout << bAllInfo[i].fullname << endl;
                break;
            case 1:
                cout << bAllInfo[i].title << endl;
                break;
            case 2:
                cout << bAllInfo[i].bopname << endl;
                break;
            default:
                break;
        }
    }
}


/*
Benevolent Order of Programmers Report
a. display by name     b. display by title
c. display by bopname  d. display by preference
q. quitEnter your choice: a
Wimp Macho
Raki Rhodes
Celia Laiter
Hoppy Hipman
Pat Hand
Next choice: d
Wimp Macho
Raki
Celia
Hipman
Hand
Next choice: b
Wimp
Raki
Celia
Hoppy
Pat
Next choice: c
Macho
Rhodes
Laiter
Hipman
Hand
Next choice: q
Bye!
*/

