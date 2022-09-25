#include <stdio.h>

#define NONBLANK 'a'

int main()
{
    int iCurrentCharacter, iLastCharacter;
    
    iLastCharacter = NONBLANK;
    
    while((iCurrentCharacter = getchar()) != EOF)
    {
        // ||：当前字符不为空，或者当前字符为空，上个字符不为空，都能输出；这样可以保留一个空格。
        if((iCurrentCharacter != ' ') || (iLastCharacter != ' '))
        {
            putchar(iCurrentCharacter);
        }
        iLastCharacter = iCurrentCharacter;
    }
}