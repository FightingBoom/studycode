#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main()
{
    using namespace std;
    ifstream fin;
    fin.open("tobuy.txt");
    if (fin.is_open() == false)
    {
        cerr << "Can't open file. Bye.\n";
        exit(EXIT_FAILURE);
    }

    string item;
    int count = 0;
    getline(fin, item, ':');
    while (fin)
    {
        ++count;
        cout << count << ": " << item << endl;
        getline(fin, item, ':');
    }

    cout << "Done\n";
    fin.close();

    return 0;
}

/*
sardines:chocolate ice cream:pop corn:leeks:
cottage cheese:olive oil:butter:tofu:
《结尾无换行符》

zhaochen@zhaochendeAir code_16.02 % clang++ strfile.cpp 
zhaochen@zhaochendeAir code_16.02 % ./a.out 
1: sardines
2: chocolate ice cream
3: pop corn
4: leeks
5: 
cottage cheese
6: olive oil
7: butter
8: tofu
Done
*/

/*
sardines:chocolate ice cream:pop corn:leeks:
cottage cheese:olive oil:butter:tofu:
《结尾带换行符，有一个新的空白行》

zhaochen@zhaochendeAir code_16.02 % clang++ strfile.cpp
zhaochen@zhaochendeAir code_16.02 % ./a.out            
1: sardines
2: chocolate ice cream
3: pop corn
4: leeks
5: 
cottage cheese
6: olive oil
7: butter
8: tofu
9: 

Done
*/

