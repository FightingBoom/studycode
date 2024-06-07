#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    using namespace std;

    string letters;
    cout << "Enter the letter grouping (quit to quit): ";
    while (cin >> letters && letters != "quit")
    {
        cout << "Permutations of " << letters << endl;
        sort(letters.begin(), letters.end());
        cout << letters << endl;
        while (next_permutation(
                letters.begin(), letters.end()))
        {
            cout << letters << endl;
        }
        cout << "Enter next sequence (quit to quit): ";
    }

    cout << "Done.\n";
    return 0;
}

/*
zhaochen@zhaochendeAir code_16.17 % clang++ strgst1.cpp
zhaochen@zhaochendeAir code_16.17 % ./a.out            
Enter the letter grouping (quit to quit): awl
Permutations of awl
alw
awl
law
lwa
wal
wla
Enter next sequence (quit to quit): all
Permutations of all
all
lal
lla
Enter next sequence (quit to quit): quit
Done.
*/
