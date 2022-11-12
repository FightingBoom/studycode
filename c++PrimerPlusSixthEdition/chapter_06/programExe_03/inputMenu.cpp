#include <iostream>

using namespace std;

void showmenu();
void report();
void comfort();

int main()
{
    showmenu();

    char choice;
    cin >> choice;
    while (('c' != choice)
            && ('p' != choice)
            && ('t' != choice)
            && ('g' != choice)) // 只做输入字符检查
    {
        cout << "Please enter a c, p, t, or g: ";
        cin >> choice;
    }

    switch (choice) // 根据输入字符，显示对应内容
    {
        case 'c':
            cout << "carnivore\n";
            break;
        case 'p':
            report();
            break;
        case 't':
            cout << "A maple is a tree\n";
            break;
        case 'g':
            comfort();
            break;
        default:
            cout << "That's not a choice.\n";
            break;
    }

    cout << "Bye!\n";
    return 0;
}

void showmenu()
{
    cout << "Please enter one of the following choices:\n"
        "c) carnivore   p) pianist\n"
        "t) tree        g) game\n";
}

void report()
{
    cout << "pianist\n";
}

void comfort()
{
    cout << "game\n";
}

/*
Please enter one of the following choices:
c) carnivore   p) pianist
t) tree        g) game
f
Please enter a c, p, t, or g: q
Please enter a c, p, t, or g: t
A maple is a tree
Bye!
*/

