#include <iostream>

using std::cout;
using std::endl;

void change(const int * pt, int n);

int main()
{
    int pop1 = 38383;       // 可被const_cast后修改
    const int pop2 = 2000;  // 无法被const_cast转换修改

    cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;

    change(&pop1, -103);

    change(&pop2, -103);

    cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;

    return 0;
}

void change(const int * pt, int n)
{
    int * pc;

    pc = const_cast<int *>(pt);

    *pc += n;
}

/*
zhaochen@zhaochendeAir code_15.19 % clang++ constcast.cpp 
zhaochen@zhaochendeAir code_15.19 % ./a.out 
pop1, pop2: 38383, 2000
pop1, pop2: 38280, 2000
*/

