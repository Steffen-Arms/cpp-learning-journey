#include <iostream>

int main()
{
    int x = 5;
    std::cout << sizeof(int) << "\n";
    std::cout << sizeof(x) << "\n";
    std::cout << &x << " " << &x + 1;
}
