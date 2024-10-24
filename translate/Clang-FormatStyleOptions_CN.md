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



`.clang-format` 文件使用 YAML 格式：

> The `.clang-format` file uses YAML format:

```yaml
key1: value1
key2: value2
# A comment.
...
```



`.clang-format` 配置文件包括几部分组成，每个部分都可以有不同的 `Language:` 参数，来表示不同语言的配置内容。具体支持的语言列表可查看后续 **语言** 章节。第一部分为所有语言共用的基础默认配置，特定语言的配置项最终会覆盖共用的基础默认配置。

> The configuration file can consist of several sections each having different `Language:` parameter denoting the programming language this section of the configuration is targeted at. See the description of the **Language** option below for the list of supported languages. The first section may have no language set, it will set the default style options for all languages. Configuration sections for specific language will override options set in the default section.



多种语言组合的配置示例参考如下文件：

> An example of a configuration file for multiple languages:

```yaml
---
# 我们将使用 LLVM 作为默认格式，但调整为 4 空格缩进
# We'll use defaults from the LLVM style, but with 4 columns indentation.
BasedOnStyle: LLVM
IndentWidth: 4
---
Language: Cpp
# 下列配置指向 C++ 类型
# Force pointers to the type for C++.
DerivePointerAlignment: false
PointerAlignment: Left
---
Language: JavaScript
# JS 使用单行最大 100 字符限制
# Use 100 columns for JS.
ColumnLimit: 100
---
Language: Proto
# .proto 文件不需要格式化
# Don't format .proto files.
DisableFormat: true
---
Language: CSharp
# C# 使用单行最大 100 字符限制
# Use 100 columns for C#.
ColumnLimit: 100
...
```



参考如下命令，可以快速获取一份包含预定义样式的格式文件：

> An easy way to get a valid `.clang-format` file containing all configuration options of a certain predefined style is:

```shell
# 以 llvm 样式为基准，生成对应的 .clang-format 文件
clang-format -style=llvm -dump-config > .clang-format
```



当使用 `-style=` 选项指定配置时，相同的配置将应用于所有输入文件，配置格式如下：

> When specifying configuration in the `-style=` option, the same configuration is applied for all input files. The format of the configuration is:

```yaml
-style='{key1: value1, key2: value2, ...}'
```



## 禁用一段代码的格式设置

> ## Disabling Formatting on a Piece of Code



clang-format 可以分隔范围内切换格式的特殊注释内容。

从注释 `// clang-format off` 或 `/* clang-format off */` 开始到注释 `// clang-format on` 或 `/* clang-format on */` 之间的代码将不会被格式化。

注释本身将被正常格式化。

❗另外，也可以在上述注释后，用 （`:`） 分隔，添加其他注释文本，用来解释 clang-format 关闭或重新打开的原因。

> Clang-format understands also special comments that switch formatting in a delimited range. The code between a comment `// clang-format off` or `/* clang-format off */` up to a comment `// clang-format on` or `/* clang-format on */` will not be formatted. The comments themselves will be formatted (aligned) normally. Also, a colon (`:`) and additional text may follow `// clang-format off` or `// clang-format on` to explain why clang-format is turned off or back on.



```c++
int formatted_code;
// clang-format off
	void		unformatted_code;
// clang-format on
void formatted_code_again;
```



> 增加禁用格式，并添加注释后的代码如下，注意 off/on 后需要紧跟 `:` ，不能有空格。
>
> ```c++
> int formatted_code;
> // clang-format off:this is comment
> 	void		unformatted_code;
> // clang-format on: this is comment
> void formatted_code_again;
> ```



## 在代码中配置样式

> ## Configuring Style in Code



使用 `clang::format::reformat(...)` 函数时，用 <font color=#ff0000>`clang::format::FormatStyle`</font> 结构指定格式。

> When using `clang::format::reformat(...)` functions, the format is specified by supplying the [clang::format::FormatStyle](https://clang.llvm.org/doxygen/structclang_1_1format_1_1FormatStyle.html) structure.



## 可配置样式选项

> ## Configurable Format Style Options

本章列出了支持的样式选项。每个选项都有规定的值类型。对于枚举类型，可能的值即指定为 C++ 枚举成员（带前缀，例如 LS_Auto ），也可作为配置中可用的值（没有前缀：Auto）。

>This section lists the supported style options. Value type is specified for each option. For enumeration types possible values are specified both as a C++ enumeration member (with a prefix, e.g. `LS_Auto`), and as a value usable in the configuration (without a prefix: `Auto`).



### BasedOnStyle (String)

该选项用于配置中未明确设置的所有选项的样式。

> The style used for all options not specifically set in the configuration.

该选项仅支持在 **clang-format** 配置中（在`-style='{...}'` 和 `.clang-format` 格式文件）

> This option is supported only in the **clang-format** configuration (both within `-style='{...}'` and the `.clang-format` file).

可选值：

> Possible values:

- `LLVM` ，符合 [LLVM 编码标准](https://llvm.org/docs/CodingStandards.html) ；

> - `LLVM` A style complying with the [LLVM coding standards](https://llvm.org/docs/CodingStandards.html)

- `Google` ，符合 [Google C++ 风格指南](https://google.github.io/styleguide/cppguide.html) ；

> - `Google` A style complying with [Google’s C++ style guide](https://google.github.io/styleguide/cppguide.html)

- `Chromium` ，符合 [Chromium 风格指南](https://chromium.googlesource.com/chromium/src/+/refs/heads/main/styleguide/styleguide.md) ；

> - `Chromium` A style complying with [Chromium’s style guide](https://chromium.googlesource.com/chromium/src/+/refs/heads/main/styleguide/styleguide.md)

- `Mozilla` ，符合 [Mozilla 风格指南](https://firefox-source-docs.mozilla.org/code-quality/coding-style/index.html) ；

> - `Mozilla` A style complying with [Mozilla’s style guide](https://firefox-source-docs.mozilla.org/code-quality/coding-style/index.html)

- `WebKit` ，符合 [WebKit 风格指南](https://www.webkit.org/coding/coding-style.html) ；

> - `WebKit` A style complying with [WebKit’s style guide](https://www.webkit.org/coding/coding-style.html)

- `Microsoft` ，符合 [Microsoft 风格指南](https://docs.microsoft.com/en-us/visualstudio/ide/editorconfig-code-style-settings-reference) ；

> - `Microsoft` A style complying with [Microsoft’s style guide](https://docs.microsoft.com/en-us/visualstudio/ide/editorconfig-code-style-settings-reference)

- `GNU` ，符合 [GNU 编码标准](https://www.gnu.org/prep/standards/standards.html) ；

> - `GNU` A style complying with the [GNU coding standards](https://www.gnu.org/prep/standards/standards.html)

- `InheritParentConfig` ，并不是一个有效的样式，但允许使用父目录的 `.clang-format` 文件。如果父目录找不到，将回退到 `fallback` 样式，并应用更改。

    使用该选项，可以覆盖子目录的主样式的某些部分配置。也可以通过命令行实现，例如 `--style={BasedOnStyle: InheritParentConfig, ColumnLimit: 20}`

> `InheritParentConfig` Not a real style, but allows to use the `.clang-format` file from the parent directory (or its parent if there is none). If there is no parent file found it falls back to the `fallback` style, and applies the changes to that.
>
> With this option you can overwrite some parts of your main style for your subdirectories. This is also possible through the command line, e.g.: `--style={BasedOnStyle: InheritParentConfig, ColumnLimit: 20}`

























