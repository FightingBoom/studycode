#include <iostream>
#include "studentc.h"

using std::cin;
using std::cout;
using std::endl;

void set(Student & sa, int n);

const int pupils = 3;
const int quizzes = 5;

int main()
{
    Student ada[pupils] = 
    {
        Student(quizzes),
        Student(quizzes),
        Student(quizzes)
    };

    int i;
    for (i = 0; i < pupils; ++i)
    {
        set(ada[i], quizzes);
    }

    cout << "\nStudent List:\n";
    for (i = 0; i < pupils; ++i)
    {
        cout << ada[i].Name() << endl;
    }

    cout << "\nResults:";
    for (i = 0; i < pupils; ++i)
    {
        cout << endl << ada[i];
        cout << "average: " << ada[i].Average() << endl;
    }

    cout << "Done.\n";

    return 0;
}

void set(Student & sa, int n)
{
    cout << "Please enter the student's name: ";
    getline(cin, sa);
    cout << "Please enter " << n << " quiz scores:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> sa[i];
    }

    while (cin.get() != '\n')
    {
        continue;
    }
}


/*
zhaochen@zhaochendeMacBook-Air code_14.01_02_03 % ./a.out 
Please enter the student's name: Gil Bayts
Please enter 5 quiz scores:
92 94 96 93 95
Please enter the student's name: Pat Roone
Please enter 5 quiz scores:
83 89 72 78 95
Please enter the student's name: Fleur O'Day
Please enter 5 quiz scores:
92 89 96 74 64

Student List:
Gil Bayts
Pat Roone
Fleur O'Day

Results:
Scores for Gil Bayts:
92 94 96 93 95 
average: 94

Scores for Pat Roone:
83 89 72 78 95 
average: 83.4

Scores for Fleur O'Day:
92 89 96 74 64 
average: 83
Done.
*/

