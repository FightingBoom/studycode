#include <iostream>

using namespace std;

const int SLEN = 30;

struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int coplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student * ps);
void display3(const student pa[], int n);

int main()
{
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
        continue;
    
    student * ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);

    delete [] ptr_stu;

    cout << "Done\n";
    return 0;
}

int getinfo(student pa[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << "Enter fullname #" << i + 1 << ": ";
        cin.getline(pa[i].fullname, SLEN);

        cout << "Enter hobby #" << i + 1 << ": ";
        cin.getline(pa[i].hobby, SLEN);

        cout << "Enter coplevel #" << i + 1 << ": ";
        cin >> pa[i].coplevel;
        if (!cin) // 输入错误，非数字输入
        {
            cin.clear(); // 清空输入缓冲区
            while (cin.get() != '\n') // 循环读取，并丢弃无效的字符串
                continue;
            cout << "Bad input; input process terminated.\n";
            break;
        }
        cin.get();
    }

    cout << "input i = " << i << endl;
    return i;
}

void display1(student st)
{
    cout << "fullname = " << st.fullname << endl;
    cout << "hobby = " << st.hobby << endl;
    cout << "coplevel = " << st.coplevel << endl;
}

void display2(const student * ps)
{
    cout << "fullname = " << ps->fullname << endl;
    cout << "hobby = " << ps->hobby << endl;
    cout << "coplevel = " << ps->coplevel << endl;
}

void display3(const student pa[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "fullname = " << pa[i].fullname << endl;
        cout << "hobby = " << pa[i].hobby << endl;
        cout << "coplevel = " << pa[i].coplevel << endl;
    }
}

/*
Enter class size: 3  
Enter fullname #1: ab ab
Enter hobby #1: cd cd 
Enter coplevel #1: 4
Enter fullname #2: efef efef
Enter hobby #2: hjhj hjhj hjhj
Enter coplevel #2: ik ik            
Bad input; input process terminated.
input i = 1
fullname = ab ab
hobby = cd cd
coplevel = 4
fullname = ab ab
hobby = cd cd
coplevel = 4
fullname = ab ab
hobby = cd cd
coplevel = 4
Done
*/

/*
Enter class size: 4  
Enter fullname #1: a
Enter hobby #1: b
Enter coplevel #1: 1
Enter fullname #2: c
Enter hobby #2: d
Enter coplevel #2: 2
Enter fullname #3: e
Enter hobby #3: f
Enter coplevel #3: 3
Enter fullname #4: h
Enter hobby #4: i
Enter coplevel #4: 4
input i = 4
fullname = a
hobby = b
coplevel = 1
fullname = a
hobby = b
coplevel = 1
fullname = c
hobby = d
coplevel = 2
fullname = c
hobby = d
coplevel = 2
fullname = e
hobby = f
coplevel = 3
fullname = e
hobby = f
coplevel = 3
fullname = h
hobby = i
coplevel = 4
fullname = h
hobby = i
coplevel = 4
fullname = a
hobby = b
coplevel = 1
fullname = c
hobby = d
coplevel = 2
fullname = e
hobby = f
coplevel = 3
fullname = h
hobby = i
coplevel = 4
Done
*/



