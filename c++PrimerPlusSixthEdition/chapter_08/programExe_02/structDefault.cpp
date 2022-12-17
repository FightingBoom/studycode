#include <iostream>

using namespace std;

struct CandyBar
{
    string strCandyName;
    double dWeight;
    int iCalorie;
};

void setCandyBarValue(CandyBar & candy, char * name = (char *)"Millennium Munch", double weight = 2.85, int calorie = 350);
void showCandy(const CandyBar & candy);

int main()
{
    CandyBar candy;
    setCandyBarValue(candy);
    showCandy(candy);

    setCandyBarValue(candy, (char *)"hello", 3.14, 15926);
    showCandy(candy);

    return 0;
}

void setCandyBarValue(CandyBar & candy, char * name, double weight, int calorie)
{
    candy.strCandyName = name;
    candy.dWeight = weight;
    candy.iCalorie = calorie;
}

void showCandy(const CandyBar & candy)
{
    cout << "candy name: " << candy.strCandyName << endl;
    cout << "candy weight: " << candy.dWeight << endl;
    cout << "candy calorie: " << candy.iCalorie << endl;
}

/*
candy name: Millennium Munch
candy weight: 2.85
candy calorie: 350
candy name: hello
candy weight: 3.14
candy calorie: 15926
*/
