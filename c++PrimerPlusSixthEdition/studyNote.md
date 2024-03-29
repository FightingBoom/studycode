# 未归类

1、signed 、unsigned 单独使用时，默认为 int 类型；

```c++
signed = signed int
unsigned = unsigned int
```



## 名词缩写

多重继承（multiple inheritance，MI）



### 10.3.5 构造函数

如果可以通过初始化，也可以通过赋值来设置对象的值，则应采用初始化的方式，通常这种方式的效率更高；

可以将列表初始化语法，用于类；只需要提供与某个构造函数的参数列表匹配的内容，并用大括号将他们括起；【C++11及以上支持】

可以通过将函数参数声明为 const 引用或指向 const 的指针，保证函数不会修改调用对象

```c++
// 函数声明
void show() const;
// 函数定义
void stock::show() const;
```

以这种方式声明和定义的类函数被称为 const 成员函数。应尽可能将 const 引用和指针用作函数形参，只要类方法不修改调用对象，就应将其声明为 const 。



### 10.3.6 构造函数和析构函数小结

如果构造函数使用了 new ，则必须提供使用 delete 的析构函数；



## 10.4 this 指针

一般来说，所有的类方法都将 this 指针设置为调用它的对象的地址。

*this，将解除引用运算符 * 用于指针，将得到指针指向的值。



## 10.8 总结

由于 this 指针被设置为调用对象的地址，因此 *this 是该对象的别名；



# 11 使用类

## 11.2 计算时间：一个运算符重载示例

将参数声明为引用的目的是为了提高效率。

个人理解：如果不需要修改值，请加上 const 限定符；

不要返回指向局部变量或临时对象的引用。函数执行完毕后，局部变量和临时对象将消失，引用将指向不存在的数据。



### 11.2.1 添加加法运算符

编译器将根据操作数的类型来确定做

```c++
int a, b, c;
Time A, B, C;
c = a + b;
C = A + B;
```

同时可以将两个以上的对象相加

```c++
t4 = t1 + t2 + t3;

t4 = t1.operator+(t2 + t3);

t4 = t1.operator+(t2.operator + (t3));
```



### 11.2.2 重载限制

C++ 对用户定义的运算符重载的限制，2023/03/26 17:22

1、重载后的运算符必须至少有一个操作数是用户定义的类型，这将防止用户为标准类型重载运算符；

2、使用运算符时， 不能违反运算符原来的句法规则。同样，不能修改运算符的优先级。

3、不能创建新运算符。

4、不能重载下面的运算符

- **sizeof** ：sizeof 运算符。
- **.** ：成员运算符。
- **. \*** ：成员指针运算符。
- **::** ：作用域解析运算符。
- **?;** ：条件运算符。
- **typeid** ：一个 RTTI 运算符。
- **const_cast** ：强制类型转换运算符。
- **dynamic_cast** ：强制类型转换运算符。
- **reinterpret_cast** ：强制类型转换运算符。
- **static_cast** ：强制类型转换运算符。

5、如下运算符只能通过成员函数进行重载

- **=** ：复制运算符。
- **()** ：函数调用运算符。
- **[]** ：下标运算符。
- **->** ：通过指针访问类成员的运算符。



## 11.3 友元

类的友元函数是非成员函数，其访问权限与成员函数相同。

应将友元函数看作类的扩展接口的组成部分。

只有类声明可以决定哪一个函数是友元，因此类声明仍然控制了哪些函数可以访问私有数据。

总之，类方法和友元只是表达类接口的两种不同机制。



### 11.3.1 创建友元

如果要为类重载运算符，并将非类的项作为其第一个操作数，则可以用友元函数来反转操作数的顺序。



### 11.3.2 常用的友元：重载<<运算符

<< 运算符是 C 和 C++ 的位运算符，将值中的位左移。2023/03/27 22:57

cout 是一个 ostream 对象，可以识别所有的 C++ 基本类型。因为对于每种基本类型，ostream 类声明中都包含了相应的重载的 operator<<() 定义。

按引用传递使用的内存和时间都比按值传递少。

```c++
int x = 5;
int y = 8;

cout << x << y;
// 上下两条语句等价
(cout << x) << y;
```

<< 运算符左边是一个 ostream 对象。

ostream 类将 operator <<() 函数实现为返回一个指向 ostream 对象的引用。具体地说，他返回一个指向调用对象（这里是 cout ）的引用。因此，表达式 (cout << x) 本身就是 ostream 对象 cout，从而可以位于 << 运算符的左侧。



## 11.4 重载运算符：作为成员函数还是非成员函数

非成员版本的重载运算符函数所需的形参数目，与运算符使用的操作数数目相同；而成员版本所需的参数数目少一个，因为其中的一个操作数是被隐式地传递给调用对象。

```c++
T1 = T2 + T3 // 编译器转换
T1 = T2.operator+(T3);
T1 = operator+(T2, T3);
```



## 11.5 再谈重载：一个矢量类

函数尾部的 const 限定符，用于声明那些不会对其显式访问的对象进行修改的函数。



### 11.5.2 为Vector类重载算术运算符

如果方法通过计算得到一个新的类对象，则应考虑是否可以使用类构造函数来完成这种工作。这样做不仅可以避免麻烦，而且可以确保新的对象是按照正确的方式创建的。

因为运算符重载是通过函数来实现的，所以只要运算符函数的特征标不同，使用的运算符数量与相应的内置 C++ 运算符相同，就可以多次重载同一个运算符。



## 11.6 类的自动转换和强制类型转换

类可使用等号的方式，调用构造函数。有两种情况（2023/04/02 18:43）

- 只有一个（整形）参数
- 有多个参数，除第一个外，后面的参数都有默认值。

使用关键字 explicit 可以关闭自动隐式转换的特性，但允许使用 类名(值) 的方式显式转换。

只接受一个参数的构造函数定义了从参数类型到类类型的转换。如果使用关键字 explicit 限定了这种构造函数，则它只能用于显式转换，否则也可以用于隐式转换。



### 11.6.1 转换函数

