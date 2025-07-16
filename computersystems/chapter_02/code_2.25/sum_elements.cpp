#include <iostream>

float sum_elements(float a[], unsigned length)
{
    int i;
    float result = 0;

    for (i = 0; i <= length - 1; i++)
    {
        printf("i[%d] length[%u] length-1 = %d\n", i, length, length - 1);
        result += a[i];
    }

    return result;
}

int main(void)
{
    float testA[10] = {0.0};
    sum_elements(testA, 0);
    return 0;
}


