#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int FILE_NAME_SIZE = 60;
const int PATRONS_NAME_SIZE = 32;

struct patronsInfo
{
    char strPatronsName[PATRONS_NAME_SIZE];
    double dPatronsMoney;
};

int main()
{
    int patronsCount = 0;

    char filename[FILE_NAME_SIZE];  // 存储文件名
    ifstream inFile;

    cout << "Enter name of data file: ";
    cin.getline(filename, FILE_NAME_SIZE);
    inFile.open(filename);
    if (!inFile.is_open())  // 打开失败
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }

    patronsInfo * allPatronsInfo = new patronsInfo[patronsCount];

    inFile >> patronsCount;
    cout << patronsCount << endl;

    char str[PATRONS_NAME_SIZE];
    inFile.getline(str, 1);

    for (int i = 0; i < patronsCount; i++)
    {
        inFile.getline(allPatronsInfo[i].strPatronsName, PATRONS_NAME_SIZE);
        cout << allPatronsInfo[i].strPatronsName << endl;

        inFile >> allPatronsInfo[i].dPatronsMoney;
        cout << allPatronsInfo[i].dPatronsMoney << endl;

        inFile.getline(str, 1); // 读取数字后边的换行符
    }

    cout << "\nThis is Grand Patrons\n";
    for (int i = 0; i < patronsCount; i++)
    {
        if (allPatronsInfo[i].dPatronsMoney > 10000)
        {
            if (!strcmp(allPatronsInfo[i].strPatronsName, "\0"))
                cout << "none" << "\t" << allPatronsInfo[i].dPatronsMoney << endl;
            else
                cout << allPatronsInfo[i].strPatronsName << "\t" << allPatronsInfo[i].dPatronsMoney << endl;
        }
    }

    cout << "\nThis is Patrons\n";
    for (int i = 0; i < patronsCount; i++)
    {
        if (allPatronsInfo[i].dPatronsMoney <= 10000)
        {
            if (!strcmp(allPatronsInfo[i].strPatronsName, "\0"))
                cout << "none" << "\t" << allPatronsInfo[i].dPatronsMoney << endl;
            else
                cout << allPatronsInfo[i].strPatronsName << "\t" << allPatronsInfo[i].dPatronsMoney << endl;
        }
    }

    delete [] allPatronsInfo;   // new分配内存，用完一定要记得删除；
    return 0;
}


/*
Enter name of data file: patrons.txt
4
Sam Stone
2000
Freida Flass
100500
Tammy Tubbs
5000
Rich Raptor
55000

This is Grand Patrons
none    100500
none    55000

This is Patrons
none    2000
none    5000
*/


/* 姓名为空
Enter name of data file: patrons.txt
4
Sam Stone
2000

100500
Tammy Tubbs
5000
Rich Raptor
55000

This is Grand Patrons
none    100500
Rich Raptor     55000

This is Patrons
Sam Stone       2000
Tammy Tubbs     5000
*/

