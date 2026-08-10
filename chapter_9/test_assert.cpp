// #define NDEBUG // disable asserts (must be placed before any #includes)
#include <cassert>
#include <iostream>

int main()
{
    assert(false &&
           "test output this message"); // won't trigger since asserts have been
                                        // disabled in this translation unit
    std::cout << "Hello, world!\n";

    return 0;
}
