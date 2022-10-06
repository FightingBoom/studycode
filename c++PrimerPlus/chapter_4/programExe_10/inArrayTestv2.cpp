#include <iostream>
#include <array>
#include <numeric>

using namespace std;

int main()
{
    array<float, 3> aGrade; // 成绩

    cout << "Enter test result of 40m race: ";
    cin >> aGrade[0];

    cout << "Enter test result of 40m race: ";
    cin >> aGrade[1];
    
    cout << "Enter test result of 40m race: ";
    cin >> aGrade[2];

    cout << "Total input " << aGrade.size() << " times, and average score is: "
            << (aGrade[0] + aGrade[1] + aGrade[2]) / aGrade.size() << endl;

    return 0;
}


/*
Enter NO.1 test result of 40m race: 15.34
Enter NO.2 test result of 40m race: 16.78
Enter NO.3 test result of 40m race: 14.2123
Total input 3 times, and average score is: 15.4441
*/
