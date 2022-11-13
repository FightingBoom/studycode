#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int strWordSize = 32;

int main()
{
    char strInputWord[strWordSize];
    int vowelNumbers = 0;       // 元音数量；a e i o u
    int consonantNumbers = 0;   // 辅音数量；
    int otherNumbers = 0;       // 非字母开头单词

    cout << "Enter words (q to quit):\n";
    cin >> strInputWord;
    while (strcmp(strInputWord, "q"))   // 用strcmp接口，判断整个单词是否相同
    {
        if (isalpha(strInputWord[0]))
        {
            switch (strInputWord[0])
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vowelNumbers++;
                    break;
                default:
                    consonantNumbers++;
                    break;
            }
        }
        else
        {
            otherNumbers++;
        }

        cin >> strInputWord;
    }

    cout << vowelNumbers << " words beginning with vowels\n";
    cout << consonantNumbers << " words beginning with consonants\n";
    cout << otherNumbers << " others\n";

    return 0;
}

/*
Enter words (q to quit):
The 12 awesome oxen ambled
quietly across 15 meters of lawn. q
5 words beginning with vowels
4 words beginning with consonants
2 others
*/
