# DrawLengthHistogramV1

输入内容

```shell
one two three four one two three four one two three four one two three four one two three four one two three four one two three 
```

PS：最后一个空格 / 换行符 / 缩进符，会影响单词个数的判断；

![image-20220304164549800](https://gitee.com/FightingBoom/BlogPictures/raw/master/img_20200821/20220304164556.png)



简要捋一下思路

1、根据约定规则分割单词，判断该单词长度是否在 MAXWORD 范围内；

2、分别计数不同长度的单词个数；

3、找出单词个数最多的长度，用作直方图绘制；

4、利用 **单词长度 - 同一长度单词个数** 的规则，在后边绘制星号；

5、最后判断是否有 MAXWORD 范围外的单词，有的话，打印出来个数；