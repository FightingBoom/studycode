#include <iostream>
#include <cstring>

using namespace std;

const int MAXLENGTH = 32;   // 单个单词最大长度

int main()
{
    char cWords[MAXLENGTH] = {0};   // 存放单个单词
    int iWordsCount = 0;            // 单词计数

    cout << "Enter words (to stop, type the word done):" << endl;
    cin >> cWords;

    while (strcmp(cWords, "done"))
    {
        cin >> cWords;  // cin只能输入一个单词，遇到空格就认为该单词结束了
        iWordsCount++;  // 经过while判断不相等，才能+1
    }

    cout << "You entered a total of " << iWordsCount << " words" << endl;

    return 0;
}

/*
Enter words (to stop, type the word done):
anteater birthday category dumpster
anteater birthday category dumpster
envy finagle geometry done for sure
You entered a total of 11 words

-----------------------------

Enter words (to stop, type the word done):
anteater birthday category dumpster
envy finagle geometry done for sure
You entered a total of 7 words
*/