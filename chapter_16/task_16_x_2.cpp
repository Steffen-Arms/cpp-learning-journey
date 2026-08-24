#include <cassert>
#include <iostream>
#include <string_view>
#include <vector>

namespace Items
{

enum ItemTypes : int
{
    healthPotions,
    torches,
    arrows,
    max_items,
};
}

template <typename T> int countItems(const std::vector<T>& itemVector)
{

    int count{};
    for (auto item : itemVector)
    {
        count += item;
    }
    return count;
}

std::string_view getItemNamePlural(const Items::ItemTypes& type)
{
    switch (type)
    {
    case Items::healthPotions:
        return "health Potions";
    case Items::torches:
        return "torches";
    case Items::arrows:
        return "arrows";
    default:
        return "???";
    }
}

std::string_view getItemNameSingular(const Items::ItemTypes& type)
{
    switch (type)
    {
    case Items::healthPotions:
        return "health Potion";
    case Items::torches:
        return "torche";
    case Items::arrows:
        return "arrow";
    default:
        return "???";
    }
}

void printItem(Items::ItemTypes itemType, int amountItem)
{
    if (amountItem == 0)
    {
        std::cout << "You have 0 " << getItemNamePlural(itemType) << "\n";
    }
    else if (amountItem == 1)
    {
        std::cout << "You have 1 " << getItemNameSingular(itemType) << "\n";
    }
    else if (amountItem > 1)
    {
        std::cout << "You have " << amountItem << " "
                  << getItemNamePlural(itemType) << "\n";
    }
    else
    {
        std::cout << "??? something went wrong";
    }
}

template <typename T> void printItemsVector(const std::vector<T>& itemVector)
{
    for (int i{0}; i < Items::max_items; ++i)
    {
        printItem(static_cast<Items::ItemTypes>(i), itemVector.data()[i]);
    }
}

int main()
{
    std::vector<int> inventary(3);
    inventary[Items::healthPotions] = 1;
    inventary[Items::torches] = 5;
    inventary[Items::arrows] = 10;

    assert(std::size(inventary) == Items::max_items);

    printItemsVector(inventary);
    std::cout << "You have " << countItems(inventary) << " total items \n";
}
