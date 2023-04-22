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
    char * buffer = new char[BUF];

    JustTesting *pc1, *pc2;

    pc1 = new (buffer) JustTesting;
    pc2 = new JustTesting("Heap1", 20);

    cout << "Memory block addresses:\n" << "buffer: "
        << (void *) buffer << "    heap: " << pc2 << endl;
    cout << "Memory contents:\n";
    cout << pc1 << ": ";
    pc1->Show();
    cout << pc2 << ": ";
    pc2->Show();

    JustTesting *pc3, *pc4;
    // 如果想要内存不重叠，则可调整为：pc3 = new (buffer + sizeof(JustTesting)) JustTesting("Bad Idea", 6);
    pc3 = new (buffer) JustTesting("Bad Idea", 6);
    pc4 = new JustTesting("Heap2", 10);

    cout << "Memory contents:\n";
    cout << pc3 << ": ";
    pc3->Show();
    cout << pc4 << ": ";
    pc4->Show();

    delete pc2;
    delete pc4;
    delete [] buffer; // 释放buffer并不会释放 pc1 pc3
    cout << "Done\n";
    return 0;
}

/*
Just Testing constructed
Heap1 constructed
Memory block addresses:
buffer: 0xf81b20    heap: 0xf817b0
Memory contents:
0xf81b20: Just Testing, 0
0xf817b0: Heap1, 20
Bad Idea constructed
Heap2 constructed
Memory contents:
0xf81b20: Bad Idea, 6
0xf81d30: Heap2, 10
Heap1 destroyed
Heap2 destroyed
Done
*/
