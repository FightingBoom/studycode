#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int LIM = 20;

struct planet
{
    char name[LIM];
    double population;
    double g;
};

const char * file = "planets.dat";

inline void eatline()
{
    while (std::cin.get() != '\n')
        continue;
}

int main()
{
    planet pl;
    cout << fixed;

    fstream finout;
    finout.open(file,
        ios_base::in | ios_base::out | ios_base::binary);

    int ct = 0;
    if (finout.is_open())
    {
        finout.seekg(0);    // go to beginning
        cout << "Here are the current contents of the "
            << file << " file:\n";

        while (finout.read((char *) &pl, sizeof pl))
        {
            cout << ct++ << ": " << setw(LIM) << pl.name
                << ": " << setprecision(0) << setw(12)
                << pl.population
                << setprecision(2) << setw(6) << pl.g
                << endl;
        }

        if (finout.eof())
        {
            finout.clear();
        }
        else
        {
            cerr << "Error in readint " << file << ".\n";
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        cerr << file << " could not be opened -- bye.\n";
        exit(EXIT_FAILURE);
    }

    cout << "Enter the record number you wish to change: ";
    long rec;
    cin >> rec;
    eatline();
    if (rec < 0 || rec >= ct)
    {
        cerr << "Invalid record number -- bye\n";
        exit(EXIT_FAILURE);
    }

    streampos place = rec * sizeof pl;
    finout.seekg(place);
    if (finout.fail())
    {
        cerr << "Error on attempted seek\n";
        exit(EXIT_FAILURE);
    }

    finout.read((char *) &pl, sizeof pl);
    cout << "Your selection:\n";
    cout << rec << ": " << setw(LIM) << pl.name << ": "
        << setprecision(0) << setw(12) << pl.population
        << setprecision(2) << setw(6) << pl.g << endl;

    if (finout.eof())
    {
        finout.clear();
    }

    cout << "Enter planet name: ";
    cin.get(pl.name, LIM);
    eatline();
    cout << "Enter planetary population: ";
    cin >> pl.population;
    cout << "Enter planet's acceleration of gravity: ";
    cin >> pl.g;
    finout.seekp(place);
    finout.write((char *)&pl, sizeof pl) << flush;
    if (finout.fail())
    {
        cerr << "Error on attempted write\n";
        exit(EXIT_FAILURE);
    }

    ct = 0;
    finout.seekg(0);
    cout << "Here are the new contents of the " << file
        << " file:\n";
    while (finout.read((char *) &pl, sizeof pl))
    {
        cout << ct++ << ": " << setw(LIM) << pl.name
            << ": " << setprecision(0) << setw(12)
            << pl.population
            << setprecision(2) << setw(6) << pl.g
            << endl;
    }
    finout.close();

    cout << "Done.\n";
    return 0;
}

/*
zhaochen@zhaochendeAir code_17.20 % ./a.out 
Here are the current contents of the planets.dat file:
0:                Earth:   6928198253  9.81
1:        Jenny's World:     32155648  8.93
Enter the record number you wish to change: 1
Your selection:
1:        Jenny's World:     32155648  8.93
Enter planet name: Trantor
Enter planetary population: 89521844777
Enter planet's acceleration of gravity: 10.53
Here are the new contents of the planets.dat file:
0:                Earth:   6928198253  9.81
1:              Trantor:  89521844777 10.53
Done.
zhaochen@zhaochendeAir code_17.20 %
*/
