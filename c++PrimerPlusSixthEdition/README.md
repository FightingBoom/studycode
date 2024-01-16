# 1 环境说明



## 1.1 开发环境组合1

1、使用 Windows 10 专业版

2、Visual Studio Code；

 - Code Runner 插件

3、G++ 版本

```shell
PS E:\91-GitRepository\studycode\c++PrimerPlusSixthEdition\chapter_06\code_6.02> g++ --version
g++.exe (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0
Copyright (C) 2018 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```


## 1.2 开发环境组合2

1、使用在线编译网站：https://ideone.com/sn24jt#/stdin

2、C语言编译器版本如下

```shell
language:C (gcc 8.3)
```

## 1.3 开发环境组合3
1、macOS 系统，可以使用自带的 clang 编译器



# 2 参考资料

1、编程练习参考资料

（1）[https://blog.csdn.net/leowinbow/article/details/86484484](https://blog.csdn.net/leowinbow/article/details/86484484)

# 3 操作命令

方案一：多文件编译命令，后续再思考如何使用 CMake / Makefile 管理，暂时采用这种方法

```shell
# 使用g++编译多个源文件
g++ .\twofile1.cpp .\twofile2.cpp

# 执行
.\a.exe
```



方案二：修改 VSCode **Code Runner** 插件，默认编译所有的 .cpp 文件

```json
        "c": "cd $dir && gcc *.c -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
        "cpp": "cd $dir && g++ *.cpp -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
```

