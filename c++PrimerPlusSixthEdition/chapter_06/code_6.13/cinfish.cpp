#include <iostream>

using namespace std;

const int Max = 5;

int main()
{
    double fish[Max];
    cout << "Please enter the weights of your fish.\n";
    cout << "You may enter up to " << Max << " fish <q to terminate>.\n";
    cout << "fish #1: ";
    int i = 0;  // 序号
    while (i < Max && cin >> fish[i])
    {
        if (++i < Max)
            cout << "fish #" << i + 1 << ": ";
    }

    double total = 0.0;
    for (int j = 0; j < i; j++)
        total += fish[j];
    
    if (0 == i)
        cout << "No fish\n";
    else
        cout << total / i << " = average weight of " << i << " fish\n";
    
    cout << "Done.\n";
    return 0;
}

/*
Please enter the weights of your fish.
You may enter up to 5 fish <q to terminate>.
fish #1: 30
fish #2: 40
fish #3: 50 
fish #4: 60
fish #5: q
45 = average weight of 4 fish
Done.
*/
