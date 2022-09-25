# 题目

验证表达式 `getchar() != EOF` 的值是0还是1

# 实际测试

> void GetCharTestV1()

编译运行结果如下：

```shell
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-6$ date
2021年 12月 09日 星期四 22:52:16 CST
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-6$ gcc main.c 
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-6$ ./a.out 
1
While internal 1
While internal 1
2
While internal 1
While internal 1

```

分析结果如下：

1、只要输入，没到文件结尾，结果都是1；

2、为什么会出现两次 `While internal 1` 呢？

 - 输入 `1` 会打印一次，按下 `回车` 会打印一次；
 - `getchar()` 函数每次只能读取一个字符；


> void GetCharTestV2()

编译运行结果如下：

```shell
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-6$ date
2021年 12月 09日 星期四 22:56:41 CST
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-6$ gcc main.c 
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-6$ ./a.out 
1
While internal 1
While external 1
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-6$
```

分析结果如下：

1、添加了 `break` 之后，会退出 `while` 循环；

2、同样会打印两次 `While internal 1` ；


> void GetCharTestV3()

编译运行结果如下：

```shell
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-6$ date
2021年 12月 09日 星期四 22:58:58 CST
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-6$ gcc main.c 
zhaoc@ubuntu2004:~/09-GitRepository/TheCProgrammingLanguage/part-1/1-6$ ./a.out 
1
While internal 1
While internal 1
2
While internal 1
While internal 1
3
While internal 1
While internal 1

```

分析结果如下：

1、添加 `c = 0;` 是没有用的，为什么呢？因为 `while` 的判断条件，是先计算 `getchar() != EOF` ，然后再给 c 赋值，因此没有用；可以这样理解这个顺序：

1. 第一次进入 `while` 循环
2. 计算 `getchar() != EOF` ；
3. 将第二步的结果，赋值给 c ；
4. 判断 while 条件为真，执行循环体；
5. 运行 `printf` 代码；
6. 执行 `c = 0;` ；
7. 需要再次进行条件判断，计算 `getchar() != EOF` ；
8. 将第二步的结果，赋值给 c ，此时的 c 在第 7 步已经被重新赋值了，不会为 0 ，因此没有用。


