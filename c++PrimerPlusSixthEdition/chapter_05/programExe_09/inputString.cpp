#include <iostream>
#include <string>

using namespace std;

const int MAXLENGTH = 32;   // 单个单词最大长度

int main()
{
    string strWords;        // 存放单个单词
    int iWordsCount = 0;    // 单词计数

    cout << "Enter words (to stop, type the word done):" << endl;
    cin >> strWords;

    while ("done" != strWords)  // string类型，可直接使用 == 比较
    {
        cin >> strWords;    // cin只能输入一个单词，遇到空格就认为该单词结束了
        iWordsCount++;      // 经过while判断不相等，才能+1
    }

    cout << "You entered a total of " << iWordsCount << " words" << endl;

    return 0;
}

/*
Enter words (to stop, type the word done):
anteater birthday category dumpster
envy finagle geometry done for sure
You entered a total of 7 words
*/