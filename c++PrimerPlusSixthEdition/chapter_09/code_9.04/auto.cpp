#include <iostream>

void oil(int x);

int main()
{
    using namespace std;

    int texas = 31;
    int year = 2011;

    cout << "In main(), texas = " << texas << ", &texas = ";
    cout << &texas << endl;
    cout << "In main(), year = " << year << ", &year = ";
    cout << &year << endl;

    oil(texas);

    cout << "In main(), texas = " << texas << ", &texas = ";
    cout << &texas << endl;
    cout << "In main(), year = " << year << ", &year = ";
    cout << &year << endl;

    return 0;
}

void oil(int x)
{
    using namespace std;
    int texas = 5;

    cout << "In oil(), texas = " << texas << ", &texas = ";
    cout << &texas << endl;
    cout << "In oil(), x = " << x << ", &x = ";
    cout << &x << endl;

    {
        int texas = 113;
        cout << "In block, texas = " << texas << ", &texas = ";
        cout << &texas << endl;
        cout << "In oil(), x = " << x << ", &x = ";
        cout << &x << endl;
    }

    cout << "Post-block texas = " << texas;
    cout << ", &texas = " << &texas << endl;
}

/*
In main(), texas = 31, &texas = 0x61fe1c
In main(), year = 2011, &year = 0x61fe18
In oil(), texas = 5, &texas = 0x61fddc
In oil(), x = 31, &x = 0x61fdf0
In block, texas = 113, &texas = 0x61fdd8
In oil(), x = 31, &x = 0x61fdf0
Post-block texas = 5, &texas = 0x61fddc
In main(), texas = 31, &texas = 0x61fe1c
In main(), year = 2011, &year = 0x61fe18
*/
