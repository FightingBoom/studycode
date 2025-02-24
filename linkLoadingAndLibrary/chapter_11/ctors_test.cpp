#include <stdio.h>

// [T2]
void my_init(void) __attribute__ ((constructor));
void my_init(void)
{
    printf("Hello ");
}

typedef void (*ctor_t)(void);
// [T1] ctor_t __attributes__((section (".ctors"))) \
// my_init_p = &my_init;

int main()
{
    printf("World!\n");
    return 0;
}

/* [T1]
会报 section 未定义错误。
*/

/* [T2]
zhaochen@zhaochendeAir chapter_11 % gcc ctors_test.cpp --std=c++11
zhaochen@zhaochendeAir chapter_11 % ./a.out          
Hello World!
zhaochen@zhaochendeAir chapter_11 %
*/
