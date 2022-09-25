# 题目

编写一个打印 EOF 值的程序；

# 实际测试

代码示例如下

```c
#include <stdio.h>

int main()
{
    printf("EOF is %d\n", EOF);
}
```

编译运行结果如下

```shell
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-7$ gcc EOFV1.c 
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-7$ ./a.out 
EOF is -1
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-7$
```

查看 EOF 定义如下

![](https://gitee.com/FightingBoom/BlogPictures/raw/master/img_20200821/20220109145455.png)