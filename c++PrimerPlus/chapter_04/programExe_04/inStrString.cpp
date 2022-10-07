#include <iostream>
#include <string>


using namespace std;

int main()
{
    string strFirstName;
    string strLastName;

    cout << "Enter your first name? ";
    getline(cin, strFirstName);

    cout << "Enter your last name? ";
    getline(cin, strLastName);

    strLastName = strLastName + ", " + strFirstName;    // 使用 string 类自带的拼接方法

    cout << "Here's the information in a single string: " << strLastName << endl;

    return 0;
}


/*
Enter your first name? Flip
Enter your last name? Fleming
Here's the information in a single string: Fleming, Flip
*/

