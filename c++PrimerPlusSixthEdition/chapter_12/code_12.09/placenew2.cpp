#include <iostream>
#include <string>
#include <new>

using namespace std;

const int BUF = 512;

class JustTesting
{
private:
    string words;
    int number;

public:
    JustTesting(const string & s = "Just Testing", int n = 0)
    {
        words = s;
        number = n;
        cout << words << " constructed\n";
    }

    ~JustTesting()
    {
        cout << words << " destroyed" << endl;
    }

    void Show() const
    {
        cout << words << ", " << number << endl;
    }
};

int main()
{
    char * buffer = new char[BUF]; // 申请一块内存区域，相当于自己申请的一块临时内存池，自己管理

    JustTesting *pc1, *pc2;

    pc1 = new (buffer) JustTesting; // pc1从buffer的首地址开始
    pc2 = new JustTesting("Heap1", 20);

    cout << "Memory block addresses:\n" << "buffer: "
        << (void *) buffer << "    heap: " << pc2 << endl;
    cout << "Memory contents:\n";
    cout << pc1 << ": ";
    pc1->Show();
    cout << pc2 << ": ";
    pc2->Show();

    JustTesting *pc3, *pc4;
    pc3 = new (buffer + sizeof(JustTesting)) JustTesting("Bad Idea", 6); // 避免与pc1踩到同一块内存
    pc4 = new JustTesting("Heap2", 10);

    cout << "Memory contents:\n";
    cout << pc3 << ": ";
    pc3->Show();
    cout << pc4 << ": ";
    pc4->Show();

    delete pc2; // 未指定内存地址的，直接delete即可
    delete pc4;
    pc3->~JustTesting();
    pc1->~JustTesting();    // 显式调用析构函数，释放pc1/pc3
    delete [] buffer;       // 先释放内存中已被使用的地址，再释放整个内存块
    cout << "Done\n";
    return 0;
}

/*
Just Testing constructed
Heap1 constructed
Memory block addresses:
buffer: 0xf61b20    heap: 0xf617b0
Memory contents:
0xf61b20: Just Testing, 0
0xf617b0: Heap1, 20
Bad Idea constructed
Heap2 constructed
Memory contents:
0xf61b48: Bad Idea, 6
0xf61d30: Heap2, 10
Heap1 destroyed
Heap2 destroyed
Bad Idea destroyed
Just Testing destroyed
Done
*/
