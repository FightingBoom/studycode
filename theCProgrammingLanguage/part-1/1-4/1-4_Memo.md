# 题目

编写一个程序打印摄氏温度转换为相应华氏温度的转换表。

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
    fCelsius = iLow;

    while (fCelsius <= iUpper)
    {
        fFahr = (9.0 * fCelsius) / 5.0 + 32.0;
        printf("%3.0f       %6.1f\n", fCelsius, fFahr);
        fCelsius += iStep;
    }
    

    return 0;
}
```

编译运行结果如下：

```shell
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-4$ ./a.out 
      Title
Celsius     Fahr
  0         32.0
 20         68.0
 40        104.0
 60        140.0
 80        176.0
100        212.0
120        248.0
140        284.0
160        320.0
180        356.0
200        392.0
220        428.0
240        464.0
260        500.0
280        536.0
300        572.0
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-4$
```