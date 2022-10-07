#include <iostream>
#include <string>

int main()
{
    using namespace std;

    cout << "Enter a word: ";

    string strWord;
    cin >> strWord;

    for (int i = strWord.size() - 1; i >= 0; i--)
        cout << strWord.at(i);
    
    cout << "\nBye.\n";

    return 0;
}


/*
Enter a word: animal
lamina
Bye.
*/
