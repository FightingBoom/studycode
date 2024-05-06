#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using std::string;

const int NUM = 26;
const string wordlist[NUM] = {
    "apiary", "beetle", "cereal", "danger", "ensign",
    "florid", "garage", "health", "insult", "jackal",
    "keeper", "loaner", "manage", "nonce", "onset",
    "plaid", "quilt", "remote", "stolid", "train",
    "useful", "valid", "whence", "xenon", "yearn",
    "zippy"
};

int main()
{
    using std::cout;
    using std::cin;
    using std::tolower;
    using std::endl;

    std::srand(std::time(0));

    char play;
    cout << "Will you play a word game? <y/n> ";
    cin >> play;
    play = tolower(play);

    while(play == 'y')
    {
        string target = wordlist[std::rand() % NUM];
        int length = target.length();
        string attempt(length, '-');
        string badchars;
        int guesses = 6;
        cout << "Guess my secret word. It has " << length
            << " letters, and you guess\n"
            << "one letter at a time. You get " << guesses
            << " wrong guesses.\n";

        cout << "Your word: " << attempt << endl;
        while(guesses > 0 && attempt != target)
        {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;

            if (badchars.find(letter) != string::npos
                || attempt.find(letter) != string::npos)
            {
                cout << "You already guessed that. "
                    "Try again.\n";
                continue;
            }

            int loc = target.find(letter);
            if (loc == string::npos)
            {
                cout << "Oh, bad guess!\n";
                --guesses;
                badchars += letter;
            }
            else
            {
                cout << "Good guess!\n";
                attempt[loc] = letter;

                loc = target.find(letter, loc + 1);
                while(loc != string::npos)
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }

            cout << "Your word: " << attempt << endl;
            if (attempt != target)
            {
                if (badchars.length() > 0)
                    cout << "Bad choices: " << badchars
                        << endl;
                cout << guesses << " bad guesses left\n";
            }
        }

        if (guesses > 0)
            cout << "That's right!\n";
        else
            cout << "Sorry, the word is "
                << target << ".\n";

        cout << "Will you play another <y/n> ";
        cin >> play;
        play = tolower(play);
    }

    cout << "Bye\n";

    return 0;
}

/*
zhaochen@zhaochendeAir code_16.03 % clang++ hangman.cpp 
zhaochen@zhaochendeAir code_16.03 % ./a.out 
Will you play a word game? <y/n> Y
Guess my secret word. It has 5 letters, and you guess
one letter at a time. You get 6 wrong guesses.
Your word: -----
Guess a letter: e
Good guess!
Your word: -e---
6bad guesses left
Guess a letter: a 
Oh, bad guess!
Your word: -e---
Bad choices: a
5bad guesses left
Guess a letter: t
Oh, bad guess!
Your word: -e---
Bad choices: at
4bad guesses left
Guess a letter: r
Oh, bad guess!
Your word: -e---
Bad choices: atr
3bad guesses left
Guess a letter: y
Oh, bad guess!
Your word: -e---
Bad choices: atry
2bad guesses left
Guess a letter: i
Oh, bad guess!
Your word: -e---
Bad choices: atryi
1bad guesses left
Guess a letter: p
Oh, bad guess!
Your word: -e---
Bad choices: atryip
0bad guesses left
Sorry, the word is xenon.
Will you play another <y/n> n
Bye
*/
