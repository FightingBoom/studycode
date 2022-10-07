#include <iostream>

struct antarctica_years_end
{
    int year;
};

int main()
{
    antarctica_years_end s01, s02, s03;

    s01.year = 1998;    // s01 赋值

    antarctica_years_end * pa = &s02;   // 定义指针指向s02地址
    pa->year = 1999;    // 通过pa指针间接给s02结构体变量赋值；

    antarctica_years_end trio[3];
    trio[0].year = 2003;

    std::cout << "----- cout start -----" << std::endl;

    std::cout << "trio->year = " << trio->year << std::endl;            // 两种不同方式打印数组成员值
    std::cout << "(trio + 1)->year = " << (trio + 1)->year << std::endl;
    std::cout << "(trio + 2)->year = " << (trio + 2)->year << std::endl;

    std::cout << "\n----------\n" << std::endl;

    std::cout << "trio[0].year = " << trio[0].year << std::endl;
    std::cout << "trio[1].year = " << trio[1].year << std::endl;
    std::cout << "trio[2].year = " << trio[2].year << std::endl;

    std::cout << "\n----------\n" << std::endl;

    const antarctica_years_end * arp[3] = {&s01, &s02, &s03};       // 指针数组
    std::cout << "arp[1]->year = " << arp[1]->year << std::endl;
    std::cout << "arp[0]->year = " << arp[0]->year << std::endl;
    std::cout << "arp[2]->year = " << arp[2]->year << std::endl;

    std::cout << "\n----------\n" << std::endl;

    const antarctica_years_end **ppa = arp; // 这种写法，更容易操作，并知道当前变量是什么类型
    std::cout << "(*ppa)->year = " << (*ppa)->year << std::endl;
    std::cout << "(*(ppa + 1))->year = " << (*(ppa + 1))->year << std::endl;
    std::cout << "(*(ppa + 2))->year = " << (*(ppa + 2))->year << std::endl;

    std::cout << "\n----------\n" << std::endl;

    auto ppb = arp;
    std::cout << "(*(ppb + 1))->year = " << (*(ppb + 1))->year << std::endl;
    std::cout << "(*(ppb + 0))->year = " << (*(ppb + 0))->year << std::endl;
    std::cout << "(*(ppb + 2))->year = " << (*(ppb + 2))->year << std::endl;


    std::cout << "----- cout end -----" << std::endl;
    return 0;
}


/*
----- cout start -----
trio->year = 2003
(trio + 1)->year = 0
(trio + 2)->year = 4199705

----------

trio[0].year = 2003
trio[1].year = 0
trio[2].year = 4199705

----------

arp[1]->year = 1999
arp[0]->year = 1998
arp[2]->year = 0

----------

(*ppa)->year = 1998
(*(ppa + 1))->year = 1999
(*(ppa + 2))->year = 0

----------

(*(ppb + 1))->year = 1999
(*(ppb + 0))->year = 1998
(*(ppb + 2))->year = 0
----- cout end -----
*/
