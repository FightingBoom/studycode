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
                printf("\\t");
                break;
            }
            case '\b':
            {
                printf("\\b");
                break;
            }
            case '\\':
            {
                printf("\\");
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