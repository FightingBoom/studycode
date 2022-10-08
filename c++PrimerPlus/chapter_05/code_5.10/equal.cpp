#include <iostream>
#include <string>

int main()
{
    using namespace std;

    int quizscores[10] = 
        {20, 20, 20, 20, 20, 19, 20, 18, 20, 20};
    
    cout << "Doing it right:\n";
    int i;
    for (i = 0; quizscores[i] == 20; i++)
        cout << "quiz " << i << " is a 20\n";

    cout << "Doing it dangerously wrong:\n";
    for (i = 0; quizscores[i] = 20; i++)    // 错误语法，此为赋值语句，而非判断语句，因此设备会一直打印，无法正常退出
        cout << "quiz " << i << " is a 20\n";
    
    return 0;
}


/*
Doing it right:
quiz 0 is a 20
quiz 1 is a 20
quiz 2 is a 20
quiz 3 is a 20
quiz 4 is a 20
Doing it dangerously wrong:
quiz 0 is a 20
quiz 1 is a 20
quiz 2 is a 20
quiz 3 is a 20
quiz 4 is a 20
quiz 5 is a 20
quiz 6 is a 20
quiz 7 is a 20
quiz 8 is a 20
......
*/
