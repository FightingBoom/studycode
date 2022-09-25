#include <stdio.h>

#define NONBLANK 'a'

int main()
{
    int iCurrentCharacter, iLastCharacter;
    
    iLastCharacter = NONBLANK;
    
    while((iCurrentCharacter = getchar()) != EOF)
    {
        // &&：当前字符和上一个字符都不能为空，因此结果中没有一个空格
        if((iCurrentCharacter != ' ') && (iLastCharacter != ' '))
        {
            putchar(iCurrentCharacter);
        }
        iLastCharacter = iCurrentCharacter;
    }
}