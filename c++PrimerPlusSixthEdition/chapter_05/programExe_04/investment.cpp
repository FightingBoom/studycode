#include <iostream>

using namespace std;

const int iCapital = 100;           // 本金
const float iDaphneInterest = 0.1;  // Daphne年利率
const float iCleoInterest = 0.05;   // Cleo年利率

int main()
{
    float iDaphneSum = iCapital;    // Daphne总投资价值
    float iCleoSum = iCapital;      // Cleo总投资价值
    int iYear = 1;                  // 年份

    while (1)
    {
        cout << "iYear = " << iYear << endl;

        iDaphneSum += iCapital * iDaphneInterest;
        cout << "iDaphneSum = " << iDaphneSum << endl;

        iCleoSum += iCleoSum * iCleoInterest;
        cout << "iCleoSum = " << iCleoSum << endl;

        if (iDaphneSum < iCleoSum)
        {
            cout << "iCleoSum: " << iCleoSum << " > iDaphneSum: " << iDaphneSum << endl;
            break;
        }
        else
        {
            iYear++;
        }
    }

    return 0;
}

/*
iYear = 1
iDaphneSum = 110
iCleoSum = 105
iYear = 2
iDaphneSum = 120
iCleoSum = 110.25
iYear = 3
iDaphneSum = 130
iCleoSum = 115.762
iYear = 4
iDaphneSum = 140
iCleoSum = 121.551
iYear = 5
iDaphneSum = 150
iCleoSum = 127.628
iYear = 6
iDaphneSum = 160
iCleoSum = 134.01
iYear = 7
iDaphneSum = 170
iCleoSum = 140.71
iYear = 8
iDaphneSum = 180
iCleoSum = 147.746
iYear = 9
iDaphneSum = 190
iCleoSum = 155.133
iYear = 10
iDaphneSum = 200
iCleoSum = 162.889
iYear = 11
iDaphneSum = 210
iCleoSum = 171.034
iYear = 12
iDaphneSum = 220
iCleoSum = 179.586
iYear = 13
iDaphneSum = 230
iCleoSum = 188.565
iYear = 14
iDaphneSum = 240
iCleoSum = 197.993
iYear = 15
iDaphneSum = 250
iCleoSum = 207.893
iYear = 16
iDaphneSum = 260
iCleoSum = 218.287
iYear = 17
iDaphneSum = 270
iCleoSum = 229.202
iYear = 18
iDaphneSum = 280
iCleoSum = 240.662
iYear = 19
iDaphneSum = 290
iCleoSum = 252.695
iYear = 20
iDaphneSum = 300
iCleoSum = 265.33
iYear = 21
iDaphneSum = 310
iCleoSum = 278.596
iYear = 22
iDaphneSum = 320
iCleoSum = 292.526
iYear = 23
iDaphneSum = 330
iCleoSum = 307.152
iYear = 24
iDaphneSum = 340
iCleoSum = 322.51
iYear = 25
iDaphneSum = 350
iCleoSum = 338.635
iYear = 26
iDaphneSum = 360
iCleoSum = 355.567
iYear = 27
iDaphneSum = 370
iCleoSum = 373.346
iCleoSum: 373.346 > iDaphneSum: 370
*/
