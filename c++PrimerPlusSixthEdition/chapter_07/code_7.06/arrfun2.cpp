#include <iostream>

// using namespace std;

const int ArSize = 8;

int sum_arr(int arr[], int n);

int main()
{
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};

    std::cout << cookies << " = arrays address, ";

    std::cout << sizeof cookies << " = sizeof cookies\n";

    int sum = sum_arr(cookies, ArSize);
    std::cout << "Total cookies eaten: " << sum << std::endl;

    sum = sum_arr(cookies, 3);
    std::cout << "First three eaters ate " << sum << " cookies.\n";

    sum = sum_arr(cookies + 4, 4);
    std::cout << "Last four eaters ate " << sum << " cookies.\n";

    return 0;
}

// 形参，真的可以为数组诶
int sum_arr(int arr[], int n)
{
    int total = 0;

    std::cout << arr << " = arr, ";
    std::cout << sizeof arr << " = sizeof arr\n";

    for (int i = 0; i < n; i++)
        total = total + arr[i];
    return total;
}


/*
arrfun2.cpp: In function 'int sum_arr(int*, int)':
arrfun2.cpp:35:25: warning: 'sizeof' on array function parameter 'arr' will return size of 'int*' [-Wsizeof-array-argument]
     std::cout << sizeof arr << " = sizeof arr\n";
                         ^~~
arrfun2.cpp:30:17: note: declared here
 int sum_arr(int arr[], int n)
             ~~~~^~~~~
0x61fdf0 = arrays address, 32 = sizeof cookies
0x61fdf0 = arr, 8 = sizeof arr
Total cookies eaten: 255
0x61fdf0 = arr, 8 = sizeof arr
First three eaters ate 7 cookies.
0x61fe00 = arr, 8 = sizeof arr
Last four eaters ate 240 cookies.
*/

