#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>

using namespace std;

char toLower(char ch) { return tolower(ch); }
string & ToLower(string & st);
void display(const string & s);

int main()
{
    // 获取初始字符串输入
    vector<string> words;
    cout << "Enter words (enter quit to quit):\n";
    string input;
    while (cin >> input && input != "quit")
        words.push_back(input);

    cout << "You entered the following words:\n";
    for_each(words.begin(), words.end(), display);
    cout << endl;

    // 使用set的自动排序，且全部转换为小写
    set<string> wordset;
    transform(words.begin(), words.end(),
        insert_iterator<set<string> > (wordset,
            wordset.begin()),
        ToLower);
    cout << "\nAlphabetis list of words:\n";
    for_each(wordset.begin(), wordset.end(), display);
    cout << endl;

    // 统计单词出现的频率/次数
    map<string, int> wordmap;
    set<string>::iterator si;
    for (si = wordset.begin(); si != wordset.end(); si++)
        wordmap[*si] =
            count(words.begin(), words.end(), *si);

    cout << "\nWord frequency:\n";
    for (si = wordset.begin(); si != wordset.end(); si++)
        cout << *si << ": " << wordmap[*si] << endl;

    return 0;
}

string & ToLower(string & st)
{
    transform(st.begin(), st.end(), st.begin(), toLower);
    return st;
}

void display(const string & s)
{
    cout << s << " ";
}

/*
zhaochen@zhaochendeMacBook-Air code_16.19 % clang++ usealgo.cpp 
zhaochen@zhaochendeMacBook-Air code_16.19 % ./a.out 
Enter words (enter quit to quit):
The dog saw the cat and thought the cat fat
The cat thought the cat perfect
quit
You entered the following words:
The dog saw the cat and thought the cat fat The cat thought the cat perfect 

Alphabetis list of words:
and cat dog fat perfect saw the thought 

Word frequency:
and: 1
cat: 4
dog: 1
fat: 1
perfect: 1
saw: 1
the: 5
thought: 2
*/
