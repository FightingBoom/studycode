#include <iostream>
#include "string1.h"

const int ArSize = 10;
const int MaxLen = 81;

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    String name;
    cout << "Hi, what's your name?\n>> ";
    cin >> name;

    cout << name << ", please enter up to " << ArSize
        << " short sayings <empty line to quit>:\n";
    
    String sayings[ArSize]; // 有ArSize个String类型变量
    char temp[MaxLen];
    int i;

    for (i = 0; i < ArSize; i++)
    {
        cout << i + 1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n') // 得到有效输入
            continue;
        if (!cin || temp[0] == '\0') // 较早的get版本读取空行后，不会返回false，但第一个字符为空
            break;
        else
            sayings[i] = temp;
    }

    int total = i;
    if (total > 0) // 存在有效输入，此时i大于0
    {
        cout << "Here are your sayings:\n";
        for (i = 0; i < total; i++)
            cout << sayings[i][0] << ": " << sayings[i] << endl;

        int shortest = 0;
        int first = 0;
        for (i = 1; i < total; i++)
        {
            if (sayings[i].length() < sayings[shortest].length())
                shortest = i;
            if (sayings[i] < sayings[first]) // 取长度最短的地址
                first = i;
        }

        cout << "Shortest saying:\n" << sayings[shortest] << endl;
        cout << "First alphabetically:\n" << sayings[first] << endl;
        cout << "This program used " << String::HowMany() << " String objects. Bye.\n";
    }
    else
    {
        cout << "No input! Bye.\n";
    }

    return 0;
}

/*
Hi, what's your name?
>> Misty Gutz
Misty Gutz, please enter up to 10 short sayings <empty line to quit>:
1: a fool and his money are soon parted
2: penny wise, pound foolish
3: the love of money is the root of much evil
4: out of sight, out of mind
5: absence makes the heart grow fonder
6: absinthe makes the hart grow fonder
7: 
Here are your sayings:
a: a fool and his money are soon parted      
p: penny wise, pound foolish
t: the love of money is the root of much evil
o: out of sight, out of mind
a: absence makes the heart grow fonder       
a: absinthe makes the hart grow fonder
Shortest saying:
penny wise, pound foolish
First alphabetically:
a fool and his money are soon parted
This program used 11 String objects. Bye.
*/

/* 谚语
1：傻瓜和他的钱很快就分开了
2：因小失大
3：对金钱的热爱是许多邪恶的根源
4：眼不见，心不烦
5：缺席让心变得更亲密
6：苦艾酒使哈特变得更可爱
*/