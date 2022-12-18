#include <iostream>
#include <cctype>

using namespace std;

void StringToUpper(string & strBuffer);

int main()
{
    string str;
    cout << "Enter a string (q to quit): ";
    getline(cin, str);
    while ("q" != str)
    {
        StringToUpper(str);
        cout << str << endl;
        cout << "Next string (q to quit): ";
        getline(cin, str);
    }

    cout << "Done!\n";
    return 0;
}

void StringToUpper(string & strBuffer)
{
    for (int i = 0; i < strBuffer.size(); i++)
    {
        strBuffer[i] = toupper(strBuffer[i]);
    }
}

/*
Enter a string (q to quit): go away
GO AWAY
Next string (q to quit): good grief!
GOOD GRIEF!
Next string (q to quit): q
Done!
*/
