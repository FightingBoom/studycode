#include <iostream>
#include "strngbad.h"

using std::cout;

void callme1(StringBad &);
void callme2(StringBad);

int main()
{
    using std::endl;
    {
        cout << "Starting an inner block.\n";
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bowl for Dollars");

        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;

        callme1(headline1);
        cout << "headline1: " << headline1 << endl;

        callme2(headline2); // 按值（非引用）传递，会隐形调用析构函数
        cout << "headline2: " << headline2 << endl;

        cout << "Initialize one object to another:\n";
        StringBad sailor = sports;
        cout << "sailor: " << sailor << endl;

        cout << "Assign one object to another:\n";
        StringBad knot;
        knot = headline1;
        cout << "knot: " << knot << endl;
        cout << "Exiting the block.\n";
    } // 使析构过程可视化

    cout << "End of main()\n";

    return 0;
}

void callme1(StringBad & rsb)
{
    cout << "String passed by reference:\n";
    cout << "   \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
    cout << "String passed by value:\n";
    cout << "   \"" << sb << "\"\n";
}

/* // Win10 环境运行，最后应该是崩溃了，没有End of main()打印
Starting an inner block.
1: "Celery Stalks at Midnight" object created
2: "Lettuce Prey" object created
3: "Spinach Leaves Bowl for Dollars" object created
headline1: Celery Stalks at Midnight
headline2: Lettuce Prey
sports: Spinach Leaves Bowl for Dollars
String passed by reference:
   "Celery Stalks at Midnight"
headline1: Celery Stalks at Midnight
String passed by value:
   "Lettuce Prey"
"Lettuce Prey" object deleted, 2 left
headline2: P
nitialize one object to another:
sailor: Spinach Leaves Bowl for Dollars
Assign one object to another:
3: "C++" default object created
knot: Celery Stalks at Midnight
Exiting the block.
"Celery Stalks at Midnight" object deleted, 2 left
"Spinach Leaves Bowl for Dollars" object deleted, 1 left
"€f?
*/
