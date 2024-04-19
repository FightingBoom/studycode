#include <iostream>
#include <string>
#include <sstream>

int main()
{
    char character = 1; // 10 64 1

    printf("character(%%d) = %d\n", character);

    printf("character(%%c) = %c\n", character);

    std::ostringstream oss;
    oss << character;
    printf("character(%%s) = %s\n", oss.str().c_str());

    return 0;
}

/*
zhaochen@zhaochendeAir to_string_test % ./a.out
character(%d) = 10
character(%c) = 

character(%s) = 

zhaochen@zhaochendeAir to_string_test % clang++ toStringTestV1.cpp
zhaochen@zhaochendeAir to_string_test % ./a.out                   
character(%d) = 64
character(%c) = @
character(%s) = @
zhaochen@zhaochendeAir to_string_test % 
zhaochen@zhaochendeAir to_string_test % 
zhaochen@zhaochendeAir to_string_test % clang++ toStringTestV1.cpp
zhaochen@zhaochendeAir to_string_test % ./a.out                   
character(%d) = 1
character(%c) = 
character(%s) = 
zhaochen@zhaochendeAir to_string_test %
*/


