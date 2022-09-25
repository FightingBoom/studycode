#include <stdio.h>

#define MAXHIST     15      // 直方图最大长度
#define MAXWORD     11      // 一个单词最大长度
#define IN          1       // 单词起始符
#define OUT         0       // 单词结束符

void main()
{
    /*
     * c: 输入字符
     * i: 循环计数
     * nc: 每个单词长度，范围 0 < nc < MAXWORD
     * state: 单词起始、结束的标志位
     */
    int c, i, nc, state;
    int len;
    int maxvalue;
    int ovflow;
    int wl[MAXWORD];

    state = OUT;
    nc = 0;
    ovflow = 0;
    
    for (i = 0; i < MAXWORD; ++i)   // 数组清空
        wl[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')   // 单词结尾
        {
            state = OUT;
            if (nc < MAXWORD)   // MAXWORD内的单词，则对应长度计数+1
                ++wl[nc];
            else
                ++ovflow;
        }
        else if (state == OUT)
        {
            state = IN;
            nc = 1;     // 检测到单词起始位
        }
        else
        {
            ++nc;       // 字符个数累加
        }
    }

    maxvalue = 0;
    for (i = 1; i < MAXWORD; ++i)
    {
        if (wl[i] > maxvalue)
            maxvalue = wl[i];   // MAXWORD内的单词，同一长度个数最多
    }

    printf("Length\t Counts\n");    // 标题计数
    for (i = 1; i < MAXWORD; ++i)
    {
        printf("%5d - %5d : ", i, wl[i]);   // 单词长度 - 同一长度单词个数

        if (wl[i] > 0)
        {
            if((len = wl[i] * MAXHIST / maxvalue) <= 0) // 计算星号数量
                len = 1;
        }
        else
        {
            len = 0;
        }

        while (len > 0)
        {
            putchar('*');
            --len;
        }
        putchar('\n');
    }

    if (ovflow > 0) // MAXWORD外的单词个数
    {
        printf("There are %d words >= %d\n", ovflow, MAXWORD);
    }
}