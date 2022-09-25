#include <stdio.h>

#define NONBLANK 'a'

int main()
{
    int iCurrentCharacter, iLastCharacter;
    
    iLastCharacter = NONBLANK;
    
    while((iCurrentCharacter = getchar()) != EOF)
    {
        if(iCurrentCharacter != ' ')
        {
            putchar(iCurrentCharacter);
        }
        else
        {
            if(iLastCharacter != ' ')   // 输出非空字符后的第一个空格
            {
                putchar(iCurrentCharacter);
            }
        }
        iLastCharacter = iCurrentCharacter;
    }
}