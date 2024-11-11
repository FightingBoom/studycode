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



### **AccessModifierOffset**(`Integer`)

> **AccessModifierOffset** (`Integer`) clang-format 3.3



访问控制修饰符（关键字）的额外缩进；比如：`public:`

> The extra indent or outdent of access modifiers, e.g. `public:`.



补充说明：

假设IndentWidth配置为4空格的默认缩进，又想要类中的关键字靠最左侧，此时配置如下：

```yaml
# 默认缩进为 4 个空格
IndentWidth: 4
# 访问控制关键字与类声明左对齐，且前面无空格；例：public/protected/private等关键字
AccessModifierOffset: -4
```





### **AlignAfterOpenBracket** (`BracketAlignmentStyle`)

> **AlignAfterOpenBracket** (`BracketAlignmentStyle`) clang-format 3.8



该配置为真时，在左括号后水平对齐参数。

> If `true`, horizontally aligns arguments after an open bracket.



适用于圆括号（圆括号），尖括号<>和方括号[]

> This applies to round brackets (parentheses), angle brackets and square brackets.



可配值：

> Possible values:



- `BAS_Align`，配置文件中为：`Align`，以左括号为基准排列参数，例如：

> `BAS_Align` (in configuration: `Align`) Align parameters on the open bracket, e.g.:

```c
someLongFunction(argument1,
                 argument2);
```



- `BAS_DontAlign`，配置文件中为：`DontAlign`，不对齐，使用 `ContinuationIndentWidth` 字段配置的缩进值，例如：

> `BAS_DontAlign` (in configuration: `DontAlign`) Don’t align, instead use `ContinuationIndentWidth`, e.g.:

```c
someLongFunction(argument1,
    argument2);
```



- `BAS_AlwaysBreak`，配置文件中为：`AlwaysBreak`，如果单行放不下所有参数，则始终在左括号之后换行，例如：

> `BAS_AlwaysBreak` (in configuration: `AlwaysBreak`) Always break after an open bracket, if the parameters don’t fit on a single line, e.g.:

```c
someLongFunction(
    argument1, argument2);
```



- `BAS_BlockIndent`，配置文件中为：`BlockIndent`，如果单行放不下所有参数，则始终在左括号之后换行，右括号将放在新行上。例如：

> `BAS_BlockIndent` (in configuration: `BlockIndent`) Always break after an open bracket, if the parameters don’t fit on a single line. Closing brackets will be placed on a new line. E.g.:

```c
someLongFunction(
    argument1, argument2
)
```



> ❗**注意**
>
> 目前仅适用于带括号的初始化列表（`Cpp11BracedListStyle`需要为真）和括号。

> Note
>
> This currently only applies to braced initializer lists (when `Cpp11BracedListStyle` is `true`) and parentheses.



### **AlignArrayOfStructures** (`ArrayInitializerAlignmentStyle`) 

> **AlignArrayOfStructures** (`ArrayInitializerAlignmentStyle`) clang-format 13



如果该选项未配置为 `None` ，当使用结构体数组初始化时，会将字段对齐到列。

> If not `None`, when using initialization for an array of structs aligns the fields into columns.



> ❗**注意**
>
> 从 clang-format 15 开始，该选项仅适用于每行列数相等的数组。

> Note
>
> As of clang-format 15 this option only applied to arrays with equal number of columns per row.



可配值：

> Possible values:



- `AIAS_Left`，配置文件中为：`Left`，左对齐数组列，例如：

> `AIAS_Left` (in configuration: `Left`) Align array column and left justify the columns e.g.:

```c
struct test demo[] =
{
    {56, 23,    "hello"},
    {-1, 93463, "world"},
    {7,  5,     "!!"   }
};
```



- `AIAS_Right`，配置文件中为：`Right`，右对齐数组列，例如：

> `AIAS_Right` (in configuration: `Right`) Align array column and right justify the columns e.g.:

```c
struct test demo[] =
{
    {56,    23, "hello"},
    {-1, 93463, "world"},
    { 7,     5,    "!!"}
};
```



- `AIAS_None`，配置文件中为：`None`，不对齐数组初始列元素。

> `AIAS_None` (in configuration: `None`) Don’t align array initializer columns.