构造函数只能实现其他类型到类类型的转换，要想实现从其他类型（比如 double ）到类类型的转换，则需要对应的 **转换函数** ，注意：

- 转换函数必须是类方法；
- 转换函数不能指定返回类型；
- 转换函数不能有参数；

标准格式

```c++
// typeName: 对象将被转换成的类型。
// 将类对象赋值给typeName变量或将其强制转换为typeName类型时，该转换函数将自动被调用。
operator typeName()
```

应谨慎地使用隐式转换函数。通常，最好选择仅在被显式地调用时才会执行的函数。



## 11.7 总结

一般访问私有类成员的唯一方法是使用类方法。C++ 可以使用友元函数避开这种限制，需在声明前加上关键字 friend 。

C++ 扩展了对运算符的重载，允许自定义特殊的运算符函数。

C++ 允许指定在类和基本类型之间进行转换的方式。

1. 任何接受唯一一个参数的构造函数都可被用作转换函数，将类型与该参数相同的值转换为类。
2. 如果将类型与该参数相同的值赋给对象，则C++将自动调用该构造函数。
3. 如果在该构造函数的声明前加上了关键字 explicit ，则该构造函数将只能用于显式转换
4. 要将类对象转换为其他类型，必须定义转换函数，指出如何进行这种转换。转换函数必须是成员函数。
5. 经验表明：最好不要依赖于隐式转换函数。
6. 自己总结：如果一定需要转换，可以自定义接口进行转换操作；
7. 与简单的C-风格结构相比，使用类时，必须更谨慎、更小心；



# 12 类和动态内存分配

## 12.1 动态内存和类

### 12.1.1 复习示例和静态类成员

将 num_strings 成员声明为静态存储类。静态存储类的特点：无论创建了多少对象，程序都只创建一个静态类变量副本。也就是说，类的所有对象共享同一个静态成员，就像家中的电话可供全体家庭成员共享一样。

这对于所有类对象都具有相同值的类私有数据是非常方便。例如，num_strings 成员可以记录所创建的对象数目。

不能在类声明中初始化静态成员变量，因为声明描述了如何分配内存，但并不分配内存。

但静态类成员，可以在类声明之外，使用单独的语句来进行初始化，因为静态类成员是单独存储的，而不是对象的组成部分。

注意：初始化语句指出了类型，并使用了作用域运算符，但没有使用关键字 static 。

```c++
static int num_strings; // 方便说明静态数据成员，实际字符串类并不需要

int StringBad::num_strings = 0; // 静态成员初始化
```

初始化是在方法文件中，而不是在类声明文件中进行的，因为类声明位于头文件中，程序可能将头文件包括在其他几个文件中。如果在头文件中进行初始化，将出现多个初始化语句副本，从而引发错误。

在构造函数中使用 new 来分配内存时，必须在相应的析构函数中使用 delete 来释放内存。如果使用 new[] （包括中括号）来分配内存，则应使用 delete[]（包括中括号）来释放内存。

```c++
StringBad sailor = sports; // <=> 等价与如下代码

StringBad sailor = StringBad(sports); // 此时调用的原型为
```



### 12.1.3 回到 Stringbad：复制构造函数的哪里出了问题

如果类中包含了使用 new 初始化的指针成员，应当定义一个复制构造函数，以复制指向的数据，而不是指针，这被称为深度复制。

复制的另一种形式（成员复制或浅复制）只是复制指针值。浅复制仅浅浅地复制指针信息，而不会深入“挖掘”以复制指针引用的结构。



### 12.2.4 静态成员函数

可以将成员函数声明为静态的，但有两个重要后果

1. 不能通过对象调用静态成员函数；实际上，静态成员函数甚至不能使用 this 之神。
2. 由于静态成员函数不与特定的对象相关联，因此只能使用静态数据成员。例如，静态方法 HowMany() 可以访问静态成员num_string。



## 12.3 在构造函数中使用 new 时应注意的事项

使用 new 初始化对象的指针成员，需注意如下几点（2023/04/16 16:38）

1. 如果在构造函数中使用 new 来初始化指针成员，则应在析构函数中使用 delete 。
2. new 和 delete 必须相互兼容。new 对应于 delete ，new[] 对应于 delete[] 。
3. 如果有多个构造函数，则必须以相同的方式使用 new ，要么都带中括号，要么都不带。
4. 应定义一个复制构造函数，通过深度复制将一个对象初始化为另一个对象。
5. 应当定义一个赋值运算符，通过深度复制将一个对象复制给另一个对象。



## 12.4 有关返回对象的说明

成员函数或独立的函数返回对象时，有几种选择：

1. 返回指向对象的引用
2. 指向对象的 const 引用或 const 对象

直接返回对象，会调用复制构造函数，但是返回引用不会。因此返回引用所做的工作更少，效率更高。

引用指向的对象应该在调用函数执行时存在。

如果方法活函数要返回局部对象，则应返回对象，而不是指向对象的引用。



## 12.5 使用指向对象的指针

如果对象是用 new 创建的，则仅当您显式使用 delete 删除对象时，其析构函数才会被调用。



## 12.7 队列模拟

1、使用成员初始化列表，注意：

- 这种格式只能用于构造函数
- 非静态 const 类成员
- 声明为引用的类成员

2、对于本身就是类对象的成员来说，使用成员初始化列表的效率更高。

3、成员初始化列表的初始化工作是在对象创建时完成的，此时还未执行构造函数括号中的任何代码。

链表在使用时，先用临时变量获取当前值，然后 front 指向自己的下一个地址，最后再删除临时变量的引用值，即删除了最开始的元素；

```c++
temp = front;
front = front->next;
delete temp;
```



## 12.8 总结

C++ 允许类内初始化。



## 13.3 多态公有继承

1、希望同一个方法在派生类和基类中的行为是不同的。方法的行为应取决于调用该方法的对象。这种复杂的行为称为多态 —— 具有多种形态。

2、有两种重要的机制可用于实现多态公有继承：

- 在派生类中重新定义基类的方法；
- 使用虚方法（虚函数）；



