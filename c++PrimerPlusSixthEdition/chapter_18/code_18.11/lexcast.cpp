#include <iostream>
#include <string>
#include "boost/lexical_cast.hpp"

using namespace std;

int main()
{
    cout << "Enter your weight: ";
    float weight;
    cin >> weight;
    string gain = "A 10% increase raises ";
    string wt = boost::lexical_cast<string>(weight);
    gain = gain + wt + " to ";
    weight = 1.1 * weight;
    gain = gain + boost::lexical_cast<string>(weight) + ".";
    cout << gain << endl;

    return 0;
}

/* 用 brew 安装的 boost 库，需要添加依赖。
zhaochen@zhaochendeAir code_18.11 % clang++ lexcast.cpp -I/opt/homebrew/opt/boost/include -L/opt/homebrew/opt/boost/lib -std=c++11
zhaochen@zhaochendeAir code_18.11 % ./a.out
Enter your weight: 150
A 10% increase raises 150 to 165.
zhaochen@zhaochendeAir code_18.11 % ./a.out
Enter your weight: 156
A 10% increase raises 156 to 171.600006.
zhaochen@zhaochendeAir code_18.11 %
*/

