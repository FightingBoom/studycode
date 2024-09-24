# 项目背景

.clang-format 官方英文文档，中文版（尝试）翻译，自己学习 .clang-format 的使用，顺便锻炼下英语水平。

官网地址：[https://clang.llvm.org/docs/ClangFormatStyleOptions.html](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)



# Clang-Format 样式设置

> # Clang-Format Style Options



[<font color=#ff0000>**Clang-Format 格式设置**</font>](https://clang.llvm.org/docs/ClangFormatStyleOptions.html) 网站详细展示了 <font color=#ff0000>**LibFormat**</font> 与 <font color=#ff0000>**ClangFormat**</font> 工具支持的可配置样式选项。

> [Clang-Format Style Options](https://clang.llvm.org/docs/ClangFormatStyleOptions.html#) describes configurable formatting style options supported by [LibFormat](https://clang.llvm.org/docs/LibFormat.html) and [ClangFormat](https://clang.llvm.org/docs/ClangFormat.html).



当我们在命令行使用 **clang-format** 程序或 `clang::format::reformat(...) 函数时，可以使用比如（LLVM，Google，Chromium，Mozilla，WebKit，Microsoft）这些预定义的样式之一，或者使用支持的配置字段创建自定义样式。

> When using **clang-format** command line utility or `clang::format::reformat(...)` functions from code, one can either use one of the predefined styles (LLVM, Google, Chromium, Mozilla, WebKit, Microsoft) or create a custom style by configuring specific style options.



## 使用 clang-format 配置样式

> ## Configuring Style with clang-format



clang-format 提供两种方式实现自定义样式选项：直接在命令行中使用 `-style=` 选项指定样式配置；或者使用 `-style=file` 选项指定在工程目录 `.clang-format` 或 `_clang-format` 文件中的样式配置。

> **clang-format** supports two ways to provide custom style options: directly specify style configuration in the `-style=` command line option or use `-style=file` and put style configuration in the `.clang-format` or `_clang-format` file in the project directory.



当使用 `-style=file` 选项时，**clang-format** 将尝试从输入文件最近的父目录开始查找 `.clang-format` 配置文件。如果使用了标准输入，将从当前目录开始搜索。

> When using `-style=file`, **clang-format** for each input file will try to find the `.clang-format` file located in the closest parent directory of the input file. When the standard input is used, the search is started from the current directory.



当使用 `-style=file:<format_file_path>` 选项时，**clang-format** 将从 <format_file_path> 指定的路径开始查找。format_file_path 中既可以是绝对路径，也可以是基于工作目录的相对路径。

> When using `-style=file:<format_file_path>`, **clang-format** for each input file will use the format file located at <format_file_path>. The path may be absolute or relative to the working directory.

















