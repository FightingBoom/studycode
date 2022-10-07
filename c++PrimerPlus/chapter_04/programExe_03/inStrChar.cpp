#include <iostream>
#include <cstring>


using namespace std;

int main()
{
    char cFirstName[20];    // first name，根据需要增大数组容量
    char cLastName[20];     // last name，根据需要增大数组容量

    cout << "Enter your first name? ";
    cin.getline(cFirstName, 20);

    cout << "Enter your last name? ";
    cin.getline(cLastName, 20);

    strcat(cLastName, ", ");        // 按规则使用 <cstring> 中的 strcat 接口，拼接字符串
    strcat(cLastName, cFirstName);

    cout << "Here's the information in a single string: " << cLastName << endl;

    return 0;
}


/*
Enter your first name? Flip
Enter your last name? Fleming
Here's the information in a single string: Fleming, Flip
*/

