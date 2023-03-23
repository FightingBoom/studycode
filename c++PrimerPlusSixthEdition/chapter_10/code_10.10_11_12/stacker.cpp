#include <iostream>
#include <cctype>
#include "stack.h"

int main()
{
    using namespace std;

    Stack st;
    char ch;
    unsigned long po;

    cout << "Please enter A to add a purchase order,\n"
        << "P to process a PO, or Q to quit.\n";

    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }

        switch (ch)
        {
            case 'A':
            case 'a': // a/A不区分大小写
            {
                cout << "Enter a PO number to add: ";
                cin >> po;
                if (st.isfull())
                    cout << "stack already full\n";
                else
                    st.push(po);
                break;
            }
            case 'P':
            case 'p': // p/P不区分大小写
            {
                if (st.isempty())
                {
                    cout << "stack already empty\n";
                }
                else
                {
                    st.pop(po);
                    cout << "PO #" << po << " popped\n";
                }
                break;
            }
            default:
                cout << "not support command!!!\n";
                break;
        }

        cout << "Please enter A to add a purchase order,\n"
            << "P to process a PO, or Q to quit.\n";
    }

    cout << "Bye\n";
    return 0;
}

/*
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
A
Enter a PO number to add: 17885
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
P
PO #17885 popped
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
A
Enter a PO number to add: 17965
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
A
Enter a PO number to add: 18002
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
P
PO #18002 popped
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
P
PO #17965 popped
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
P
stack already empty
Please enter A to add a purchase order,
P to process a PO, or Q to quit.
Q
Bye 
*/

