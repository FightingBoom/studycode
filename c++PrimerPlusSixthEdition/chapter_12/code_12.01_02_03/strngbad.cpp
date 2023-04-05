#include <cstring>
#include "strngbad.h"

using std::cout;

int StringBad::num_strings = 0; // 静态成员初始化

StringBad::StringBad(const char * s)
{
    len = std::strlen(s);       // 获取传入字符串的长度
    str = new char[len + 1];    // 根据当前字符串长度，动态初始化内存
    std::strcpy(str, s);        // 拷贝到当前类成员变量中
    num_strings++;              // 类静态数据++
    cout << num_strings << ": \"" << str << "\" object created\n";
}

StringBad::StringBad()
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++"); // 默认初始化字符串
    num_strings++;
    cout << num_strings << ": \"" << str << "\" default object created\n";
}

StringBad::~StringBad()
{
    cout << "\"" << str << "\" object deleted, ";
    --num_strings;
    cout << num_strings << " left\n";
    delete [] str; // 析构函数，删除动态申请内存
}

std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
    os << st.str;
    return os;
}

