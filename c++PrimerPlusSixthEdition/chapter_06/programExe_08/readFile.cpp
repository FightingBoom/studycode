#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int FILE_NAME_SIZE = 60;

int main()
{
    char filename[FILE_NAME_SIZE];  // 存储文件名
    ifstream inFile;

    cout << "Enter name of data file: ";
    cin.getline(filename, FILE_NAME_SIZE);
    inFile.open(filename);
    if (!inFile.is_open())  // 打开失败
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }

    char ch;
    int whitespace = 0; // 空格、回车、换行符等
    int digits = 0;     // 数字
    int chars = 0;      // 字符
    int punct = 0;      // 标点符号
    int others = 0;     // 其他
    int totalNumbers = 0;

    inFile.get(ch);
    while (inFile.good())
    {
        if (isalpha(ch))        // 字符
            chars++;
        else if (isspace(ch))   // 空格、回车、换行符等
            whitespace++;
        else if (isdigit(ch))   // 数字
            digits++;
        else if (ispunct(ch))   // 标点符号
            punct++;
        else
            others++;
        
        inFile.get(ch);
    }

    if (inFile.eof())   // 读取到文件结尾
        cout << "End of file reached.\n";
    else if (inFile.fail())
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated for unknown reason.\n";

    cout << chars << " letters, "
        << whitespace << " whitespace, "
        << digits << " digits, "
        << punct << " punctuations, "
        << others << " others.\n";

    totalNumbers = chars + whitespace + digits + punct + others;
    cout << "total " << totalNumbers << " characters.\n";

    inFile.close(); // 使用完毕，必须关闭
    return 0;
}

/*
Enter name of data file: carinfo.txt
End of file reached.
44 letters, 13 whitespace, 18 digits, 6 punctuations, 0 others.
total 81 characters.
*/
