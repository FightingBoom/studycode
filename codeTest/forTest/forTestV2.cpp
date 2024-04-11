#include <iostream>

using namespace std;

const int MAX = 5;

void forMethod3()
{
    cout << "\nThis is i++ test V2 start" << endl;

    int i;
    for (i = 0; i < MAX;)
    {
        cout << "for start i = " << i << endl;

        cout << "for test, start i++" << endl;

        i++;

        cout << "for end i = " << i << endl;
    }

    cout << "for exit, i = " << i << endl;

    cout << "This is i++ test V2 end\n" << endl;
}

void forMethod4()
{
    cout << "\nThis is ++i test V2 start" << endl;

    int i;
    for (i = 0; i < MAX;)
    {
        cout << "for start i = " << i << endl;

        cout << "for test, start ++i" << endl;

        ++i;

        cout << "for end i = " << i << endl;
    }

    cout << "for exit, i = " << i << endl;

    cout << "This is ++i test V2 end\n" << endl;
}

int main()
{
    forMethod3();
    forMethod4();
}

/*
zhaochen@zhaochendeAir forTest % ./a.out              

This is i++ test V2 start
for start i = 0
for test, start i++
for end i = 1
for start i = 1
for test, start i++
for end i = 2
for start i = 2
for test, start i++
for end i = 3
for start i = 3
for test, start i++
for end i = 4
for start i = 4
for test, start i++
for end i = 5
for end, i = 5
This is i++ test V2 end


This is ++i test V2 start
for start i = 0
for test, start ++i
for end i = 1
for start i = 1
for test, start ++i
for end i = 2
for start i = 2
for test, start ++i
for end i = 3
for start i = 3
for test, start ++i
for end i = 4
for start i = 4
for test, start ++i
for end i = 5
for end, i = 5
This is ++i test V2 end

*/
