#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

int inputArray(double * buffer);
void showArray(const double * buffer, int size);
double ProcessAverage(double * buffer, int size);

int main()
{
    double buffer[MAX_SIZE] = {0};

    int size = inputArray(buffer);
    showArray(buffer, size);
    double average = ProcessAverage(buffer, size);
    cout << "average = " << average << endl;

    cout << "Done." << endl;
    return 0;
}

int inputArray(double * buffer)
{
    int i = 0; // 也可用for循环
    cout << "Please input score(q or quit end input)#" << i + 1 << " ";
    while (cin >> buffer[i] && (i < MAX_SIZE))
    {
        i++;
        cout << "Please input next score(q or quit end input)#" << i + 1 << ": ";
    }
    return i;
}

void showArray(const double * buffer, int size)
{
    for (int i = 0; i < size; i++)
        cout << buffer[i] << " ";
    cout << endl;
}

double ProcessAverage(double * buffer, int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; i++)
        sum += buffer[i];
    return sum / size;
}

/*
Please input score(q or quit end input)#1 12
Please input next score(q or quit end input)#2 23
Please input next score(q or quit end input)#3 43
Please input next score(q or quit end input)#4 123
Please input next score(q or quit end input)#5 24
Please input next score(q or quit end input)#6 32
Please input next score(q or quit end input)#7 312
Please input next score(q or quit end input)#8 3123
Please input next score(q or quit end input)#9 123
Please input next score(q or quit end input)#10 432
Please input next score(q or quit end input)#11 342
12 23 43 123 24 32 312 3123 123 432 
average = 424.7
Done.
*/
