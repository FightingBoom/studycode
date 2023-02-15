#include "golf.h"
#include <iostream>
#include <cstring>

void setgolf(golf & g, const char * name, int hc)
{
    // g.fullname = &name;
    memcpy(g.fullname, &name, Len);
    g.handicap = hc;
}

int setgolf(golf & g)
{
    std::cout << "please enter fullname:" << std::endl;
    std::cin.getline(g.fullname, Len);
    // std::cin.clear();
    // std::cin.sync();

    if ('\0' == g.fullname[0])
    {
        std::cout << "fullname is NULL" << std::endl;
        return 0;
    }
    else
    {
        std::cout << "please enter handicap:" << std::endl;
        std::cin >> g.handicap;
    }

    std::cin.clear();
    std::cin.sync();
    return 1;
}

void handicap(golf & g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf & g)
{
    std::cout << "g.fullname = " << g.fullname << std::endl;
    std::cout << "g.handicap = " << g.handicap << std::endl;
}
