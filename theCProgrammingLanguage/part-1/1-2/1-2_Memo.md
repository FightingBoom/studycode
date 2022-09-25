# 题目

做个实验，当 printf 函数的参数字符串中包含 \c （其中 c 是上面的转义字符序列中未曾列出的某个字符）时，观察一下会出现什么情况。


# 测试1

源代码如下

```c
#include <stdio.h>

int main()
{
    printf("hello,world\n");    // 正确代码
}
```

```shell
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-2$ cat main.c
#include <stdio.h>

int main()
{
    printf("hello,world\n");    // 正确代码
}zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-2$ gcc main.c 
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-2$ ./a.out 
hello,world
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-2$
```

可以看到这是一次正确的尝试，没有任何错误。

# 测试2

源代码如下

```c
#include <stdio.h>

int main()
{
    printf("hello,world\c");    // 错误尝试 1 ，\c
}
```

编译运行结果如下

```shell
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-2$ gcc main.c 
main.c: In function ‘main’:
main.c:6:12: warning: unknown escape sequence: '\c'
    6 |     printf("hello,world\c");    // 错误尝试1，\c
      |            ^~~~~~~~~~~~~~~
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-2$ ls -l
total 28
-rw-rw-r-- 1 zhaoc zhaoc  2978 11月 12 16:37 1-2_Memo.md
-rwxrwxr-x 1 zhaoc zhaoc 16696 11月 12 16:38 a.out
-rw-rw-r-- 1 zhaoc zhaoc   139 11月 12 16:38 main.c
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-2$ ./a.out 
hello,worldczhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-2$
```

有警告，但还是生成了可执行程序，但是未达到预期的结果。

# 测试3

源代码如下

```c
#include <stdio.h>

int main()
{
    printf("hello,world\7");    // 错误尝试 2 ，\7
}
```

编译运行结果如下

```shell
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-2$ gcc main.c 
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-2$ ./a.out 
hello,worldzhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-2$
```

编译没有警告，也没有报错，可以正常输出。

# 测试4

源代码如下：

```c
#include <stdio.h>

int main()
{
    printf("hello,world\?");    // 错误尝试 3 ，\?
}
```

编译运行结果如下

```shell
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-2$ gcc main.c 
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-2$ ./a.out 
hello,world?zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-2$
```

编译没有警告，没有报错，但是执行结果，多了一个 “?” ，也就是把转义的字符 “\?” 当做转义后正常字符 “?” 来输出了。

# 补充说明

结尾不同的转义字符，跟使用的编译器也是相关的。

参考《习题解答》提供的答案，出现 `<BELL>` 这种特殊说明，是 ASCII 值等于 7 的字符所产生的的一声短蜂鸣。
