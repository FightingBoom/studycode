#include <iostream>
#include "stock10.h"

int main()
{
    {
        using std::cout;
        cout << "Using constructors to create new objects\n";
        Stock stock1("NanoSmart", 12, 20.0);
        stock1.show();

        Stock stock2 = Stock ("Boffo Objects", 2, 2.0);
        stock2.show();

        cout << "Assigning stock1 to stock2:\n";
        stock2 = stock1;
        cout << "Listing stock1 and stock2:\n";
        stock1.show();
        stock2.show();

        cout << "Using a constructor to reset an object\n";
        stock1 = Stock("Nifty Foods", 10, 50.0);
        cout << "Revised stock1:\n";
        stock1.show();
        cout << "Done\n";
    } // 为了方便我们看到析构函数执行过程，否则需要等main退出才析构，就看不到了。

    return 0;
}

/*
Using constructors to create new objects
Constructor using NanoSmart called
Company: NanoSmart Shares: 12
  Share Price: $20.000  Total Worth: $240.00
Constructor using Boffo Objects called
Company: Boffo Objects Shares: 2
  Share Price: $2.000  Total Worth: $4.00
Assigning stock1 to stock2:
Listing stock1 and stock2:
Company: NanoSmart Shares: 12
  Share Price: $20.000  Total Worth: $240.00
Company: NanoSmart Shares: 12
  Share Price: $20.000  Total Worth: $240.00
Using a constructor to reset an object
Constructor using Nifty Foods called
Bye, Nifty Foods!
Revised stock1:
Company: Nifty Foods Shares: 10
  Share Price: $50.000  Total Worth: $500.00
Done
Bye, NanoSmart!
Bye, Nifty Foods!
*/
