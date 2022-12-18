#include <iostream>
#include <cstring>

using namespace std;

struct stringy
{
    char * str;
    int ct;
};

void set(stringy & stuBeany, const char * test);
void show(const stringy stuBeany, int times = 1);
void show(const char * stuBeany, int times = 1);

int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany, testing);

    show(beany);
    show(beany, 2);

    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);

    delete [] beany.str;
    show("Done!");
    return 0;
}

void set(stringy & stuBeany, const char * test)
{
    stuBeany.ct = strlen(test);
    // cout << stuBeany.ct << endl;

    stuBeany.str = new char [stuBeany.ct];
    memset(stuBeany.str, 0, stuBeany.ct);         // 初始化为0
    strncpy(stuBeany.str, test, stuBeany.ct - 1); // 增加长度的安全拷贝
    // cout << stuBeany.str;
}

void show(const stringy stuBeany, int times)
{
    for (int i = 0; i < times; i++)
    {
        cout << "the length of [" << stuBeany.str << "] is " << stuBeany.ct << endl;
    }
}

void show(const char * stuBeany, int times)
{
    for (int i = 0; i < times; i++)
    {
        cout << stuBeany << endl;
    }
}

/*
the length of [Reality isn't what it used to be] is 33
the length of [Reality isn't what it used to be] is 33
the length of [Reality isn't what it used to be] is 33
Duality isn't what it used to be.
Duality isn't what it used to be.
Duality isn't what it used to be.
Duality isn't what it used to be.
Done!
*/
