#include "workermi.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// 纯虚析构函数，必须有默认定义
Worker::~Worker()
{

}

void Worker::Data() const
{
    cout << "Name: " << fullname << endl;
    cout << "Employee ID: " << id << endl;
}

void Worker::Get()
{
    getline(cin, fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n')
        continue;
}


// Waiter
void Waiter::Set()
{
    cout << "Enter Waiter's name: ";
    Worker::Get();  // 先调用基类函数，再调用当前类实现
    Get();
}

void Waiter::Show() const
{
    cout << "Category: waiter\n";
    Worker::Data();
    Data();
}

void Waiter::Data() const
{
    cout << "Panache rating: " << panache << endl;
}

void Waiter::Get()
{
    cout << "Enter waiter's panache rating: ";
    cin >> panache;
    while (cin.get() != '\n')
        continue;
}


// Singer
char * Singer::pv[Singer::Vtypes] = 
{
    (char *)"other",
    (char *)"alto",
    (char *)"contralto",
    (char *)"soprano",
    (char *)"bass",
    (char *)"baritone",
    (char *)"tenor"
};

void Singer::Set()
{
    cout << "Enter singer's name: ";
    Worker::Get();
    Get();
}

void Singer::Show() const
{
    cout << "Category: singer\n";
    Worker::Data();
    Data();
}

void Singer::Data() const
{
    cout << "Vocal range: " << pv[voice] << endl;
}

void Singer::Get()
{
    cout << "Enter number for singer's vocal range:\n";
    int i;
    for (i = 0; i < Vtypes; i++)
    {
        cout << i << ": " << pv[i] << "    ";
        if (i % 4 == 3)
            cout << endl;
    }

    if (i % 4 != 0)
        cout << '\n';

    cin >> voice;

    while (cin .get() != '\n')
        continue;
}


// 多重继承类定义
void SingingWaiter::Data() const
{
    Singer::Data();
    Waiter::Data();
}

void SingingWaiter::Get()
{
    Waiter::Get();
    Singer::Get();
}

void SingingWaiter::Set()
{
    cout << "Enter singing waiter's name: ";
    Worker::Get();
    Get();
}

void SingingWaiter::Show() const
{
    cout << "Category: singing waiter\n";
    Worker::Data();
    Data();
}
