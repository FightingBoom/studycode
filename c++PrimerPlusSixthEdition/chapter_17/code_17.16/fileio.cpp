#include <iostream>
#include <fstream>
#include <string>

int main()
{
    using namespace std;
    string filename;

    cout << "Enter name for new file: ";
    cin >> filename;

    // 用输入的文件名，创建一个新文件
    ofstream fout(filename.c_str());

    fout << "For your eyes only!\n";
    cout << "Enter your secret number: ";
    float secret;
    cin >> secret;
    fout << "Your secret number is " << secret << endl;
    fout.close(); // 关闭并刷新文件显示

    ifstream fin(filename.c_str());
    cout << "Here are the contents of "
        << filename << ":\n";
    char ch;
    while (fin.get(ch))
        cout << ch;
    cout << "Done\n";
    fin.close();

    return 0;
}

/*
zhaochen@zhaochendeMacBook-Air code_17.16 % clang++ fileio.cpp 
zhaochen@zhaochendeMacBook-Air code_17.16 % ./a.out 
Enter name for new file: pythag
Enter your secret number: 3.14159
Here are the contents of pythag:
For your eyes only!
Your secret number is 3.14159
Done
*/

