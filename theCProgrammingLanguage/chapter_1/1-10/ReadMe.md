# inToOutV1 代码运行结果

输入内容

```shell
12\t34\b56\\78 12\t34\b56\\78 12\t34\b56\\78 12\t34\b56\\78
```

![image-20220215215055495](https://gitee.com/FightingBoom/BlogPictures/raw/master/img_20200821/20220215215055.png)

1、当检测到输入 **\t** 时，使用 putchar 输出特殊字符，会实现该效果。

2、疑问点

（1）：为啥只有一个字母 t b 呢？

（2）为啥 56 后边会换两行呢？



# inToOutV2 代码运行结果

输入内容

```shell
12\t34\b56\\78 12\t34\b56\\78 12\t34\b56\\78 12\t34\b56\\78
```

![image-20220215215516921](https://gitee.com/FightingBoom/BlogPictures/raw/master/img_20200821/20220215215516.png)

改为 **printf** 之后，发现把输入原封不动的打印出来了



将输入内容 12 与 34 之间的 \t 替换为实际的 table size 

```shell
12	34\b56\\78 12	34\b56\\78 12	34\b56\\78 12	34\b56\\78
```

![image-20220215220156063](https://gitee.com/FightingBoom/BlogPictures/raw/master/img_20200821/20220215220156.png)

发现实际的 table size 被替换为了 \t 。



# inToOutV3 代码运行结果

根据书本上的例程编写，输入内容

```shell
12	34\b56\\78 12	34\b56\\78 12	34\b56\\78 12	34\b56\\78
```

![image-20220215220951775](https://gitee.com/FightingBoom/BlogPictures/raw/master/img_20200821/20220215220951.png)