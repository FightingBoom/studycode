# 题目

编写一个统计空格、制表符与换行符个数的程序

# 实际练习

实际测试代码如下

```c
#include <stdio.h>

int main()
{
    int iCharacter = 0;     // 输入单个字符
    int iNumBlanks = 0;     // 空白个数
    int iNumTabs = 0;       // 制表符个数
    int iNumNewlines = 0;   // 换行符个数

    while((iCharacter = getchar()) != EOF)
    {
        // if 与 if... else if... 结构均可；
        // 实际测试无太大差别，因为 getchar() 只能是单个字符输入；
        if(' ' == iCharacter) ++iNumBlanks;
        else if('\t' == iCharacter) ++iNumTabs;
        else if('\n' == iCharacter) ++iNumNewlines;
    }

    printf("blanks: %d, tabs: %d, newlines: %d\n", iNumBlanks, iNumTabs, iNumNewlines);
}
```

经过测试后的结果如下

![](https://gitee.com/FightingBoom/BlogPictures/raw/master/img_20200821/20220109152443.png)


特别说明

1、Linux 环境通过 Ctrl + D 输入 EOF 字符；

（1）参考链接：https://stackoverflow.com/questions/12389518/representing-eof-in-c-code/12389581