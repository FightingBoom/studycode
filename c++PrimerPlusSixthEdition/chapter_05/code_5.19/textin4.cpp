#include <iostream>

using namespace std;

int main()
{
    char ch;
    int count = 0;

    while ((ch = cin.get()) != EOF)
    {
        cout.put(char(ch));
        ++count;
    }

    cout << endl << count << " characters read\n";  // 神奇，竟然能自动回显出来。

    return 0;
}

/* while ((ch = cin.get()) != EOF)
The sullen mackerel sulks in the shadowy shallows.
The sullen mackerel sulks in the shadowy shallows.
Yes, but the blue bird of happiness harbors secrets.
Yes, but the blue bird of happiness harbors secrets.
^Z

104 characters read
*/


/* while (ch = cin.get() != EOF)
The sullen mackerel sulks in the shadowy shallows.
Yes, but the blue bird of happiness harbors secrets.
^Z

104 characters read
*/

