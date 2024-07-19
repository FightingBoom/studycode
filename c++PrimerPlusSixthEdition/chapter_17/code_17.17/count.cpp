#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char * argv[])
{
    if (argc == 1)
    {
        cerr << "Usage: " << argv[0] << " filename[s]\n";
        exit(EXIT_FAILURE);
    }

    ifstream fin;
    long count;
    long total = 0;
    char ch;

    for (int file = 1; file < argc; file++)
    {
        fin.open(argv[file]);
        if (!fin.is_open())
        {
            cerr << "Could not open " << argv[file] << endl;
            fin.clear();
            continue;
        }

        count = 0;
        while (fin.get(ch))
            count++;

        cout << count << " characters in " << argv[file]
            << endl;

        total += count;

        fin.clear();    // 利用一个fin输入流，打开多个文件
        fin.close();
    }

    cout << total << " characters in all files\n";

    return 0;
}

/*
zhaochen@zhaochendeAir code_17.17 % clang++ count.cpp 
zhaochen@zhaochendeAir code_17.17 % ./a.out 
Usage: ./a.out filename[s]
zhaochen@zhaochendeAir code_17.17 % ./a.out paris rome
Could not open paris
Could not open rome
0 characters in all files
zhaochen@zhaochendeAir code_17.17 % 
zhaochen@zhaochendeAir code_17.17 % ./a.out paris rome
21 characters in paris
20 characters in rome
41 characters in all files
*/
