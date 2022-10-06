#include <iostream>


using namespace std;

struct PizzaInfo
{
    string strName;     // 名称
    float fDiameter;    // 直径
    float fWeight;      // 重量
};

int main()
{
    PizzaInfo pizza;

    cout << "Enter pizza company name: ";
    getline(cin, pizza.strName);
    
    cout << "Enter pizza diameter (inche): ";
    cin >> pizza.fDiameter;

    cout << "Enter pizza weight (pound): ";
    cin >> pizza.fWeight;

    // This is an 8-inch 6-pound pizza from ABC Company
    cout << "This is an " << pizza.fDiameter << "-inch " << pizza.fWeight << "-pound "
            << "pizza from " << pizza.strName << " Company" << endl;

    return 0;
}


/*
Enter pizza company name: rob moon
Enter pizza diameter (inche): 12.345
Enter pizza weight (pound): 23.456
This is an 12.345-inch 23.456-pound pizza from rob moon Company
*/



