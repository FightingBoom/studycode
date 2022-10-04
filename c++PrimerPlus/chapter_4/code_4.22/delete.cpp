#include <iostream>
#include <cstring>

using namespace std;

char * getname(void);

int main()
{
    char* name;

    name = getname();
    cout << name << " at " << (int*)name << "\n";
    delete [] name;

    name = getname();
    cout << name << " at " << (int*)name << "\n";
    delete [] name;

    return 0;
}

char * getname()
{
    char temp[80];
    cout << "Enter last name: ";
    cin >> temp;
    char* pn = new char[strlen(temp) + 1];
    cout << "strlen(temp) = " << strlen(temp) << endl;
    strcpy(pn, temp);

    return pn;
}


/*
Enter last name: rob
strlen(temp) = 3
rob at 0x1a1790
Enter last name: moon
strlen(temp) = 4
moon at 0x1a1790
*/

