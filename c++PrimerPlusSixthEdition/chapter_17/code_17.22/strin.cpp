#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string lit = "It was a dark and stormy day, and "
        " the full moon glowed brilliantly. ";

    istringstream instr(lit);
    string word;
    while (instr >> word)
        cout << word << endl;

    return 0;
}

/*
zhaochen@zhaochendeAir code_17.22 % clang++ strin.cpp 
zhaochen@zhaochendeAir code_17.22 % ./a.out 
It
was
a
dark
and
stormy
day,
and
the
full
moon
glowed
brilliantly.
zhaochen@zhaochendeAir code_17.22 %
*/
