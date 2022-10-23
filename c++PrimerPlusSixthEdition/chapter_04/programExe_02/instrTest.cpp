#include <iostream>
#include <string>


int main()
{
    using namespace std;

    const int ArSize = 20;
    string strName;
    string strDessert;

    cout << "Enter your name:\n";
    getline(cin, strName);      // string 类型获取输入时，应使用 getline 接口，cin 作为第一个参数；

    cout << "Enter your favorite dessert:\n";
    getline(cin, strDessert);

    cout << "I have some delicious " << strDessert;
    cout << " for you, " << strName << ".\n";

    return 0;
}


/*
Enter your name:
Dirk Hammernose
Enter your favorite dessert:
Radish Torte
I have some delicious Radish Torte for you, Dirk Hammernose.
*/
