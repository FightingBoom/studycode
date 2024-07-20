#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const char * file = "guests.txt";

int main()
{
    char ch;
    ifstream fin;
    fin.open(file);

    if (fin.is_open())
    {
        cout << "Here are the current contents of the "
            << file << " file:\n";

        while (fin.get(ch))
            cout << ch;

        fin.close();
    }

    ofstream fout(file, ios::out | ios::app);
    if (!fout.is_open())
    {
        cerr << "Can't open " << file
            << " file for output.\n";
        exit(EXIT_FAILURE);
    }

    cout <<
        "Enter guest names (enter a blank line to quit):\n";

    string name;
    while (getline(cin, name) && name.size() > 0)
    {
        fout << name << endl;
    }
    fout.close();

    fin.clear();
    fin.open(file);
    if (fin.is_open())
    {
        cout << "Here are the new contents of the "
            << file << " file:\n";

        while (fin.get(ch))
            cout << ch;

        fin.close();
    }

    cout << "Done.\n";

    return 0;
}

/* 第一次运行
zhaochen@zhaochendeAir code_17.18 % clang++ append.cpp 
zhaochen@zhaochendeAir code_17.18 % ./a.out 
Enter guest names (enter a blank line to quit):
Genghis Kant
Hank Attila
Charles Bigg

Here are the new contents of the guests.txt file:
Genghis Kant
Hank Attila
Charles Bigg
Done.
zhaochen@zhaochendeAir code_17.18 % ls
a.out           append.cpp      guests.txt
zhaochen@zhaochendeAir code_17.18 %
*/

/* 第二次运行
zhaochen@zhaochendeAir code_17.18 % ./a.out 
Here are the current contents of the guests.txt file:
Genghis Kant
Hank Attila
Charles Bigg
Enter guest names (enter a blank line to quit):
Greta Greppo
LaDonna Mobile
Fannie Mae

Here are the new contents of the guests.txt file:
Genghis Kant
Hank Attila
Charles Bigg
Greta Greppo
LaDonna Mobile
Fannie Mae
Done.
zhaochen@zhaochendeAir code_17.18 %
*/
