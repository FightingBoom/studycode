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
    CandyBar* pSnack = new CandyBar [3];    // new申请内存

    pSnack[0] = {"candy 1", 1.0, 100};
    pSnack[1] = {"candy 2", 2.0, 200};
    pSnack[2] = {"Mocha Munch", 2.3, 350};

    for (int i = 0; i < 3; i++)     // 偷懒方法
    {
        cout << "pSnack[" << i << "].strName = " << pSnack[i].strName << endl;
        cout << "pSnack[" << i << "].fWeight = " << pSnack[i].fWeight << endl;
        cout << "pSnack[" << i << "].iCalorie = " << pSnack[i].iCalorie << endl;
    }

    delete [] pSnack;   // new申请的内存，结束前一定要释放掉
    return 0;
}


/*
pSnack[0].strName = candy 1
pSnack[0].fWeight = 1
pSnack[0].iCalorie = 100
pSnack[1].strName = candy 2
pSnack[1].fWeight = 2
pSnack[1].iCalorie = 200
pSnack[2].strName = Mocha Munch
pSnack[2].fWeight = 2.3
pSnack[2].iCalorie = 350
*/