### **AlignConsecutiveAssignments** (`AlignConsecutiveStyle`) 

> **AlignConsecutiveAssignments** (`AlignConsecutiveStyle`) clang-format 3.8



对齐连续代码块的样式

> Style of aligning consecutive assignments.

连续将导致格式化：

> `Consecutive` will result in formattings like:

```c
int a            = 1;
int somelongname = 2;
double c         = 3;
```



嵌套配置标志：

对齐选项。

为了兼容性，它们也可以作为一个整体来阅读。具体选项如下：

> Nested configuration flags:
>
> Alignment options.
>
> They can also be read as a whole for compatibility. The choices are:

- `None`
- `Consecutive`
- `AcrossEmptyLines`
- `AcrossComments`
- `AcrossEmptyLinesAndComments`



例如，要跨空行而不跨注释对齐，如下两种方法都可以

> For example, to align across empty lines and not across comments, either of these work.

```yaml
AlignConsecutiveAssignments: AcrossEmptyLines

AlignConsecutiveAssignments:
  Enabled: true
  AcrossEmptyLines: true
  AcrossComments: false
```



- `bool Enabled` ，是否启用对齐

> `bool Enabled` Whether aligning is enabled.

```c
#define SHORT_NAME       42
#define LONGER_NAME      0x007f
#define EVEN_LONGER_NAME (2)
#define foo(x)           (x * x)
#define bar(y, z)        (y + z)

int a            = 1;
int somelongname = 2;
double c         = 3;

int aaaa : 1;
int b    : 12;
int ccc  : 8;

int         aaaa = 12;
float       b = 23;
std::string ccc;
```



- `bool AcrossEmptyLines` ，是否跳过空行对齐。

> `bool AcrossEmptyLines` Whether to align across empty lines.

```c
true:
int a            = 1;
int somelongname = 2;
double c         = 3;

int d            = 3;

false:
int a            = 1;
int somelongname = 2;
double c         = 3;

int d = 3;
```



- `bool AcrossComments` ，是否跳过注释对齐。

> `bool AcrossComments` Whether to align across comments.

```c
true:
int d    = 3;
/* A comment. */
double e = 4;

false:
int d = 3;
/* A comment. */
double e = 4;
```



- `bool AlignCompound` 由 `AlignConsecutiveAssignments` 直接配置。复合赋值运算符 `+=` 是否与 `=` 对齐。

> `bool AlignCompound` Only for `AlignConsecutiveAssignments`. Whether compound assignments like `+=` are aligned along with `=`.

```c
true:
a   &= 2;
bbb  = 2;

false:
a &= 2;
bbb = 2;
```



- `bool AlignFunctionDeclarations` 由 `AlignConsecutiveDeclarations` 直接配置。函数声明是否对齐。

> `bool AlignFunctionDeclarations` Only for `AlignConsecutiveDeclarations`. Whether function declarations are aligned.

```c
true:
unsigned int f1(void);
void         f2(void);
size_t       f3(void);

false:
unsigned int f1(void);
void f2(void);
size_t f3(void);
```



- `bool AlignFunctionPointers` 由 `AlignConsecutiveDeclarations` 直接配置。函数指针是否对齐。

> `bool AlignFunctionPointers` Only for `AlignConsecutiveDeclarations`. Whether function pointers are aligned.

```c
true:
unsigned i;
int     &r;
int     *p;
int      (*f)();

false:
unsigned i;
int     &r;
int     *p;
int (*f)();

```



- `bool PadOperators` 由 `AlignConsecutiveAssignments` 直接配置。是否在短赋值运算符左侧填充空格，达到与长赋值运算符相同的长度，以便将所有赋值运算符放在长赋值运算符的右侧。
- . Whether short assignment operators are left-padded to the same length as long ones in order to put all assignment operators to the right of the left hand side.

> `bool PadOperators` Only for `AlignConsecutiveAssignments`. Whether short assignment operators are left-padded to the same length as long ones in order to put all assignment operators to the right of the left hand side.

```c
true:
a   >>= 2;
bbb   = 2;

a     = 2;
bbb >>= 2;

false:
a >>= 2;
bbb = 2;

a     = 2;
bbb >>= 2;

```



