如果方法是通过引用或指针而不是对象调用的，它将确定使用哪一种方法。

如果没有使用关键字 virtual ，程序将根据引用类型或指针类型选择方法；

如果使用了 virtual ，程序将根据引用或指针指向的对象的类型来选择方法；

```c++
// ViewAcct 不是虚函数
Brass dom("Dominic Banker", 11224, 4183.45);
BrassPlus dot("Dorothy Banker", 12118, 2592.00);
Brass & b1_ref = dom;
Brass & b2_ref = dot;
b1_ref.ViewAcct();    // use Brass::ViewAcct()
b2_ref.ViewAcct();    // use Brass::ViewAcct()
```



```c++
// ViewAcct 是虚函数
Brass dom("Dominic Banker", 11224, 4183.45);
BrassPlus dot("Dorothy Banker", 12118, 2592.00);
Brass & b1_ref = dom;
Brass & b2_ref = dot;
b1_ref.ViewAcct();    // use Brass::ViewAcct()
b2_ref.ViewAcct();    // use BrassPlus::ViewAcct()
```

方法在基类中被声明为虚的后，它在派生类中将自动成为虚方法。然而，在派生类中使用 virtual 指出哪些是虚函数也挺好。

如果要在派生类中重新定义基类的方法，通常应将基类方法声明为虚的。这样，程序将根据对象类型而不是引用或指针的类型来选择方法版本。为基类声明一个虚析构函数也是一种惯例。

关键字 virtual 只用于类声明的方法原型中，没有用于方法定义中。

在派生类方法中，标准技术是使用作用域解析运算符来调用基类方法。



## 13.4 静态联编和动态联编

### 13.4.1 指针和引用类型的兼容性

对于使用基类引用或指针作为参数的函数调用，将进行向上转换。如下代码，假定每个函数都调用虚方法 ViewAcct() ；

```c++
// 引用、指针，可以隐式向上转换
void fr(Brass & rb);   // uses rb.ViewAcct()
void fp(Brass * pb);   // uses pb->ViewAcct()
void fv(Brass b);      // uses b.ViewAcct()

int main()
{
    Brass b("Billy Bee", 123432, 10000.0);
    BrassPlus bp("Betty Beep", 232313, 12345.0);

    fr(b);    // uses Brass::ViewAcct()
    fr(bp);   // uses BrassPlus::ViewAcct()
    fp(b);    // uses Brass::ViewAcct()
    fp(bp);   // uses BrassPlus::ViewAcct()
    fv(b);    // uses Brass::ViewAcct()
    fv(bp);   // uses Brass::ViewAcct()
}
```



### 13.4.2 虚成员函数和动态联编

编译器对非虚方法，使用静态联编。

编译器对虚方法，使用动态联编。因为通常只有在运行程序时才能确定对象的类型。

C++的指导原则之一：不要为不使用的特性付出代价（内存或者处理时间）

使用虚函数时，在内存和执行速度方面有一定的成本，包括：

- 每个对象都将增大，增大量为存储地址的空间；
- 对于每个类，编译器都创建一个虚函数地址表（数组）；
- 对于每个函数调用，都需要执行一项额外的操作，即到表中查找地址。

虽然非虚函数的效率比虚函数稍高，但不具备动态联编功能。



### 13.4.3 有关虚函数注意事项

构造函数不能是虚函数。

析构函数应当是虚函数，除非类不用做基类。

派生类中存在 new 等内存，需要在派生类销毁时，回收对应内存，因此析构函数应当是虚函数，这样派生类可以有自己的实现。

当 delete 派生类的内存时，会先调用派生类的析构函数，再调用基类的析构函数。

通常应该给类定义一个虚析构函数，即使他并不需要析构函数。

友元不能是虚函数，因为友元不是类成员，只有成员才能是虚函数。如果有设计问题，可以让友元函数使用虚成员函数来解决。



5. 重新定义将隐藏方法

基类有一个虚函数，派生类重新实现，但参数不同，此时会隐藏基类的同名函数

```c++
class Dwelling
{
public:
    virtual void showperks(int a) const;
...
};


class Hovel : public Dwelling
{
public:
    virtual void showperks() const;
...
}
```

重新定义不会生成函数的两个重载版本，而是隐藏了接受一个 int 参数的基类版本。

总之，重新定义继承的方法并不是重载。如果重新定义派生类中的函数，将不只是使用相同的函数参数列表覆盖基类声明，无论参数列表是否相同，该操作将隐藏所有的同名基类方法。



此引出来两条规则

第一，如果重新定义继承的方法，应确保与原来的原型完全相同，但如果返回类型是基类引用或指针，则可以修改为指向派生类的引用或指针。这种特性被称为返回类型协变，因为允许返回类型随类类型的变化而变化。

需要注意，这种例外只适用于返回值，而不适用于参数。

```c++
class Dwelling
{
public:
    virtual Dwelling & build(int n);
...
};


class Hovel : public Dwelling
{
public:
    virtual Hovel & build(int n); // 同名虚函数，只是返回值类型不同
...
}
```

第二，如果基类声明被重载了，则应在派生类中重新定义所有的基类版本。

```c++
class Dwelling
{
public:
    virtual void showperks(int a) const;
    virtual void showperks(double x) const;
    virtual void showperks() const;
...
};


class Hovel : public Dwelling
{
public:
    virtual void showperks(int a) const;
    virtual void showperks(double x) const;
    virtual void showperks() const;
...
}
```

如果只重新定义一个版本，则另外两个版本将被隐藏，派生类对象将无法使用它们。如果不需要修改，新定义可以只调用基类版本。

```c++
void Hovel::showperks() const {Dwelling::showperks();}
```





## 13.5 访问控制：protected

protected 与 private ，在 类外 只能用公有类成员来访问。

派生类的成员，可以直接访问基类的保护成员，但不能直接访问基类的私有成员。

| 基类关键字类型 | 派生类访问权限 | 外部类访问权限 |
| :------------: | :------------: | :------------: |
|    private     |    无法访问    |    无法访问    |
|    protect     |    可以访问    |    无法访问    |
|     public     |    可以访问    |    可以访问    |
|                |                |                |

