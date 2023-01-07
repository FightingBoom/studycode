#include <iostream>

int tom = 3;
int dick = 30;
static int harry = 300;

void remote_access(); // 在另一个文件中定义；

int main()
{
    using namespace std;
    cout << "main() reports the following addresses:\n";
    cout << &tom << " = &tom, " << &dick << " = &dick, ";
    cout << &harry << " = &harry\n";
    remote_access();

    return 0;
}

/*
PS E:\91-GitRepository\studycode\c++PrimerPlusSixthEdition\chapter_09\code_9.07_08> g++ .\twofile1.cpp .\twofile2.cpp
PS E:\91-GitRepository\studycode\c++PrimerPlusSixthEdition\chapter_09\code_9.07_08> .\a.exe
main() reports the following addresses:
0x403010 = &tom, 0x403014 = &dick, 0x403018 = &harry
remote_access() reports the following addresses:
0x403010 = &tom, 0x403020 = &dick, 0x403024 = &harry
*/
