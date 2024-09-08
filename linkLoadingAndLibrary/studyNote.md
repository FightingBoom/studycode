# 第1部分 简介

## 第1章 温故而知新

### 1.1 从 Hello World 说起

从 Hello World 思考一些问题：

  ? 程序为什么要被编译器编译了之后才可以运行？

  ? 编译器在把C语言程序转换成可以执行的机器码的过程中做了什么，怎么做的？

  ? 最后编译出来的可执行文件里面是什么？除了机器码还有什么？它们怎么存放的，怎么组织的？

  ? #include <stdio.h>是什么意思？把stdio.h包含进来意味着什么？C语言库又是什么？它怎么实现的？

  ? 不同的编译器（Microsoft VC、GCC）和不同的硬件平台（x86、SPARC、MIPS、ARM），以及不同的操作系统（Windows、Linux、UNIX、Solaris），最终编译出来的结果一样吗？为什么？

  ? Hello World程序是怎么运行起来的？操作系统是怎么装载它的？它从哪儿开始执行，到哪儿结束？main函数之前发生了什么？main函数结束以后又发生了什么？

  ? 如果没有操作系统，Hello World可以运行吗？如果要在一台没有操作系统的机器上运行Hello World需要什么？应该怎么实现？

  ? printf是怎么实现的？它为什么可以有不定数量的参数？为什么它能够在终端上输出字符串？

  ? Hello World程序在运行时，它在内存中是什么样子的？



### 1.2 万变不离其宗

最为关键的三个部件：中央处理器 CPU 、内存和 I/O 控制芯片；



北桥（Northbridge，PCI Bridge）

南桥（Southbridge）



多核处理器（Multi-core Processor）

> “多处理器应用最多的场合也是这些商用的服务器和需要处理大量计算的环境。而在个人电脑中，使用多处理器则是比较奢侈的行为，毕竟多处理器的成本是很高的。于是处理器的厂商开始考虑将多个处理器“合并在一起打包出售”，这些“被打包”的处理器之间共享比较昂贵的缓存部件，只保留多个核心，并且以一个处理器的外包装进行出售，售价比单核心的处理器只贵了一点，这就是多核处理器（Multi-core Processor）的基本想法。”
>
> 摘录来自
> 程序员的自我修养：链接、装载与库
> 俞甲子 石凡 潘爱民
> 此材料可能受版权保护。



[Free Lunch is Over（免费午餐已经结束了）](http://www.gotw.ca/publications/concurrency-ddj.htm)



### 1.3 站得高，望得远

“Any problem in computer science can be solved by another layer of indirection.”

“计算机科学领域的任何问题都可以通过增加一个间接的中间层来解决”














