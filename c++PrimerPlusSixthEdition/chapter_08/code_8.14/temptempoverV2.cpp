#include <iostream>

using namespace std;

struct debts
{
    char name[50];
    double amount;
};


template <typename T>
void ShowArray(T arr[], int n);

// template <typename T>
// void ShowArray(T * arr[], int n);

int main()
{
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3]
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    double * pd[3];

    for (int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;

    cout << "Listing Mr. E's counts off things:\n";
    ShowArray(things, 6);

    cout << "Listing Mr. E's debts:\n";
    ShowArray(pd, 3); // 匹配到 template B，因为模板B更具体，做了特定的假设，数组内容是指针；

    return 0;
}

template <typename T>
void ShowArray(T arr[], int n)
{
    cout << "template A\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

// template <typename T>
// void ShowArray(T * arr[], int n)
// {
//     cout << "template B\n";
//     for (int i = 0; i < n; i++)
//         cout << *arr[i] << ' ';
//     cout << endl;
// }

/*
# 未屏蔽模板B的调用结果
Listing Mr. E's counts off things:
template A
13 31 103 301 310 130
Listing Mr. E's debts:
template B
2400 1300 1800
*/

/*
# 屏蔽模板B的调用结果，使用模板A，打印出地址
Listing Mr. E's counts off things:
template A
13 31 103 301 310 130
Listing Mr. E's debts:
template A
0x61fd78 0x61fdb8 0x61fdf8
*/
