#include <stdio.h>

int main()
{
    float fFahr;        // 华氏度
    float fCelsius;     // 摄氏度

    int iLow = 0;       // 最低值
    int iUpper = 300;   // 最高值
    int iStep = 20;     // 步进间隔

    printf("      Title\nCelsius     Fahr\n");
    fCelsius = iUpper;

    while (fCelsius >= iLow)
    {
        fFahr = (9.0 * fCelsius) / 5.0 + 32.0;
        printf("%3.0f       %6.1f\n", fCelsius, fFahr);
        fCelsius -= iStep;
    }
    

    return 0;
}