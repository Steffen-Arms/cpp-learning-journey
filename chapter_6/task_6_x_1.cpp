#include <iostream>
#include <string_view>

constexpr std::string_view getQuantityPhrase(int quant)
{
    if (quant < 0)
        return "negative";
    else if (quant == 0)
        return "no";
    else if (quant == 1)
        return "a single";
    else if (quant == 2)
        return "a couple of";
    else if (quant == 3)
        return "a few";
    else
        return "many";
}

constexpr std::string_view getApplesPluralized(int amount_apples)
{
    return (amount_apples == 1 ? "apple" : "apples");
}

int main()
{
    constexpr int maryApples{3};
    std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' '
              << getApplesPluralized(maryApples) << ".\n";

    std::cout << "How many apples do you have? ";
    int numApples{};
    std::cin >> numApples;

    std::cout << "You have " << getQuantityPhrase(numApples) << ' '
              << getApplesPluralized(numApples) << ".\n";
}
