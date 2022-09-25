# 题目

修改温度转换程序，要求以逆序（即按照从300度到0度的顺序）打印温度转换表。

# 测试1

源代码如下：

```c
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
```

编译运行结果如下：

```shell
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-5$ date
2021年 12月 09日 星期四 22:32:38 CST
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-5$ gcc main.c 
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-5$ ./a.out 
      Title
Celsius     Fahr
300        572.0
280        536.0
260        500.0
240        464.0
220        428.0
200        392.0
180        356.0
160        320.0
140        284.0
120        248.0
100        212.0
 80        176.0
 60        140.0
 40        104.0
 20         68.0
  0         32.0
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-5$
```