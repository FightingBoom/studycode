#include <iostream>

using namespace std;

int main()
{
    char cFirstName[20];    // first name，根据需要增大数组容量
    char cLastName[20];     // last name，根据需要增大数组容量
    char cGrade;            // grade
    int iAge;               // age

    cout << "What is your first name? ";
    cin.getline(cFirstName, 20);
    cin.clear();
    cin.sync();

    cout << "What is your last name? ";
    cin.getline(cLastName, 20);
    cin.clear();
    cin.sync();

    cout << "What letter grade do you deserve? ";
    cin.get(cGrade);
    cin.clear();
    cin.sync();

    cout << "What is your age? ";
    cin >> iAge;
    cin.clear();
    cin.sync();

    cout << "Name: " << cLastName << ", " << cFirstName << endl;
    cout << "Grade: " << (char)(cGrade + 1) << endl;
    cout << "Age: " << iAge << endl;

    return 0;
}


/*
What is your first name? Betty Sue
What is your last name? Yewe
What letter grade do you deserve? B
What is your age? 22
Name: Yewe, Betty Sue
Grade: C
Age: 22
*/

/* 思考点
1、cin 输入需要使用 getline ，否则输入内容有空格会被截断；
2、cin 每次输入后，需要 clear 、sync 清空缓存区，否则后续的输入不会被执行；
3、数字最好使用整型，char 类型只会打印出来一个字符；
*/
