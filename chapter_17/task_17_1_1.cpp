#include <array>
#include <iostream>

int main()
{
    [[maybe_unused]] std::array<double, 365> highTemp{};

    std::array<char, 5> hello{'h', 'e', 'l', 'l', 'o'};
    std::cout << "Element of index 1: " << hello[1];
}
