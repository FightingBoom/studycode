#include "stdio.h"

const int tempArraySize = 8;
const int k = 3;

const int tempArray[tempArraySize] = 
{
    3,
    -1,
    2,
    10,
    8,
    1,
    3,
    7
};

int main()
{
    int x1 = 0;
    int x2 = 0;
    int x3 = 0;
    int max1 = 0;
    int max2 = 0;

    printf("size[%d] k[%d]\n", tempArraySize, k);

    for (int i = 0; i < tempArraySize - k; i++)
    {
        x1 = tempArray[i];
        x2 = tempArray[i + 1];
        x3 = tempArray[i + 2];
        max1 = x1 > x2 ? x1 : x2;
        max2 = max1 > x3 ? max1 : x3;
        printf("%d ", max2);
    }
    printf("\n");

    return 0;
}
