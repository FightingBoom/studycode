#include <stdio.h>


int main()
{
    int iCurrentCharacter;
    
    while ((iCurrentCharacter = getchar()) != EOF)
    {
        if (iCurrentCharacter == '\t')
            printf("\\t");
        if (iCurrentCharacter == '\b')
            printf("\\b");
        if (iCurrentCharacter == '\\')
            printf("\\\\");
        if ((iCurrentCharacter != '\t')
            && (iCurrentCharacter != '\b')
            && (iCurrentCharacter != '\\'))
        {
            putchar(iCurrentCharacter);
        }
    }
}