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
    PizzaInfo* pPizza = new PizzaInfo;

    cout << "Enter pizza company name: ";
    getline(cin, pPizza->strName);      // 指针：p->name / (*p).name；变量：p.name;
    
    cout << "Enter pizza diameter (inche): ";
    cin >> pPizza->fDiameter;

    cout << "Enter pizza weight (pound): ";
    cin >> pPizza->fWeight;

    // This is an 8-inch 6-pound pizza from ABC Company
    cout << "This is an " << pPizza->fDiameter << "-inch " << pPizza->fWeight << "-pound "
            << "pizza from " << pPizza->strName << " Company" << endl;

    delete pPizza;
    return 0;
}


/*
Enter pizza company name: rob moon
Enter pizza diameter (inche): 1.234
Enter pizza weight (pound): 3.456
This is an 1.234-inch 3.456-pound pizza from rob moon Company
*/



