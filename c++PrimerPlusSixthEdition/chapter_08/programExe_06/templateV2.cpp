#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 5;

template <typename T>
T maxn(T buffer[], int n = MAX);

template <> char * maxn(char * buffer[], int n);

void showAddress(char * buffer[], int n);

int main()
{
    int iTest[6] = {1, 3, 5, 9, 7, 11};
    double dTest[4] = {1.2, 3.4, 7.8, 9.9};
    char * strBuffer[5] = 
    {
        (char *)"hello",
        (char *)"hello world!!!", // 两次不同测试结果在下方
        (char *)"hello world!!!",
        (char *)"hello china!",
        (char *)"hello, love"
    };

    int iResult = maxn(iTest, 6);
    cout << iResult << endl;

    double dResult = maxn(dTest, 4);
    cout << dResult << endl;

    showAddress(strBuffer, 5);
    char * cResult = maxn(strBuffer, 5);

    // cout打印地址需要强制转换，参考教程此处使用的&，获取的是临时变量的地址
    cout << (void *)cResult << endl;

    cout << "Done!\n";
    return 0;
}

template <typename T>
T maxn(T buffer[], int n)
{
    T temp;
    for (int i = 0; i < n - 1; i++)
    {
        temp = buffer[i] > buffer[i + 1] ? buffer[i] : buffer[i + 1];
    }

    return temp;
}

template <> char * maxn(char * buffer[], int n)
{
    int Number = 0;
    int maxLength = 0; // 必须初始化，否则值不确定
    for (int i = 0; i < n; i++)
    {
        // cout << "--test-1- str:" << buffer[i] << ", length:" << strlen(buffer[i]) << endl;
        // cout << "--test-2- " << Number << endl;
        if (maxLength < strlen(buffer[i])) // 只有大于的时候，才会更新序号，否则就是第一个最大的地址
        {
            // cout << "--test-3- " << maxLength << endl;
            maxLength = strlen(buffer[i]);
            Number = i;
            // cout << "--test-4- " << Number << endl;
        }
    }

    cout << &buffer[Number] << endl;
    return (char *)&buffer[Number];
    // char * address = buffer[Number]; // 参考博客教程方法，获取的为外层字符串地址
    // return address;
}

void showAddress(char * buffer[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "buffer[" << i << "] = " << buffer[i] << ", address = " << &buffer[i] << endl;
    }
}

/*
11
9.9
buffer[0] = hello, address = 0x61fda0
buffer[1] = hello world!!!, address = 0x61fda8
buffer[2] = hello world!!!, address = 0x61fdb0
buffer[3] = hello china!, address = 0x61fdb8
buffer[4] = hello, love, address = 0x61fdc0
0x61fda8
0x61fda8
*/

/*
11
9.9
buffer[0] = hello, address = 0x61fda0
buffer[1] = hello world!!!, address = 0x61fda8
buffer[2] = hello world!!!, address = 0x61fdb0
buffer[3] = hello china!, address = 0x61fdb8
buffer[4] = hello, love, address = 0x61fdc0
0x61fda8
0x61fda8
Done!
*/

/*
11
9.9
buffer[0] = hello, address = 0x61fda0
buffer[1] = hello world!!, address = 0x61fda8
buffer[2] = hello world!!!, address = 0x61fdb0
buffer[3] = hello china!, address = 0x61fdb8
buffer[4] = hello, love, address = 0x61fdc0
0x61fdb0
0x61fdb0
*/

/*
11
9.9
buffer[0] = hello, address = 0x61fda0
buffer[1] = hello world!!, address = 0x61fda8
buffer[2] = hello world!!!, address = 0x61fdb0
buffer[3] = hello china!, address = 0x61fdb8
buffer[4] = hello, love, address = 0x61fdc0
0x61fdb0
0x61fdb0
Done!
*/
