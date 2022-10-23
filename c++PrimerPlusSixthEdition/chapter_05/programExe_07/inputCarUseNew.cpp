#include <iostream>
#include <string>

using namespace std;

struct CarInfo
{
    string strManufacturer;     // 生产商
    int iYear;                  // 生产年份
};

int main()
{
    int iUserCarNumber = 0; // 用户汽车数量

    cout << "How many cars do you wish to catalog? ";
    cin >> iUserCarNumber;

    CarInfo * pCarInfo = new CarInfo [iUserCarNumber];

    for (int i = 0; i < iUserCarNumber; i++)
    {
        cout << "Car #" << i + 1 << ":" << endl;

        cout << "Please enter the make: ";
        cin.get();  // cin缓冲区有之前输入数字的换行符，不加此语句，会导致无法输入字符串，因为检测到换行符直接就结束了
        getline(cin, pCarInfo[i].strManufacturer);

        cout << "Please enter the year made: ";
        cin >> pCarInfo[i].iYear;
    }

    cout << "Here is your collection:" << endl;
    for (int i = 0; i < iUserCarNumber; i++)
    {
        cout << pCarInfo[i].iYear << " " << pCarInfo[i].strManufacturer << endl;
    }

    delete [] pCarInfo;
    return 0;
}


/*
How many cars do you wish to catalog? 2
Car #1:
Please enter the make: Hudson Hornet
Please enter the year made: 1952
Car #2:
Please enter the make: Kaiser
Please enter the year made: 1951
Here is your collection:
1952 Hudson Hornet
1951 Kaiser

-----------------------------

How many cars do you wish to catalog? 3
Car #1:
Please enter the make: one car
Please enter the year made: 2022
Car #2:
Please enter the make: second car
Please enter the year made: 2021
Car #3:
Please enter the make: the third car
Please enter the year made: 2020
Here is your collection:
2022 one car
2021 second car
2020 the third car
*/
