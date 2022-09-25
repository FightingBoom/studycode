#include <stdio.h>

int main()
{
    float fFahr, fCelsius;      // 华氏、摄氏
    int iLower, iUpper, iStep;  // 最低，最高，步进长度

    iLower = 0;
    iUpper = 300;
    iStep  = 20;

    printf("Fahr Celsius\n");
    fFahr = iLower;
    while (fFahr <= iUpper)
    {
        fCelsius = (5.0 / 9.0) * (fFahr - 32.0);
        printf("%3.0f   %6.1f\n", fFahr, fCelsius);
        fFahr += iStep;
    }
    
    return 0;
}