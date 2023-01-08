#include <iostream>
#include <new>

const int BUF = 521;
const int N = 5;
char buffer[BUF];

int main()
{
    using namespace std;
    double *pd1, *pd2;
    int i;
    cout << "Calling new and placement new:\n";
    pd1 = new double[N];            // 使用堆内存(heap)
    pd2 = new (buffer) double[N];   // 从buffer中给pd2分配内存地址
    for (i = 0; i < N; i++)
        pd2[i] = pd1[i] = 1000 + 20.0 * i;
    cout << "Memory addresses:\n" << "  heap: " << pd1
        << "  static: " << (void *)buffer << endl;
    cout << "Memory contents:\n";
    for (i = 0; i < N; i++)
    {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }


    // 第二次测试
    cout << "\nCalling new and placement new a second time:\n";
    double *pd3, *pd4;
    pd3 = new double[N];
    pd4 = new (buffer) double[N];
    for (i = 0; i < N; i++)
        pd4[i] = pd3[i] = 1000 + 40.0 * i;
    cout << "Memory contents:\n";
    for (i = 0; i < N; i++)
    {
        cout << pd3[i] << " at " << &pd3[i] << "; ";
        cout << pd4[i] << " at " << &pd4[i] << endl;
    }


    // 第三次测试
    cout << "\nCalling new and placement new a third time:\n";
    delete [] pd1;
    pd1 = new double[N];
    pd2 = new (buffer + N * sizeof(double)) double[N];
    for (i = 0; i < N; i++)
        pd2[i] = pd1[i] = 1000 + 60.0 * i;
    cout << "Memory contents:\n";
    for (i = 0; i < N; i++)
    {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }

    delete [] pd1;
    delete [] pd3;
    return 0;
}

/*
Calling new and placement new:
Memory addresses:
  heap: 0xe117b0  static: 0x408040
Memory contents:
1000 at 0xe117b0; 1000 at 0x408040
1020 at 0xe117b8; 1020 at 0x408048
1040 at 0xe117c0; 1040 at 0x408050
1060 at 0xe117c8; 1060 at 0x408058
1080 at 0xe117d0; 1080 at 0x408060

Calling new and placement new a second time:
Memory contents:
1000 at 0xe11b20; 1000 at 0x408040
1040 at 0xe11b28; 1040 at 0x408048
1080 at 0xe11b30; 1080 at 0x408050
1120 at 0xe11b38; 1120 at 0x408058
1160 at 0xe11b40; 1160 at 0x408060

Calling new and placement new a third time:
Memory contents:
1000 at 0xe117b0; 1000 at 0x408068
1060 at 0xe117b8; 1060 at 0x408070
1120 at 0xe117c0; 1120 at 0x408078
1180 at 0xe117c8; 1180 at 0x408080
1240 at 0xe117d0; 1240 at 0x408088
*/
