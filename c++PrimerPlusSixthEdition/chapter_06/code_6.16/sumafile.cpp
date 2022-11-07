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

    double value = 0.0;
    double sum = 0.0;
    int count = 0;

    inFile >> value;
    while (inFile.good())
    {
        ++count;
        sum += value;
        cout << "sum: " << sum << ", value: " << value << endl;
        inFile >> value;
    }

    if (inFile.eof())   // 读取到文件结尾
        cout << "End of file reached.\n";
    else if (inFile.fail())
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated for unknown reason.\n";

    if (0 == count)
        cout << "No data processed.\n";
    else
    {
        cout << "Items read: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;
    }

    inFile.close();

    return 0;
}


/*
scores.txt共3行，最后一行未使用回车换行，导致最后一个数据没有被输入

Enter name of data file: scores.txt
sum: 37, value: 19
sum: 55.5, value: 18.5
sum: 69, value: 13.5
sum: 83, value: 14
sum: 99, value: 16
sum: 118.5, value: 19.5
sum: 138.5, value: 20
sum: 156.5, value: 18
sum: 168.5, value: 12
sum: 187, value: 18.5
End of file reached.
Items read: 11
Sum: 187
Average: 17
*/

/*
scores.txt共4行，最后一行使用回车换行

Enter name of data file: scores.txt
sum: 18, value: 18
sum: 37, value: 19
sum: 55.5, value: 18.5
sum: 69, value: 13.5
sum: 83, value: 14
sum: 99, value: 16
sum: 118.5, value: 19.5
sum: 138.5, value: 20
sum: 156.5, value: 18
sum: 168.5, value: 12
sum: 187, value: 18.5
sum: 204.5, value: 17.5
End of file reached.
Items read: 12
Sum: 204.5
Average: 17.0417
*/


