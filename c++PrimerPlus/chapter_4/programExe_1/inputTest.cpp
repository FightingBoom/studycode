#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

char * getname(void);

int main()
{
    char cTemp[20];
    vector<string> vStrBuffer;

    // memset(cTemp, 0, 20);
    cout << "What is your first name? ";
    cin.getline(cTemp, 20);
    // cout << "(string)cTemp = " << (string)cTemp << endl;
    vStrBuffer.push_back((string)cTemp);
    // cout << "vStrBuffer.size() = " << vStrBuffer.size() << endl;

    // memset(cTemp, 0, 20);
    cout << "What is your last name? ";
    cin.getline(cTemp, 20);
    // cout << "(string)cTemp = " << (string)cTemp << endl;
    vStrBuffer.push_back((string)cTemp);
    // cout << "vStrBuffer.size() = " << vStrBuffer.size() << endl;

    // memset(cTemp, 0, 20);
    cout << "What letter grade do you deserve? ";
    cin.getline(cTemp, 20);
    // cout << "(string)cTemp = " << (string)cTemp << endl;
    vStrBuffer.push_back((string)cTemp);
    // cout << "vStrBuffer.size() = " << vStrBuffer.size() << endl;

    // memset(cTemp, 0, 20);
    cout << "What is your age? ";
    cin.getline(cTemp, 20);
    // cout << "(string)cTemp = " << (string)cTemp << endl;
    vStrBuffer.push_back((string)cTemp);
    // cout << "vStrBuffer.size() = " << vStrBuffer.size() << endl;

    cout << "Name: " << vStrBuffer.at(1) << ", " << vStrBuffer.at(0) << endl;
    
    if ("B" == vStrBuffer.at(2))    // 可以直接写死，也可以加上字符判断
    {
        cout << "Grade: C" << endl;
    }
    else
    {
        cout << "Grade: " << vStrBuffer.at(2) << endl;
    }

    
    cout << "Age: " << vStrBuffer.at(3) << endl;


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
2、是否还有其他比 getline 、vector 更好的方案？后续需要进一步思考；
3、memset(cTemp, 0, 20); 实际测试，可以不用清零，因为每次 getline ，输入长度都是 20 ，也就是会从头开始覆盖；
*/
