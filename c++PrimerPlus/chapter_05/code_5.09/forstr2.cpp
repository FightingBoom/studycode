#include <iostream>
#include <string>

int main()
{
    using namespace std;

    cout << "Enter a word: ";

    string strWord;
    cin >> strWord;

    char temp;
    int i, j;
    for (j = 0, i = strWord.size() - 1; j < i; --i, ++j)
    {
        temp = strWord[i];
        strWord[i] = strWord[j];
        strWord[j] = temp;
    }

    cout << strWord << "\nDone\n";

    return 0;
}


/*
Enter a word: stressed
desserts
Done
*/
