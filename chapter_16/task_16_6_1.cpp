#include <iostream>
#include <vector>

int main()
{
    std::vector arr{4, 6, 7, 3, 8, 2, 1, 9};

    std::size_t length{arr.size()};

    std::cout << "Vector: ";

    for (std::size_t i{0}; i < length; ++i)
    {
        std::cout << arr.at(i) << " ";
    }
    std::cout << "\n";

    return 0;
}
