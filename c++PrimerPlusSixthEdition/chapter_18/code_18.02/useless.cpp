#include <iostream>

using namespace std;

class Useless
{
private:
    int n;
    char * pc;
    static int ct;

    void ShowObject() const;

public:
    Useless();
    explicit Useless(int k);
    Useless(int k, char ch);
    Useless(const Useless & f);
    Useless(Useless && f);

    ~Useless();

    Useless operator+(const Useless & f) const;
    void ShowData() const;
};

int Useless::ct = 0;

Useless::Useless()
{
    ++ct;
    n = 0;
    pc = nullptr;
    cout << "default constructor called; number of "
        << "objects: " << ct << endl;
    ShowObject();
}

Useless::Useless(int k) : n(k)
{
    ++ct;
    cout << "int constructor called; number of objects: "
        << ct << endl;
    pc = new char[n];
    ShowObject();
}

Useless::Useless(int k, char ch) : n(k)
{
    ++ct;
    cout << "int, char constructor called; number of "
        << "objects: " << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; i++)
        pc[i] = ch;
    ShowObject();
}

Useless::Useless(const Useless & f) : n(f.n)
{
    ++ct;
    cout << "copy const called; number of objects: "
        << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; i++)
        pc[i] = f.pc[i];
    ShowObject();
}

Useless::~Useless()
{
    cout << "destructor called; objects left: "
        << --ct << endl;
    cout << "deleted object:\n";
    ShowObject();
    delete [] pc;
}

Useless Useless::operator+(const Useless & f) const
{
    cout << "Entering operator+()\n";
    Useless temp = Useless(n + f.n);
    for (int i = 0; i < n; i++)
        temp.pc[i] = pc[i];
    for (int i = n; i < temp.n; i++)
        temp.pc[i] = f.pc[i - n];
    cout << "temp object:\n";
    cout << "leaving operator+()\n";
    return temp;
}

void Useless::ShowObject() const
{
    cout << "Number of elements: " << n;
    cout << " Data address: " << (void *) pc << endl;
}

void Useless::ShowData() const
{
    if (n == 0)
        cout << "(object empty)";
    else
        for (int i = 0; i < n; i++)
            cout << pc[i];
    cout << endl;
}

int main()
{
    {
        Useless one(10, 'x');
        Useless two = one;
        Useless three(20, 'o');
        Useless four(one + three);

        cout << "object one: ";
        one.ShowData();
        cout << "object two: ";
        two.ShowData();
        cout << "object three: ";
        three.ShowData();
        cout << "object four: ";
        four.ShowData();
    }
}

/*
zhaochen@zhaochendeAir code_18.02 % ./a.out 
int, char constructor called; number of objects: 1
Number of elements: 10 Data address: 0x125e05dd0
copy const called; number of objects: 2
Number of elements: 10 Data address: 0x125e06000
int, char constructor called; number of objects: 3
Number of elements: 20 Data address: 0x125e06010
Entering operator+()
int constructor called; number of objects: 4
Number of elements: 30 Data address: 0x125e05f80
temp object:
leaving operator+()
object one: xxxxxxxxxx
object two: xxxxxxxxxx
object three: oooooooooooooooooooo
object four: xxxxxxxxxxoooooooooooooooooooo
destructor called; objects left: 3
deleted object:
Number of elements: 30 Data address: 0x125e05f80
destructor called; objects left: 2
deleted object:
Number of elements: 20 Data address: 0x125e06010
destructor called; objects left: 1
deleted object:
Number of elements: 10 Data address: 0x125e06000
destructor called; objects left: 0
deleted object:
Number of elements: 10 Data address: 0x125e05dd0
zhaochen@zhaochendeAir code_18.02 %
*/

/* -std=c++11
zhaochen@zhaochendeAir code_18.02 % ./a.out 
int, char constructor called; number of objects: 1
Number of elements: 10 Data address: 0x14b605dd0
copy const called; number of objects: 2
Number of elements: 10 Data address: 0x14b606000
int, char constructor called; number of objects: 3
Number of elements: 20 Data address: 0x14b606010
Entering operator+()
int constructor called; number of objects: 4
Number of elements: 30 Data address: 0x14b605f80
temp object:
leaving operator+()
object one: xxxxxxxxxx
object two: xxxxxxxxxx
object three: oooooooooooooooooooo
object four: xxxxxxxxxxoooooooooooooooooooo
destructor called; objects left: 3
deleted object:
Number of elements: 30 Data address: 0x14b605f80
destructor called; objects left: 2
deleted object:
Number of elements: 20 Data address: 0x14b606010
destructor called; objects left: 1
deleted object:
Number of elements: 10 Data address: 0x14b606000
destructor called; objects left: 0
deleted object:
Number of elements: 10 Data address: 0x14b605dd0
zhaochen@zhaochendeAir code_18.02 %
*/
