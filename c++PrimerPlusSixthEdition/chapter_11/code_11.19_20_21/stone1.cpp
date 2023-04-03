#include <iostream>
#include "stonewt1.h"

int main()
{
    using std::cout;

    Stonewt poppins(9, 2.8);
    double p_wt = poppins;

    cout << "Convert to double => ";
    cout << "Poppins: " << p_wt << " pounds.\n";

    cout << "Convert to int => ";
    cout << "Poppins: " << int (poppins) << " pounds.\n"; // 强制类型转换

    return 0;
}

/*
Convert to double => Poppins: 128.8 pounds.
Convert to int => Poppins: 129 pounds.
*/
