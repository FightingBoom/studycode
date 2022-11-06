#include <iostream>

using namespace std;

const int Max = 5;

int main()
{
    int golf[Max];
    cout << "Please enter your golf scores.\n";
    cout << "You must enter " << Max << " rounds.\n";

    int i = 0;  // 序号
    for (i = 0; i < Max; i++)
    {
        cout << "round #" << i + 1 << ": ";
        while (!(cin >> golf[i]))   // 如果输入成功，则进入下一个 for 循环，否则必须输入正确的整形
        {
            cin.clear();
            while (cin.get() != '\n')   // 依次读取当前行所有的非法输入，并丢弃。
                continue;
            cout << "Please enter a number: ";
        }
    }

    double total = 0.0;
    for (i = 0; i < Max; i++)
        total += golf[i];

    cout << total / Max << " = average score " << Max << " rounds\n";

    return 0;
}

/*
Please enter your golf scores.
You must enter 5 rounds.
round #1: 88
round #2: 87
round #3: must i?
Please enter a number: 103
round #4: 94
round #5: 86
91.6 = average score 5 rounds
*/
