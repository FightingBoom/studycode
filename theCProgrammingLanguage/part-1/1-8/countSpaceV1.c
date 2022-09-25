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