注意：最好对类数据成员采用私有访问控制，不要使用保护访问控制；同时通过基类方法使派生类能够访问基类数据；

另外对于成员函数来说，保护访问控制很有用，它让派生类能够访问公众不能使用的内部函数。



## 13.6 抽象基类

ABC：abstract base class

真正的 ABC ，必须至少包含一个纯虚函数。

当类声明中包含纯虚函数时，则不能创建该类的对象。

理念：包含纯虚函数的类只用作基类。



## 13.7 继承和动态内存分配

### 13.7.1 第一种情况：派生类不使用 new

可以不需要为派生类定义显式析构函数、复制构造函数和赋值运算符。



### 13.7.2 第二种情况：派生类使用 new

如果派生类有使用 new ，则必须为派生类定义显式析构函数、复制构造函数和赋值运算符。

派生类析构函数自动调用基类的析构函数，故其自身的职责是对派生类构造函数执行工作的进行清理。因此，hasDMA （派生类）的析构函数必须释放指针 style 管理的内存，并依赖于 baseDMA （基类）的析构函数来释放指针 label 管理的内存。

hasDMA （派生类）复制构造函数只能访问 hasDMA 的数据，因此必须调用 baseDMA 复制构造函数来处理共享的 baseDMA 数据。

当基类和派生类都采用动态内存分配时，派生类的析构函数、复制构造函数、赋值运算符都必须使用相应的积累方法来处理基类元素。

这种要求是通过三种不同的方式来满足的。

对于析构函数，这是自动完成的；

对于构造函数，这是通过在初始化成员类表中调用基类的复制构造函数来完成的；如果不这样做，将自动调用基类的默认构造函数。

对于复制运算符，这是通过使用作用域解析运算符显式地调用基类的复制运算符来完成的。



## 13.8 类设计回顾

### 13.8.1 编译器生成的成员函数

如果定义了某种构造函数，则编译器将不会定义默认构造函数。如果有需要，则必须自己提供。

提供构造函数的动机之一是确保对象总能被正确地初始化。如果类包含指针成员，则必须初始化这些成员。因此，最好提供一个显式默认构造函数，将所有的类数据成员都初始化为合理的值。



复制构造函数接受其所属类的对象作为参数。

Star(const Star &);

在下述情况下，将使用复制构造函数：

- 将新对象初始化为一个同类对象；
- 按值将对象传递给函数；
- 函数按值返回对象；
- 编译器生成临时对象；



默认的赋值运算符用于处理同类对象之间的赋值。

PS：不要将赋值与初始化混淆了。如果语句创建新的对象，则使用初始化；如果语句修改已有对象的值，则是赋值；

默认赋值为成员赋值。



### 13.8.2 其他的类方法

1. 构造函数

构造函数不同于其他类方法，因为它创建新的对象，而其他类方法只是被现有的对象调用。这是构造函数不被继承的原因之一。

继承意味着派生类对象可以使用基类的方法，但构造函数在完成其工作之前，对象并不存在。



2. 析构函数

一定要定义显式析构函数来释放类构造函数使用 new 分配的所有内存，并完成类对象所需的任何特殊的清理工作。

对于基类，即使它不需要析构函数，也应提供一个虚析构函数。



3. 转换

在带一个参数的构造函数原型中使用 explicit 将禁止进行隐式转换，但仍允许显式转换：

```c++
class star
{
...
public:
    explicit Star(const char *);
...
};

...

Star north;
north = "polaris";        // not allowed
north = Star("polaris");  // allowed
```



另外，对于某些类，包含转换函数将增加代码的二义性。

C++11 支持将关键字 explicit 用于转换函数。与构造函数一样，explicit 允许使用强制类型转换进行显式转换，但不允许隐式转换。



4. 按值传递对象与传递引用

通常，编写使用对象作为参数的函数时，应按引用而不是按值来传递对象。

原因之一是为了提高效率。按值传递对象涉及到生成临时拷贝，即调用复制构造函数，然后调用析构函数。调用这些函数需要时间，复制大型对象比传递引用花费的时间要多得多。如果函数不修改对象，应将参数声明为 const 引用。

按引用传递对象的另外一个原因是，在继承使用虚函数时，被定义为接受基类引用参数的函数可以接受派生类。



5. 返回对象和返回引用

有些类方法返回对象。有些成员函数直接返回对象，另一些返回引用。有时方法必须返回对象，但如果可以不返回对象，则应返回引用。

```c++
// 返回对象
Star nova1(const Star &);

// 返回引用
Star & nova2(const Star &);
```

返回对象涉及生成调用函数的程序，可以使用的临时副本。因此，返回对象的时间成本包括调用复制构造函数来生成副本所需的时间和调用析构函数删除副本所需的时间。

返回引用可以节省时间和内存。

直接返回对象与按值传递对象相似：都生成临时副本。

返回引用与按引用传递对象相似：调用和被调用的函数对同一个对象进行操作。



函数不能返回在函数中创建的临时对象的引用，因为当函数结束时，临时对象将消失，因此这种引用将是非法的。在这种情况下，应返回对象，以生成一个调用程序可以使用的副本。



6. 使用 const

使用 const 可以确保方法不修改参数；可以确保方法不修改调用它的对象；

可以使用 const 来确保引用或指针返回的值不能用于修改对象中的数据：
```c++
const Stock & Stock::topval(const Stock & s) const
{
	if (s.total_val > total_val)
        return s;
    else
        return *this;
}
```

该方法返回对 this 或 s 的引用，且因为 this 与 s 都被声明为 const ，所以函数不能对它们进行修改，同时意味着返回的引用也必须被声明为 const 。

如果函数将参数声明为指向 const 的引用或指针，则不能将该参数传递给另一个函数，除非后者也确保了参数不会被修改。



### 13.8.3 公有继承的考虑因素

1. is-a 关系

要遵循 is-a 关系。如果派生类不是一种特殊的基类，则不要使用公有派生。

