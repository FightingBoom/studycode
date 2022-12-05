#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

int Fill_array(double * buffer);
void Show_array(const double * buffer, int size);
void Reverse_array(double * begin, double * end);

int main()
{
    double buffer[MAX_SIZE] = {0};

    int size = Fill_array(buffer);
    Show_array(buffer, size);

    Reverse_array(buffer, buffer + size);
    Show_array(buffer, size);

    Reverse_array(buffer + 1, buffer + size - 1);
    Show_array(buffer, size);

    cout << "Done." << endl;
    return 0;
}

int Fill_array(double * buffer)
{
    int i = 0; // 也可用for循环
    cout << "Please input score(q or quit end input)#" << i << " ";
    while (cin >> buffer[i] && (i < MAX_SIZE) && (buffer[i] > 0))
    {
        cout << "Please input next score(q or quit end input)#" << ++i << ": ";
    }
    return i;
}

void Show_array(const double * buffer, int size)
{
    for (int i = 0; i < size; i++)
        cout << buffer[i] << " ";
    cout << endl;
}

void Reverse_array(double * begin, double * end)
{
    double * pBegin;
    double * pEnd;
    double temp;
    for (pBegin = begin, pEnd = end - 1; pBegin < pEnd; pBegin++, pEnd--)
    {
        temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;
    }
}

/*
Please input score(q or quit end input)#0 1
Please input next score(q or quit end input)#1: 2
Please input next score(q or quit end input)#2: 3
Please input next score(q or quit end input)#3: 4
Please input next score(q or quit end input)#4: 5
Please input next score(q or quit end input)#5: q
1 2 3 4 5 
5 4 3 2 1
5 2 3 4 1
Done.
*/

/*
Please input score(q or quit end input)#0 1
Please input next score(q or quit end input)#1: 2
Please input next score(q or quit end input)#2: 3
Please input next score(q or quit end input)#3: 4
Please input next score(q or quit end input)#4: 5
Please input next score(q or quit end input)#5: 6
Please input next score(q or quit end input)#6: 7
Please input next score(q or quit end input)#7: 8
Please input next score(q or quit end input)#8: 9
Please input next score(q or quit end input)#9: 10
Please input next score(q or quit end input)#10: 11
1 2 3 4 5 6 7 8 9 10 
10 9 8 7 6 5 4 3 2 1
10 2 3 4 5 6 7 8 9 1
Done.
*/
