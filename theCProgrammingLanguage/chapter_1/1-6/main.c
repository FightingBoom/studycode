#include <stdio.h>

void GetCharTestV1();
void GetCharTestV2();
void GetCharTestV3();

int main()
{
    GetCharTestV3();
}

void GetCharTestV1()
{
    int c;

    // != 优先级大于 =
    while (c = (getchar() != EOF))
    {
        printf("While internal %d\n", c);
    }

    printf("While external %d\n", c);
}

void GetCharTestV2()
{
    int c;

    // != 优先级大于 =
    while (c = getchar() != EOF)
    {
        printf("While internal %d\n", c);
        if (c > 0)
            break;//c = 0;
    }

    printf("While external %d\n", c);
}

void GetCharTestV3()
{
    int c;

    // != 优先级大于 =
    while (c = getchar() != EOF)
    {
        printf("While internal %d\n", c);
        c = 0;
    }

    printf("While external %d\n", c);
}