
#include <iostream>

int main()
{
    int x{};
    const int* ptr{&x}; // assume 4 byte ints

    std::cout << ptr << ' ' << (ptr + 1) << ' ' << (ptr + 2) << '\n';
    std::cout << sizeof(ptr) << ' ' << sizeof(*ptr) << '\n';

    return 0;
}
