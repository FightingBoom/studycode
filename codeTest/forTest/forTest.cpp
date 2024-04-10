#include <iostream>

using namespace std;

const int MAX = 5;

void forMethod1()
{
    cout << "\nThis is i++ test start" << endl;

#if 0
    for (int i = 0; i < MAX; i++)
    {
        cout << "for start i = " << i << endl;

        cout << "for test" << endl;

        cout << "for end i = " << i << endl;
    }
#else
    int i;

    for (i = 0; i < MAX; i++)
    {
        cout << "for start i = " << i << endl;

        cout << "for test" << endl;

        cout << "for end i = " << i << endl;
    }

    cout << "for exit, i = " << i << endl;
#endif

    cout << "This is i++ test end\n" << endl;
}

void forMethod2()
{
    cout << "\nThis is ++i test start" << endl;

#if 0
    for (int i = 0; i < MAX; ++i)
    {
        cout << "for start i = " << i << endl;

        cout << "for test" << endl;

        cout << "for end i = " << i << endl;
    }
#else
    int i;

    for (i = 0; i < MAX; ++i)
    {
        cout << "for start i = " << i << endl;

        cout << "for test" << endl;

        cout << "for end i = " << i << endl;
    }

    cout << "for exit, i = " << i << endl;
#endif

    cout << "This is ++i test end\n" << endl;
}

int main()
{
    forMethod1();   // i++ test
    forMethod2();   // ++i test
}

