# oneLineOneWordV1

输入内容

```shell
hello world!
you are my love.
```



![image-20220215223009157](https://gitee.com/FightingBoom/BlogPictures/raw/master/img_20200821/20220215223009.png)

简要捋一下思路

1、将布尔标志位置为初始状态，代表需要开始读取字符；

2、进入 while 循环，读取字符；

3、首先读取第一个字符，并将标志位置为起始状态；

4、如果当前字符不是空格、换行符、制表符，就输出该字符；

5、如果当前字符是空格、或者换行符、或者制表符，且当前状态为起始状态，则代表该单词输入完毕，将标志位置为结束状态，并换行输出；