在某些情况下，最好的方法可能是创建包含纯虚函数的抽象数据类，并从它派生出其他的类。

表示 is-a 关系的方式之一：

- 无需进行显式类型转换，基类指针就可以指向派生类对象，基类引用可以引用派生类对象。
- 反过来行不通，即不能在不进行显式类型转换的情况下，将派生类指针或引用指向基类对象。不安全。



2. 什么不能被继承

构造函数是不能继承的。

析构函数也是不能继承的。在释放对象时，程序将首先调用派生类的析构函数，然后调用基类的析构函数。通常对于基类，析构函数应该设置为虚函数。

赋值运算符是不能继承的。派生类继承的方法的特征标与基类完全相同，但赋值运算符的特征标随类而异，因为它包含一个类型为其所属类的形参。



3. 赋值运算符

如果编译器发现程序将一个对象赋给同一个类的另一个对象，它将自动为这个类提供一个赋值运算符。



4. 私有成员与保护成员

对派生类而言，保护成员类似于公有成员；但对于外部而言，保护成员与私有成员类似。

讲基类成员设置为私有的可以提高安全性，而将它们设置为保护成员则可简化代码的编写工作，并提高访问速度。

Stroustrup：使用私有数据成员比使用保护数据成员更好，但保护方法很有用。



5. 虚方法

设计基类时，必须确定是否将类方法声明为虚的。

如果希望派生类能够重新定义方法，则应在基类中将方法定义为虚的，这样可以启用晚期联编（动态联编）；

如果不希望重新定义方法，则不必将其声明为虚的；



6. 析构函数

基类的析构函数应当是虚的。

这样，当通过指向对象的基类指针或引用来删除派生类对象时，程序将首先调用派生类的析构函数，然后调用基类的析构函数，而不仅仅是调用基类的析构函数。



7. 友元函数

由于友元函数并非类成员，因此不能继承。

然而，可以通过强制类型转换，将派生类引用或指针转换为基类引用或指针，然后使用转换后的指针或引用来调用基类的友元函数。



8. 有关使用基类方法的说明

以公有方式派生的类的对象可以通过多种方式来使用基类的方法。

- 派生类对象自动使用继承而来的基类方法，如果派生类没有重新定义该方法。
- 派生类的构造函数自动调用基类的构造函数。
- 派生类的构造函数自动调用基类的默认构造函数，如果没有在成员初始化列表中指定其他构造函数。
- 派生类构造函数显式地调用成员初始化列表中指定的基类构造函数。
- 派生类方法可以使用作用域解析运算符来调用公有的和受保护的基类方法。
- 派生类的友元函数可以通过强制类型转换，将派生类引用或指针转换为基类引用或指针，然后使用该引用或指针来调用基类的友元函数。

PS：今天，2024年01月26日，农历腊月十六，是我的生日，哈哈哈哈，太开心啦



### 13.8.4 类函数小节

C++类函数有很多不同的变体，其中有些可以继承，有些不可以。

参考下表，其中 op= 表示诸如 += 、*= 等格式的赋值运算符。


|    函数    | 能否继承 | 成员还是友元 | 默认能否生成 | 能否为虚函数 | 是否可以有返回类型 |
| :--------: | :------: | :----------: | :----------: | :----------: | :----------------: |
|  构造函数  |    否    |     成员     |      能      |      否      |         否         |
|  析构函数  |    否    |     成员     |      能      |      能      |         否         |
|     =      |    否    |     成员     |      能      |      能      |         能         |
|     &      |    能    |     任意     |      能      |      能      |         能         |
|  转换函数  |    能    |     成员     |      否      |      能      |         否         |
|     ()     |    能    |     成员     |      否      |      能      |         能         |
|     []     |    能    |     成员     |      否      |      能      |         能         |
|     ->     |    能    |     成员     |      否      |      能      |         能         |
|    op=     |    能    |     任意     |      否      |      能      |         能         |
|    new     |    能    |   静态成员   |      否      |      否      |       void*        |
|   delete   |    能    |   静态成员   |      否      |      否      |        void        |
| 其他运算符 |    能    |     任意     |      否      |      能      |         能         |
|  其他成员  |    能    |     成员     |      否      |      能      |         能         |
|    友元    |    否    |     友元     |      否      |      否      |         能         |



# 14 C++ 中的代码重用

## 14.1 包含对象成员的类

### 14.1.1 valarray 类简介

