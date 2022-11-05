#include <iostream>

using namespace std;

const char * qualify[4] = 
{
    "10,000-meter race.\n",
    "mud tug-of-war.\n",
    "masters canoe jousting.\n",
    "pie-throwing festival.\n"
};

int main()
{
    int age;

    cout << "Enter your age in years: ";
    cin >> age;
    int index;

    if (age > 17 && age < 35)
        index = 0;
    else if (age >= 35 && age < 50)
        index = 1;
    else if (age >= 50 && age < 65)
        index = 2;
    else
        index = 3;
    
    cout << "You qualify for the " << qualify[index];
    return 0;
}

/*
1、警惕此种写法 17 < age < 35 ，有效，但是会被识别为 (17 < age) < 35 ，即 0/1 < 35 ，结果总为真。
*/

/*
Enter your age in years: 87
You qualify for the pie-throwing festival.
*/
