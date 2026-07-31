#include <iostream>

void doNothing(
    int &) // Don't worry about what & is for now, we're just using it to trick
           // the compiler into thinking variable x is used
{
}

int main()
{
    std::cout << sizeof(int) << '\n';
    6 + 5;
    return 0;
}
