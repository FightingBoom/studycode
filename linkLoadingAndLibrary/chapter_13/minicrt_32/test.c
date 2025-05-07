#include "minicrt.h"

int main(int argc, char *argv[])
{
    int i;
    FILE *fp;
    char **v = malloc(argc * sizeof(char *));
    for (i = 0; i < argc; ++i)
    {
        v[i] = malloc(strlen(argv[i]) + 1);
        strcpy(v[i], argv[i]);
    }

    fp = fopen("test.txt", "w");
    for (i = 0; i < argc; ++i)
    {
        int len = strlen(v[i]);
        fwrite(&len, 1, sizeof(int), fp);
        fwrite(v[i], 1, len, fp);
    }
    fclose(fp);

    fp = fopen("test.txt", "r");
    for (i = 0; i < argc; ++i)
    {
        int len;
        char *buf;
        fread(&len, 1, sizeof(int), fp);
        buf = malloc(len + 1);
        fread(buf, 1, len, fp);
        buf[len] = '\0';
        printf("%d %s\n", len, buf);
        
        free(buf);
        free(v[i]);
    }

    fclose(fp);
}


/* linux build cmd
$gcc -c -ggdb -fno-builtin -nostdlib -fno-stack-protector test.c 
$ld -static -e mini_crt_entry entry.o test.o minicrt.a –o test
$ ls -l test
-rwxr-xr-x 1 yujiazi yujiazi 5083 2008-08-19 21:59 test
$ ./test arg1 arg2 123
6 ./test
4 arg1
4 arg2
3 123
*/

