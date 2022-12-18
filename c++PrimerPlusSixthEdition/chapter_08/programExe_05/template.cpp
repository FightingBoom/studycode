#include <iostream>

using namespace std;

const int MAX = 5;

template <typename T>
T maxn(T buffer[], int n = MAX)
{
    T temp;
    for (int i = 0; i < n - 1; i++)
    {
        temp = buffer[i] > buffer[i + 1] ? buffer[i] : buffer[i + 1];
    }

    return temp;
}

int main()
{
    int iTest[MAX] = {1, 3, 5, 9, 7};
    double dTest[MAX] = {1.2, 3.4, 5.6, 7.8, 9.9};

    int iResult = maxn(iTest);
    cout << iResult << endl;

    double dResult = maxn(dTest);
    cout << dResult << endl;

    return 0;
}

/*
9
9.9
*/
