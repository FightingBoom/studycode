#include <iostream>
#include <new>
#include <cstdlib>

using namespace std;

struct Big
{
    double stuff[20000];
};

int main()
{
    Big * pb;
    try
    {
        cout << "Trying to get a big block of memory:\n";
        pb = new Big[10000]; // macOS实际测试未超过上限
        cout << "Got past the new request:\n";
    }
    catch (bad_alloc & ba)
    {
        cout << "Caught the exception!\n";
        cout << ba.what() << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Memory successfully allocated\n";
    pb[0].stuff[0] = 4;
    cout << pb[0].stuff[0] << endl;

    delete [] pb;

    return 0;
}

/*
zhaochen@zhaochendeAir code_15.13 % ./a.out 
Trying to get a big block of memory:
Got past the new request:
Memory successfully allocated
4
*/

