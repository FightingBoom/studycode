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


/*
please enter fullname:
zhao
please enter handicap:
123
g.fullname = zhao
g.handicap = 123
please enter fullname:

fullname is NULL
result = 0, quit!!!
*/

/*
please enter fullname:
zhao 1
please enter handicap:
1
g.fullname = zhao 1
g.handicap = 1
please enter fullname:
zhao 2
please enter handicap:
2
g.fullname = zhao 2
g.handicap = 2
please enter fullname:
zhao 3
please enter handicap:
3
g.fullname = zhao 3
g.handicap = 3
*/
