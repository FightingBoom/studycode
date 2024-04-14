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
    int i; // 循环变量声明放for循环之前，便于查看循环结束后的循环变量值

    for (i = 0; i < MAX; i++)
    {
        cout << "for start i = " << i << endl;

        cout << "for test" << endl;

        cout << "for end i = " << i << endl;
    }

	// 此时循环变量已是最后一次修改后的，但不满足循环条件的值
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

/*
zhaochen@zhaochendeAir forTest % ./a.out            

This is i++ test start
for start i = 0
for test
for end i = 0
for start i = 1
for test
for end i = 1
for start i = 2
for test
for end i = 2
for start i = 3
for test
for end i = 3
for start i = 4
for test
for end i = 4
for exit, i = 5
This is i++ test end


This is ++i test start
for start i = 0
for test
for end i = 0
for start i = 1
for test
for end i = 1
for start i = 2
for test
for end i = 2
for start i = 3
for test
for end i = 3
for start i = 4
for test
for end i = 4
for exit, i = 5
This is ++i test end

*/
