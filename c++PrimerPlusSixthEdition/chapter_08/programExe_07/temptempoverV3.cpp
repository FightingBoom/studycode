#include <iostream>

using namespace std;

struct debts
{
    char name[50];
    double amount;
};


template <typename T>
void ShowArray(T arr[], int n);

template <typename T>
void ShowArray(T * arr[], int n);

template <typename T>
T SumArray(T arr[], int n);

template <typename T>
T SumArray(T * arr[], int n);

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
    int iSum = SumArray(things, 6);
    cout << "Listing Mr. E's counts off things sum: " << iSum << endl;

    cout << "Listing Mr. E's debts:\n";
    ShowArray(pd, 3); // 匹配到 template B，因为模板B更具体，做了特定的假设，数组内容是指针；
    double dSum = SumArray(pd, 3);
    cout << "Listing Mr. E's counts off things sum: " << dSum << endl;

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

template <typename T>
void ShowArray(T * arr[], int n)
{
    cout << "template B\n";
    for (int i = 0; i < n; i++)
        cout << *arr[i] << ' ';
    cout << endl;
}

template <typename T>
T SumArray(T arr[], int n)
{
    T sum = 0; // 局部变量，必须初始化
    cout << "template A-A\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
        sum += arr[i];
    }
    cout << endl;
    return sum;
}

template <typename T>
T SumArray(T * arr[], int n)
{
    T sum = 0; // 局部变量，必须初始化
    cout << "template B-B\n";
    for (int i = 0; i < n; i++)
    {
        cout << *arr[i] << ' ';
        sum += *arr[i];
    }
    cout << endl;
    return sum;
}



/*
# 模板内变量未初始化，结果错误！！！
Listing Mr. E's counts off things:
template A
13 31 103 301 310 130
template A-A
13 31 103 301 310 130
Listing Mr. E's counts off things sum: 894
Listing Mr. E's debts:
template B
2400 1300 1800
template B-B
2400 1300 1800 
Listing Mr. E's counts off things sum: 5500
*/

/*
# 模板内变量，增加初始化，正确！！！！！！！！！！！！！！！
Listing Mr. E's counts off things:
template A
13 31 103 301 310 130
template A-A
13 31 103 301 310 130
Listing Mr. E's counts off things sum: 888
Listing Mr. E's debts:
template B
2400 1300 1800
template B-B
2400 1300 1800
Listing Mr. E's counts off things sum: 5500
*/
