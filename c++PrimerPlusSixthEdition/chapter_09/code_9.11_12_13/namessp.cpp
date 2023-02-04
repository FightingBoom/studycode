#include <iostream>
#include "namesp.h"

/*
学到这个章节，才发现之前书本上有的代码，为啥不用全局名称，
原来是有含义的，避免名称空间冲突
*/

void other(void);
void another(void);

int main(void)
{
    using debts::Debt;
    using debts::showDebt;

    Debt golf = 
    {
        {
            "Benny",
            "Goatsniff"
        },
        120.0
    };

    showDebt(golf);
    other();
    another();

    return 0;
}

void other(void)
{
    using std::cout;
    using std::endl;
    using namespace debts;
    Person dg = {"Doodles", "Glister"};
    showPerson(dg);
    cout << endl;

    Debt zippy[3];
    int i;
    for (i = 0; i < 3; i++)
        getDebt(zippy[i]);  // 获取三次输入
    for (i = 0; i < 3; i++)
        showDebt(zippy[i]);
    cout << "Total debt: $" << sumDebts(zippy, 3) << endl;
    return;
}

void another(void)
{
    using pers::Person;
    Person collector = {"Milo", "Rightshift"};
    pers::showPerson(collector);
    std::cout << std::endl;
}

/*
Goatsniff, Benny: $120
Glister, Doodles      
Enter first name: Arabella
Enter last name: Binx
Enter debt: 100
Enter first name: Cleve
Enter last name: Delaproux  
Enter debt: 120
Enter first name: Eddie
Enter last name: Fiotox
Enter debt: 200
Binx, Arabella: $100  
Delaproux, Cleve: $120
Fiotox, Eddie: $200   
Total debt: $420      
Rightshift, Milo
*/
