#include <iostream>
#include <string>

using namespace std;

struct patronsInfo
{
    string strPatronsName;
    double dPatronsMoney;
};

int main()
{
    int patronsCount = 0;

    cout << "Enter the total patrons count: ";
    cin >> patronsCount;

    patronsInfo * allPatronsInfo = new patronsInfo[patronsCount];

    for (int i = 0; i < patronsCount; i++)
    {
        cin.clear();    // 每次获取数据前，清空缓冲区
        cin.sync();

        cout << "Enter the patrons name:\n";
        getline(cin, allPatronsInfo[i].strPatronsName);

        cout << "Enter the patrons money: ";
        cin >> allPatronsInfo[i].dPatronsMoney;
    }

    cout << "\nThis is Grand Patrons\n";
    for (int i = 0; i < patronsCount; i++)
    {
        if (allPatronsInfo[i].dPatronsMoney > 10000)
        {
            if (allPatronsInfo[i].strPatronsName.empty())
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
            if (allPatronsInfo[i].strPatronsName.empty())
                cout << "none" << "\t" << allPatronsInfo[i].dPatronsMoney << endl;
            else
                cout << allPatronsInfo[i].strPatronsName << "\t" << allPatronsInfo[i].dPatronsMoney << endl;
        }
    }

    delete [] allPatronsInfo;   // new分配内存，用完一定要记得删除；
    return 0;
}


/*
Enter the total patrons count: 3
zhao 111
Enter the patrons money: 8000
Enter the patrons name:
han 222
Enter the patrons money: 11000
Enter the patrons name:
chen 333
Enter the patrons money: 30000
This is Grand Patrons
han 222         11000
chen 333                30000
This is Patrons
zhao 111                8000


Enter the total patrons count: 3
Enter the patrons name:
zhao 1
Enter the patrons money: 8000
Enter the patrons name:
han 2
Enter the patrons money: 10000
Enter the patrons name:
chen 3 
Enter the patrons money: 21000
This is Grand Patrons
chen 3  21000
This is Patrons
zhao 1  8000
han 2   10000


Enter the total patrons count: 4
Enter the patrons name:
zhao 1
Enter the patrons money: 8000
Enter the patrons name:
zhao 2
Enter the patrons money: 90000
Enter the patrons name:
zh 3  
Enter the patrons money: 20000
Enter the patrons name:
sfwsjoeawf 12 sdjoif
Enter the patrons money: 10001

This is Grand Patrons
zhao 2  90000
zh 3    20000
sfwsjoeawf 12 sdjoif    10001

This is Patrons
zhao 1  8000
*/

