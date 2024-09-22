# 项目背景

.clang-format 官方英文文档，中文版（尝试）翻译，自己学习 .clang-format 的使用，顺便锻炼下英语水平。

官网地址：[https://clang.llvm.org/docs/ClangFormatStyleOptions.html](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)



# Clang-Format 样式设置

[<font color=#ff0000>**Clang-Format 格式设置**</font>](https://clang.llvm.org/docs/ClangFormatStyleOptions.html) 网站详细展示了 <font color=#ff0000>**LibFormat**</font> 与 <font color=#ff0000>**ClangFormat**</font> 工具支持的可配置样式选项。



当我们在命令行使用 **clang-format** 程序或 `clang::format::reformat(...) 函数时，可以使用比如（LLVM，Google，Chromium，Mozilla，WebKit，Microsoft）这些预定义的样式之一，或者使用支持的配置字段创建自定义样式。



## 使用 clang-format 配置样式

clang-format 提供两种方式实现自定义样式选项：直接在命令行中使用 `-style=` 选项指定样式配置；或者使用 `-style=file` 选项指定在工程目录 `.clang-format` 或 `_clang-format` 文件中的样式配置。



当使用 `-style=file` 选项时，**clang-format** 将尝试从输入文件最近的父目录开始查找 `.clang-format` 配置文件。如果使用了标准输入，将从当前目录开始搜索。



当使用 `-style=file:<format_file_path>` 选项时，**clang-format** 将从 <format_file_path> 指定的路径开始查找。format_file_path 中既可以是绝对路径，也可以是基于工作目录的相对路径。



















