#include "my.h"

int main()
{
    extern int foo;
    foo = 7;

    print_foo();

    print(99);

    return 0;
}