#include <iostream>
#include <cstring>


int main()
{
    using namespace std;

    const int Size = 15;
    char name1[Size];
    char name2[Size] = "C++owboy";

    cout << "Howdy! I'm " << name2;
    cout << "! What's your name?\n";
    
    cin >> name1;
    cout << "Well, " << name1 << ", your name has ";
    cout << strlen(name1) << " letters and is stored\n";    // strlen 实际输入长度

    cout << "in an array of " << sizeof(name1) << " bytes.\n";  // sizeof 数组大小
    cout << "Your initial is " << name1[0] << ".\n";

    name2[3] = '\0';
    cout << "Here are the first 3 characters of my name: ";
    cout << name2 << endl;

    return 0;
}


/*
Howdy! I'm C++owboy! What's your name?
Basicman
Well, Basicman, your name has 8 letters and is stored
in an array of 15 bytes.
Your initial is B.
Here are the first 3 characters of my name: C++
*/
