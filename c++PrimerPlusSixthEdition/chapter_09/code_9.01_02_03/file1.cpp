#include <iostream>
#include "coordin.h"

int main()
{
    rect rplace;
    polar pplace;

    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y)
    {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next two numbers (q to quit): "; // 实际只要为非数字输入，都会终止退出
    }
    cout << "Done.\n";
    return 0;
}

/*
# Win10编译命令： g++ .\file1.cpp .\file2.cpp
PS E:\91-GitRepository\studycode\c++PrimerPlusSixthEdition\chapter_09\code_9.01_02_03> .\a.exe
Enter the x and y values: 120 80
distance = 144.222, angle = 33.6901 degrees
Next two numbers (q to quit): 120 50
distance = 130, angle = 22.6199 degrees
Next two numbers (q to quit): q
Done.
*/
