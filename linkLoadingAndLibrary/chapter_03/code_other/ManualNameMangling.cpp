#include <stdio.h>

namespace myname {
    int var = 42;
}

extern "C" int _ZN6myname3varEi;

int main()
{
    printf("%d\n", _ZN6myname3varEi);
    return 0;
}

/*
zhaochen@zhaochendeAir code_other % gcc ManualNameMangling.cpp -o ManualNameMangling
Undefined symbols for architecture arm64:
  "myname::var(int)", referenced from:
      _main in ManualNameMangling-783761.o
ld: symbol(s) not found for architecture arm64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
zhaochen@zhaochendeAir code_other %
*/
