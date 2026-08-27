#include <array>
#include <iostream>
#include <string_view>

struct Item
{
    std::string_view name{};
    int gold{};
};

template <typename T, std::size_t N>
void printStore(const std::array<T, N>& arr)
{
    for (auto i : arr)
    {
        std::cout << "A " << i.name << " costs " << i.gold << " gold. \n";
    }
}

int main()
{

    constexpr std::array<Item, 4> itemOjbects{
        {{"sword", 5}, {"dagger", 3}, {"club", 2}, {"spear", 7}}};

    printStore(itemOjbects);
    return 0;
}
