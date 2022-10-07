#include <iostream>


using namespace std;

struct CandyBar
{
    string strName;     // 糖果品牌名
    float fWeight;      // 重量
    int iCalorie;       // 卡路里
};

int main()
{
    CandyBar snack = {"Mocha Munch", 2.3, 350};

    cout << "snack.strName = " << snack.strName << endl;
    cout << "snack.fWeight = " << snack.fWeight << endl;
    cout << "snack.iCalorie = " << snack.iCalorie << endl;

    return 0;
}


/*
snack.strName = Mocha Munch
snack.fWeight = 2.3
snack.iCalorie = 350
*/