valarray 类，包含在头文件 <valarray> 中，参考链接：[valarray](https://zh.cppreference.com/w/cpp/numeric/valarray)

支持将数组中所有元素的值相加以及在数组中找出最大和最小的值等操作。

valarray 是一个模板类，便于处理不同的数据类型。在声明对象时，必须指定具体的数据类型。

```c++
// int数组
valarray<int> q_values;

// double数组
valarray<double> weights;
```

构造函数使用方法举例

```c++
double gpa[5] = {3.1, 3.5, 3.8, 2.9, 3.3};

// 一个空的double类型数组
valarray<double> v1;

// 拥有8个元素的int类型数组
valarray<int> v2(8);

// 拥有8个元素的int类型数组，均被初始化为10
valarray<int> v3(10, 8);

// 拥有4个元素的double类型数组，被初始化为gpa数组前四个元素值
valarray<double> v4(gpa, 4);

// C++11可以使用初始化列表
valarray<int> v5 = {20, 32, 17, 9};
```

类方法举例

- `operator[]()`：可以直接访问各个元素；
- `size()`：返回包含的元素数；
- `sum()`：返回所有元素的总和；
- `max()`：返回最大的元素；
- `min()`：返回最小的元素；

### 14.1.2 **Student**类的设计

学生不是姓名，也不是一组考试成绩。这里的关系是 has-a ，学生有姓名，也有一组考试分数。通常，用于建立 has-a 关系的 C++ 技术是组合（包含），即创建一个包含其他类对象的类。

> **接口和实现**
>
> 使用公有继承时，类可以继承接口，可能还有实现（基类的纯虚函数提供接口，但不提供实现）。获得接口是 is-a 关系的组成部分。而使用组合，类可以获得实现，但不能获得接口。不继承接口是 has-a 关系的组成部分。

### **14.1.3 Student**类示例

代码参考对应小节练习代码。



> **C++和约束**
>
> C++包含让程序员能够限制程序结构的特性——使用 explicit 防止单参数构造函数的隐式转换，使用 const 限制方法修改数据，等等。这样做的根本原因是：在编译阶段出现错误优于在运行阶段出现错误。



**初始化顺序**

当初始化列表包含多个项目时，这些项目被初始化的顺序为它们被声明的顺序，而不是它们在初始化列表中的顺序。例如，假设 Student 构造函数如下：

```c++
Student(const char * str, const double * pd, int n)
	: scores(pd, n), name(str) {}
```

则 name 成员仍将首先被初始化，因为在类定义中它首先被声明。对于这个例子来说，初始化顺序并不重要，但如果代码使用一个成员的值作为另一个成员的初始化表达式的一部分时，初始化顺序就非常重要了。



## 14.2 私有继承

使用私有继承，基类的公有成员和保护成员都将成为派生类的私有成员。这意味着基类方法将不会成为派生对象公有接口的一部分，但可以在派生类的成员函数中使用它们。

省略关键字则默认为私有继承，private 是默认值，因此省略访问限定符也将导致私有继承。



### 14.2.2 使用包含还是私有继承

大部分首选使用包含

- 易于理解；
- 继承会引起很多问题，尤其从多个基类继承时，可能必须处理很多问题，如包含同名方法的独立的基类或共享祖先的独立基类；
- 包含能够包括多个同类的子对象。如果使用继承 string 类对象，则只能有一个对象，但使用包含，则可以使用多个；

另一种需要使用私有继承的情况是需要重新定义虚函数。派生类可以重新定义虚函数，但包含类不能。使用私有继承，重新定义的函数将只能在类中使用，而不是公有的。

> **提示：**
>
> 通常，应使用包含来建立has-a关系；如果新类需要访问原有类的保护成员，或需要重新定义虚函数，则应使用私有继承。



### 14.2.3 保护继承

保护继承，使用关键字 protected 。下表为各种继承方式：

|       特征       |       公有继承       |        保护继承        |       私有继承       |
| :--------------: | :------------------: | :--------------------: | :------------------: |
|   公有成员变量   |   派生类的公有成员   |    派生类的保护成员    |   派生类的私有成员   |
|   保护成员变量   |   派生类的保护成员   |    派生类的保护成员    |   派生类的私有成员   |
|   私有成员变量   | 只能通过基类接口访问 |  只能通过基类接口访问  | 只能通过基类接口访问 |
| 能否隐式向上转换 |          是          | 是（但只能在派生类中） |          否          |



### 14.2.4 使用**using**重新定义访问权限

设要让基类的方法在派生类外面可用，方法之一是定义一个使用该基类方法的派生类方法。

PS：基本像是把基类方法（STL标准库/其他自定义基类私有/保护方法），重新封装对外接口；



第二种方法，使用 using ，但 using 声明只适用于继承，并不适用于包含。

```c++
class Student : private std::string, private std::valarray<double>
{
public:
    using std::valarray<double>::min;
    using std::valarray<double>::max;
}
```



## 14.3 多重继承



### 14.3.1 有多少 Worker

此时如果从 Singer 和 Waiter 公有派生出 SingingWaiter ，如下

```c++
class SiingingWaiter : public Singer, public Waiter
{
    
};
```

因为 Singer 和 Waiter 都继承自 Worker ，因此 SingingWaiter 将包含两个 Worker 组件。

如果将派生类对象的地址赋给基类指针，将出现二义性：

```C++
SingingWaiter ed;
Worker * pw = &ed; // 不知道是Singer还是Waiter的指针
```

此时应该使用类型转换来指定对象：

```c++
Worker * pw1 = (Waiter *) &ed;
Worker * pw2 = (Singer *) &ed;
```



1. 虚基类

虚基类使得从多个类（它们的基类相同）派生出的对象只继承一个基类对象。例如，通过在类声明中使用关键字 virtual ，可以使 Worker 被用作 Singer 和 Waiter 的虚基类（ virtual 和 public 的次序无关紧要）：

```c++
// 虚基类
class Singer : virtual public Worker
{
    
};

// 虚基类，与顺序无关
class Waiter : public virtual Worker
{
    
};

class SiingingWaiter : public Singer, public Waiter
{
    
};
```

SingingWaiter 对象将只包含 Worker 对象的一个副本。从本质上说，继承的 Singer 和 Waiter 对象共享一个 Worker 对象，而不是各自引入自己的 Worker 对象副本。因为 SingingWaiter 现在只包含了一个 Worker 子对象，所以可以使用多态。



为什么使用术语虚？

毕竟，在虚函数和虚基类之间并不存在明显的联系。C++ 用户强烈反对引入新的关键字，因为这将给他们带来很大的压力。例如，如果新关键字与重要程序中的重要函数或变量的名称相同，这将非常麻烦。因此，C++ 对这种新特性也使用关键字 virtual ——有点像关键字重载。



为什么不抛弃将基类声明为虚的这种方式，而使虚行为成为 MI 的准则呢？

第一，在一些情况下，可能需要基类的多个拷贝；

第二，将基类作为虚的要求程序完成额外的计算，为不需要的工具付出代价是不应当的；

第三，这样做有其缺点；



是否存在麻烦？

是的。为使虚基类能够工作，需要对 C++ 规则进行调整，必须以不同的方式编写一些代码。另外，使用虚基类还可能需要修改已有的代码。例如，将 SingingWaiter 类添加到 Worker 集成层次中时，需要在 Singer 和 Waiter 类中添加关键字 virtual 。



2. 新的构造函数规则

如果 Worker 是虚基类，构造函数默认的信息传递是无效的，如下

```c++
SingingWaiter(const Worker & wk, int p = 0, int v = Singer::other)
    : Waiter(wk, p), Singer(wk, v)
{
        
}
```

此时，如果需要自动传递信息给基类，将通过两条不同的途径（Waiter / Singer）将 wk 传递给 Worker 对象。

因此为了避免冲突，C++ 在基类是虚的时，禁止信息通过中间类自动传递给基类。

但编译器必须在构造派生对象之前构造基类对象组件，此时编译器将使用 Worker 的默认构造函数。

如果不想用默认的，则需要显式地调用所需的基类构造函数

```c++
SingingWaiter(const Worker & wk, int p = 0, int v = Singer::other)
    : Worker(wk), Waiter(wk, p), Singer(wk, v)
{
        
}
```

如上代码将显式的调用构造函数 worker (const Worker &)。此时这种用法是合法的，对于虚基类，必须这样做；但对于非虚基类，则是非法的。

> 警告：
>
> 如果类有间接虚基类，则除非只需使用该虚基类的默认构造函数，否则必须显式地调用该虚基类的某个构造函数。



### 14.3.2 哪个方法

对于单继承，如果没有重新定义Show( )，则将使用最近祖先中的定义。而在多重继承中，每个直接祖先都有一个Show( )函数，这使得上述调用是二义性的。

类似之前的构造函数，普通继承而来的函数，也会存在多重继承的二义性问题。

> 警告：
>
> 多重继承可能导致函数调用的二义性。例如，BadDude 类可能从 Gunslinger 类和 PokerPlayer 类那里继承两个完全不同的 Draw( ) 方法。

解决方法：

- 用作用域运算符显式指出类；
- 在当前类中封装接口，内部使用合适的基类接口实现；

总之，在祖先相同时，使用 MI 必须引入虚基类，并修改构造函数初始化列表的规则。另外，如果在编写这些类时没有考虑到 MI ，则还可能需要重新编写它们。



1. 混合使用虚基类和非虚基类

当类通过多条虚途径和非虚途径继承某个特定的基类时，该类将包含一个表示所有的虚途径的基类子对象和分别表示各条非虚途径的多个基类子对象。

2. 虚基类和支配

派生类中的名称优先于直接或间接祖先类中的相同名称。



### 14.3.3 MI小结

主要变化（同时也是使用虚基类的原因）是，从虚基类的一个或多个实例派生而来的类将只继承了一个基类对象。为实现这种特性，必须满足其他要求：

- 有间接虚基类的派生类包含直接调用间接基类构造函数的构造函数，这对于间接非虚基类来说是非法的；

- 通过优先规则解决名称二义性。

正如您看到的，MI会增加编程的复杂程度。然而，这种复杂性主要是由于派生类通过多条途径继承同一个基类引起的。避免这种情况后，唯一需要注意的是，在必要时对继承的名称进行限定。



## 14.4 类模板

简单模板类声明如下

```c++
template <typename Type>

// 头文件声明类型，应该替换为 Type
Type items[MAX];

// 成员函数实现，要增加模板类变量；内联函数则可以省略模板前缀及类限定符
template <typename Type>
bool Stack<Type>::push(const Type & item)
{

}
```



栈的析构函数对字符串有何影响呢？

没有。构造函数使用new创建一个用于保存指针的数组，析构函数删除该数组，而不是数组元素指向的字符串。



### 14.4.4 数组模板示例和非类型参数

模板常用作容器类，这是因为类型参数的概念非常适合于将相同的存储方案用于不同的类型。

比如常见的 array / map / vector / list 等等，都属于容器类，可以存储不同的类型。



致编译器定义名为ArrayTP<double, 12>的类，并创建一个类型为ArrayTP<double, 12>的eggweight对象。定义类时，编译器将使用double替换T，使用12替换n。

表达式参数有一些限制。表达式参数可以是整型、枚举、引用或指针。因此，double m是不合法的，但double * rm和double * pm是合法的。另外，模板代码不能修改参数的值，也不能使用参数的地址。所以，在ArrayTP模板中不能使用诸如n++和&n等表达式。另外，实例化模板时，用作表达式参数的值必须是常量表达式。

与Stack中使用的构造函数方法相比，这种改变数组大小的方法有一个优点。构造函数方法使用的是通过new和delete管理的堆内存，而表达式参数方法使用的是为自动变量维护的内存栈。这样，执行速度将更快，尤其是在使用了很多小型数组时。



表达式参数的缺点是，每个数组大小都将生成自己的模板，如下为两个独立的类声明

```c++
ArrayTP<double, 12> eggweights;
ArrayTP<double, 13> donuts;
```

但是如下声明，只生成一个类声明，并将数组大小信息传递给类的构造函数：

```c++
Stack<int> eggs(12);
Stact<int> dunkers(13);
```



另一个区别是，构造函数方法更通用，这是因为数组大小是作为类成员（而不是硬编码）存储在定义中的。这样可以将一种尺寸的数组赋给另一种尺寸的数组，也可以创建允许数组大小可变的类。



### 14.4.5 模板多功能性

1. 递归使用模板。

```c++
// twodee是一个包含10个元素的数组，其中每个元素都是一个包含5个int元素的数组。
ArrayTP< ArrayTP<int,5> , 10> twodee;

// 等价的常规数组声明
int twodee[10][5];
```



2. 使用多个类型参数。参考 code_14.19 。



3. 默认类型模板参数。

虽然可以为类模板类型参数提供默认值，但不能为函数模板参数提供默认值。然而，可以为非类型参数提供默认值，这对于类模板和函数模板都是适用的。



### 14.4.6 模板的具体化

1. 隐式实例化。

且编译器在需要对象之前，不会生成类的隐式实例化。比如只有变量的声明，未具体使用时，编译器不会实例化。

2. 显式实例化。

当使用关键字template并指出所需类型来声明类时，编译器将生成类声明的显式实例化（explicit instantiation）。

3. 显式具体化。

显式具体化（explicit specialization）是特定类型（用于替换模板中的泛型）的定义。有时候，可能需要在为特殊类型实例化时，对模板进行修改，使其行为不同。在这种情况下，可以创建显式具体化。

当具体化模板和通用模板都与实例化请求匹配时，编译器将使用具体化版本

4. 部分具体化

类似于函数参数一样，可以指定形参默认值，当无实参传入时，使用默认参数。

如果有多个模板可供选择，编译器将使用具体化程度最高的模板。



### 14.4.7 成员模板

练习代码参考 code_14.20 。

如果用的编译器接受类外边的模板定义，则可以在外边实现，需要分行多层嵌套模板头。



### 14.4.8 将模板用作参数

可以混合使用模板参数和常规参数，代码如下

```c++
template <template <typename T> class Thing, typename U, typename V>
class Crab
{
private:
    Thing<U> s1;
    Thing<V> s2;
}
```

如上代码，s1 / s2 可存储的数据类型为泛型，不是固定类型。此时在程序中声明 Crab 类变量时，应如下操作

```c++
Crab<Stack, int, double> nebula;
```

模板参数 T 表示一种模板类型，类型参数 U 和 V 表示非模板类型。



### 14.4.9 模板类和友元

模板类声明也可以有友元。模板的友元分3类：

- 非模板友元；
- 约束（bound）模板友元，即友元的类型取决于类被实例化时的类型；
- 非约束（unbound）模板友元，即友元的所有具体化都是类的每一 个具体化的友元。



### 14.4.10 模板别名（C++11）

通常，使用 typedef 定义类型别名，但 c++11 提供了另外一种选择

```c++
typedef std::array<double, 12> arrd;

// c++11
template <typename T>
using arrtype = std::array<T, 12>;
```

c++11 允许将语法 using= 用于非模板，参考如下

```c++
typedef const char * pc1;
using pc2 = const char *;

typedef const int *(*pa1)[10];
using pa2 = const int *(*)[10];
```

这种新语法可读性更强一些，可以让类型名和类型信息更清晰。



# 15 友元、异常和其他

## 15.1 友元

### 15.1.1 友元类

什么时候希望一个类成为另一个类的友元呢？我们来看一个例子。假定需要编写一个模拟电视机和遥控器的简单程序。决定定义一个Tv类和一个Remote类，来分别表示电视机和遥控器。很明显，这两个类之间应当存在某种关系，但是什么样的关系呢？遥控器并非电视机，反之亦然，所以公有继承的is-a关系并不适用。遥控器也非电视机的一部分，反之亦然，因此包含或私有继承和保护继承的has-a关系也不适用。事实上，遥控器可以改变电视机的状态，这表明应将Romote类作为Tv类的一个友元。



参考《code_15.01_02_03》，目的在于，类友元是一种自然用语，用于表示一些关系。如果不使用某些形式的友元关系，则必须将Tv类的私有部分设置为公有的，或者创建一个笨拙的、大型类来包含电视机和遥控器。这种解决方法无法反应这样的事实，即同一个遥控器可用于多台电视机。



### 15.1.2 友元成员函数

参考实现头文件 tvfm.h 。



### 15.1.3 其他友元关系

如果两个类需要互相成为友元，则类似步骤如下

```c++
class Tv
{
    friend class Remote;
public:
    void buzz(Remote & r); // 之前已声明Remote为友元类，所以可直接使用
};

class Remote
{
    friend class Tv;
public:
    void Bool volup(Tv & t) { t.volup(); } // 之前已声明Tv为友元类，所以可直接使用
};

inline void Tv::buzz(Remote & r)
{
    // buzz函数用到了Remote类，因此必须在Remote类声明之后定义
}
```

由于Remote的声明位于Tv声明的后面，所以可以在类声明中定义 Remote::volup( )，但Tv::buzz( )方法必须在Tv声明的外部定义，使其位 于Remote声明的后面。如果不希望buzz( )是内联的，则应在一个单独的 方法定义文件中定义它。



### 15.1.4 共同的友元

需要使用友元的另一种情况是，函数需要访问两个类的私有数据。 示例代码如下

```c++
// 前向声明
class Analyzer;

class Probe
{
    friend void sync(Analyzer & a, const Probe & p);
    friend void sync(Probe & p, const Analyzer & a);
};

class Analyzer
{
    friend void sync(Analyzer & a, const Probe & p);
    friend void sync(Probe & p, const Analyzer & a);
};

inline void sync(Analyzer & a, const Probe & p)
{
    
}

inline void sync(Probe & p, const Analyzer & a)
{
    
}
```



## 15.2 嵌套类

struct 结构体内部也可存在构造函数，与 class 类有点相似；

如果要在方法文件中定义构造函数，则需要通过多次作用域解析运算符实现，类似下属代码

```c++
Queue::Node::Node(const Item & i)
    : item(i), next(0)
{
        
}
```



### 15.2.1 嵌套类和访问权限

类的默认访问权限是私有的，且派生类不能直接访问基类的私有部分。

1. 作用域

嵌套类、结构和枚举的作用域特征参考下表

| 声明位置 | 包含它的类是否可以使用它 | 从包含它的类派生而来的类是否可以使用它 |   在外部是否可以使用   |
| :------: | :----------------------: | :------------------------------------: | :--------------------: |
| 私有部分 |            是            |                   否                   |           否           |
| 保护部分 |            是            |                   是                   |           否           |
| 公用部分 |            是            |                   是                   | 是，通过类限定符来使用 |

2. 访问控制

类声明的位置决定了类的作用域或可见性。类可见后，访问 控制规则（公有、保护、私有、友元）将决定程序对嵌套类成员的访问 权限。

即类放在哪个地方，决定别人能不能看到它；但类内部成员仍然遵循控制规则，决定看到这个类的地方，能不能用这些成员数据。



### 15.2.2 模板中的嵌套

参考练习代码《code_15.05_06》。



## 15.3 异常

### 15.3.1 调用abort()

参考代码 15.07 运行结果。

### 15.3.2 返回错误码

参考代码 15.08 运行结果。

### 15.3.3 异常机制

如果函数引发了异常，而没有try块或没有匹配的处理 程序时，将会发生什么情况？

在默认情况下下，程序最终将调用abort( ) 函数，但可以修改这种行为。

### 15.3.4 将对象用作异常类型















