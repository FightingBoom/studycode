#include <stdio.h>


int main()
{
    int iCurrentCharacter;
    
    while ((iCurrentCharacter = getchar()) != EOF)
    {
        switch (iCurrentCharacter)
        {
            case '\t':
            {
                putchar("\\t");
                break;
            }
            case '\b':
            {
                putchar("\\b");
                break;
            }
            case '\\':
            {
                putchar("\\");
                break;
            }
            default:
            {
                putchar(iCurrentCharacter);
                break;
            }
        }
    }
}