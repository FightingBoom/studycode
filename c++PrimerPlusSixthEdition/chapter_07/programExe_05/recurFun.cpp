#include <iostream>

using namespace std;

long long funRecur(int n);

int main()
{
    int iNumber;
    long long llReturn;
    
    cout << "Please Enter a number: ";

    while ((cin >> iNumber) && (iNumber > 0))
    {
        llReturn = funRecur(iNumber);
        cout << iNumber << "! = " << llReturn << endl;
        cout << "Please Enter next a number: ";
    }

    return 0;
}

long long funRecur(int n)
{
    long long llTemp;

    if (0 == n)
    {
        llTemp = 1;
    }
    else
    {
        llTemp = n * funRecur(n - 1); // 现在看好简单，没写出来之前，好难啊……
    }

    return llTemp;
}

/*
Please Enter a number: 4
4! = 24
Please Enter next a number: 5
5! = 120
Please Enter next a number: 6
6! = 720
Please Enter next a number: 7
7! = 5040
Please Enter next a number: 8
8! = 40320
Please Enter next a number: 9
9! = 362880
Please Enter next a number: 10
10! = 3628800
Please Enter next a number: 11
11! = 39916800
Please Enter next a number: -1
*/

/*
Please Enter a number: 4
4! = 24
Please Enter next a number: q
*/

