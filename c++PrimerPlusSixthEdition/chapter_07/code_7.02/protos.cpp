#include <iostream>


using namespace std;


// 函数原型声明
void cheers(int);       // 函数原型可以不需要变量名
double cube(double x);


int main()
{
    cheers(5);
    cout << "Give me a number: ";
    double side;
    cin >> side;
    double volume = cube(side);
    cout << "A " << side << "-foot cube has a volume of ";
    cout << volume << " cubic feet.\n";
    cheers(cube(2));

    return 0;
}


void cheers(int n)
{
    for (int i = 0; i < n; i++)
        cout << "Cheers! ";
    cout << endl;
}


double cube(double x)
{
    return x * x * x;
}


/*
Cheers! Cheers! Cheers! Cheers! Cheers! 
Give me a number: 1.5
A 1.5-foot cube has a volume of 3.375 cubic feet.
Cheers! Cheers! Cheers! Cheers! Cheers! Cheers! Cheers! Cheers!
*/
