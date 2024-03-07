#include <iostream>
#include <string>
#include <cctype>

#include "stacktp.h"

using std::cin;
using std::cout;

int main()
{
    Stack<std::string> st;
    char ch;
    std::string po;

    cout << "Please enter A to add a purchase order,\n"
        << "P to process a PO, or Q to quit.\n";

    // 获取输入，并判断字符，q转换为大写Q再做比较
    while (cin >> ch && std::toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;

        if (!std::isalpha(ch))
        {
            cout << '\a';
        }

        switch (ch)
        {
            case 'A':
            case 'a':
            {
                cout << "Enter a PO number to add: ";
                cin >> po;
                if (st.isfull())
                {
                    cout << "stack already full\n";
                }
                else
                {
                    st.push(po);
                }
                break;
            }
            case 'P':
            case 'p':
            {
                if (st.isempty())
                {
                    cout << "stack already empty\n";
                }
                else
                {
                    st.pop(po);
                    cout << "PO #" << po << " popped\n";
                    break;
                }
            }
        }

        cout << "Please enter A to add a purchase order,\n"
            << "P to process a PO, or Q to quit.\n";
    }

    cout << "Bye\n";
    return 0;
}

/*
zhaochen@zhaochendeMacBook-Air code_14.13_14 % ./a.out
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
A
Enter a PO number to add: red911porsche
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
A
Enter a PO number to add: blueR8audi
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
A
Enter a PO number to add: silver747boeing
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
P
PO #silver747boeing popped
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
P
PO #blueR8audi popped
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
P
PO #red911porsche popped
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
P
stack already empty
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
Q
Bye
*/

/*
zhaochen@zhaochendeMacBook-Air code_14.13_14 % ./a.out
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
a
Enter a PO number to add: werw
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
p
PO #werw popped
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
p
stack already empty
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
q
Bye
*/

