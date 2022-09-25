# 题目

在自己的系统中运行“hello,world”程序。再有意去掉程序中的部分内容，看看会得到什么出错信息。


# 测试1

源代码如下

```c
#include <stdio.h>

int main()
{
    printf("hello,world");
}
```

编译运行结果如下

```shell
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-1$ cat main.c 
#include <stdio.h>

int main()
{
    printf("hello,world");
}zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-1$ gcc main.c 
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-1$ ./a.out 
hello,worldzhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-1$
```

这是正确的代码，因此编译没有任何错误。

# 测试2

源代码如下

```c
#include <stdio.h>

int main()
{
    printf("hello,world\n")
}
```

编译运行结果如下

```shell
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-1$ cat main.c 
#include <stdio.h>

int main()
{
    printf("hello,world\n")
}zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-1$ gcc main.c 
main.c: In function ‘main’:
main.c:5:28: error: expected ‘;’ before ‘}’ token
    5 |     printf("hello,world\n")
      |                            ^
      |                            ;
    6 | }
      | ~                           
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-1$
```

错误信息很明显，在第 5 行，第 28 列，缺少一个分号。

# 测试3

源代码如下

```c
#include <stdio.h>

int main()
{
    printf("hello,world\n');
}
```

编译运行结果如下

```shell
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-1$ cat main.c 
#include <stdio.h>

int main()
{
    printf("hello,world\n');
}zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-1$ gcc main.c 
main.c: In function ‘main’:
main.c:5:12: warning: missing terminating " character
    5 |     printf("hello,world\n');
      |            ^
main.c:5:12: error: missing terminating " character
    5 |     printf("hello,world\n');
      |            ^~~~~~~~~~~~~~~~~
main.c:6:1: error: expected expression before ‘}’ token
    6 | }
      | ^
main.c:5:12: error: expected ‘;’ before ‘}’ token
    5 |     printf("hello,world\n');
      |            ^
      |            ;
    6 | }
      | ~           
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-1$
```

很明显，可以看到在第 5 行，第 12 列，这个双引号是有一个警告；

接着后边的字符串是错误的，提示缺少了一个双引号；

然后在第 6 行，第 1 列，提示大括号错误，原因是没找到最后一个双引号，错把之前的全部当做字符串了；

接着又回到第 5 行，第 12 列，提示该行语句缺少了一个分号，原来的分号被当做字符串中的一部分了。