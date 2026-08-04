#include <iostream>

constexpr bool isEven(int number) { return number % 2 == 0; }

int readInt()
{
    int x{};
    std::cin >> x;
    return x;
}

int main()
{

    std::cout << "Enter an integer: ";
    const int x{readInt()};
    if (isEven(x))
        std::cout << "is even";
    else
        std::cout << "is odd";

    return 0;
}
