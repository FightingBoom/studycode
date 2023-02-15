#include <iostream>
#include <cstring>
#include "golf.h"

const int MAX = 3;

int main()
{
    golf teamInfo[MAX];
    memset(teamInfo, 0, sizeof(golf) * MAX); // 临时变量初始化

    int result = 0;
    for (int i = 0; i < MAX; i++)
    {
        result = setgolf(teamInfo[i]);
        if (0 == result)
        {
            std::cout << "result = 0, quit!!!" << std::endl;
            break;
        }

        showgolf(teamInfo[i]);
    }

    return 0;
}


