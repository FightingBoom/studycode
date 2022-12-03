#include <iostream>

using namespace std;

void countdown(int n);

int main()
{
    countdown(4);
    return 0;
}

void countdown(int n)
{
    cout << "Counting down ... " << n << "(n at " << &n << ")" << endl;
    if (n > 0)
        countdown(n - 1);
    cout << n << ": Kaboom!" << "         (n at " << &n << ")" << endl;;
}

/*
Counting down ... 4(n at 0x61fe00)
Counting down ... 3(n at 0x61fdd0)
Counting down ... 2(n at 0x61fda0)
Counting down ... 1(n at 0x61fd70)
Counting down ... 0(n at 0x61fd40)
0: Kaboom!         (n at 0x61fd40)
1: Kaboom!         (n at 0x61fd70)
2: Kaboom!         (n at 0x61fda0)
3: Kaboom!         (n at 0x61fdd0)
4: Kaboom!         (n at 0x61fe00)
*/
