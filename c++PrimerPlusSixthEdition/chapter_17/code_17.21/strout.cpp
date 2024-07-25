#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    ostringstream outstr;

    string hdisk;
    cout << "What's the name of your hard disk? ";
    getline(cin, hdisk);
    int cap;
    cout << "What's its capacity in GB? ";
    cin >> cap;

    outstr << "The hard disk " << hdisk
        << " has a capacity of " << cap << " gigabytes.\n";
    string result = outstr.str();
    cout << result;

    return 0;
}

/*
zhaochen@zhaochendeAir code_17.21 % clang++ strout.cpp 
zhaochen@zhaochendeAir code_17.21 % ./a.out 
What's the name of your hard disk? Datarapture
What's its capacity in GB? 2000
The hard disk Datarapture has a capacity of 2000 gigabytes.
zhaochen@zhaochendeAir code_17.21 %
*/
