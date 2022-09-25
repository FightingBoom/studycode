# 题目

修改温度转换程序，使之能在转换表的顶部打印一个标题。

# 测试1

源代码如下：

```c
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
```

编译运行结果如下

```shell
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-3$ gcc main.c 
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-3$ ./a.out 
Fahr Celsius
  0    -17.8
 20     -6.7
 40      4.4
 60     15.6
 80     26.7
100     37.8
120     48.9
140     60.0
160     71.1
180     82.2
200     93.3
220    104.4
240    115.6
260    126.7
280    137.8
300    148.9
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-3$
```

可以看到，这是一次正确的尝试，没有错误。

后续尝试修改了缩进，发现标题的 `Fahr Celsius` 中间用一个空格最合适。

打印 `%3.0f   %6.1f\n` 中间，使用一个 TAB 缩进，比较合适。