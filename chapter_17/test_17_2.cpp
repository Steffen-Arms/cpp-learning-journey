#include <array>
#include <iostream>

template <auto Length> void printLength(const std::array<int, Length>& arr)
{
    constexpr int length{std::size(arr)};
    std::cout << "length: " << length << '\n';
}

int main()
{
    std::array arr{9, 7, 5, 3, 1};
    constexpr int length{std::size(arr)}; // works just fine
    std::cout << "length: " << length << '\n';

    printLength(arr);

    return 0;
}
