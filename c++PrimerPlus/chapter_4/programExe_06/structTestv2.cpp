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
    CandyBar snack[3] = 
    {
        {"candy 1", 1.0, 100},
        {"candy 2", 2.0, 200},
        {"Mocha Munch", 2.3, 350}
    };

    for (int i = 0; i < 3; i++)     // 偷懒方法
    {
        cout << "snack[" << i << "].strName = " << snack[i].strName << endl;
        cout << "snack[" << i << "].fWeight = " << snack[i].fWeight << endl;
        cout << "snack[" << i << "].iCalorie = " << snack[i].iCalorie << endl;
    }

    return 0;
}


/*
snack[0].strName = candy 1
snack[0].fWeight = 1
snack[0].iCalorie = 100
snack[1].strName = candy 2
snack[1].fWeight = 2
snack[1].iCalorie = 200
snack[2].strName = Mocha Munch
snack[2].fWeight = 2.3
snack[2].iCalorie = 350
*/

