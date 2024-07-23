#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

inline void eatline()
{
    while (std::cin.get() != '\n')
        continue;
}

struct planet
{
    char name[20];
    double population;
    double g;
};

const char * file = "planets.dat";

int main()
{
    planet pl;
    cout << fixed << right;

    ifstream fin;
    fin.open(file, ios_base::in | ios_base::binary);

    if (fin.is_open())
    {
        cout << "Here are the current contents of the "
            << file << " file:\n";
        while (fin.read((char *) &pl, sizeof pl))
        {
            cout << setw(20) << pl.name << ": "
                << setprecision(0) << setw(12)
                << pl.population << setprecision(2)
                << setw(6) << pl.g << endl;
        }
        fin.close();
    }

    ofstream fout(file,
        ios_base::out | ios_base::app | ios_base::binary);

    if (!fout.is_open())
    {
        cerr << "Can't open " << file
            << " file for output:\n";
        exit(EXIT_FAILURE);
    }

    cout << "Enter planet name"
        << "(enter a blank line to quit):\n";
    cin.get(pl.name, 20);
    while (pl.name[0] != '\0')
    {
        eatline();
        cout << "Enter planetary population: ";
        cin >> pl.population;
        cout << "Enter planet's acceleration of gravity: ";
        cin >> pl.g;
        eatline();
        fout.write((char *) &pl, sizeof pl);
        cout << "Enter planet name (enter a blank line "
            "to quit):\n";
        cin.get(pl.name, 20);
    }
    fout.close();

    fin.clear();
    fin.open(file, ios_base::in | ios_base::binary);
    if (fin.is_open())
    {
        cout << "Here are the new contents of the "
            << file << " file:\n";
        while (fin.read((char *) &pl, sizeof pl))
        {
            cout << setw(20) << pl.name << ": "
                << setprecision(0) << setw(12)
                << pl.population
                << setprecision(2) << setw(6)
                << pl.g << endl;
        }
        fin.close();
    }

    cout << "Done.\n";
    return 0;
}

/* 第一次运行
zhaochen@zhaochendeAir code_17.19 % ./a.out 
Enter planet name(enter a blank line to quit):
Earth
Enter planetary population: 6928198253
Enter planet's acceleration of gravity: 9.81
Enter planet name (enter a blank line to quit):

Here are the new contents of the planets.dat file:
               Earth:   6928198253  9.81
Done.
zhaochen@zhaochendeAir code_17.19 % 
zhaochen@zhaochendeAir code_17.19 % 
*/

/* 第二次运行
zhaochen@zhaochendeAir code_17.19 % ./a.out
Here are the current contents of the planets.dat file:
               Earth:   6928198253  9.81
Enter planet name(enter a blank line to quit):
Jenny's World
Enter planetary population: 32155648
Enter planet's acceleration of gravity: 8.93
Enter planet name (enter a blank line to quit):

Here are the new contents of the planets.dat file:
               Earth:   6928198253  9.81
       Jenny's World:     32155648  8.93
Done.
zhaochen@zhaochendeAir code_17.19 %
*/
