#include "shopItems.h"
#include <iostream>

void shop()
{
    std::cout << "Here is our selection for today: \n";

    for (auto i : Potion::potionTypesArray)
    {
        std::cout << i << ") " << Potion::potionNamesArray[i] << " costs "
                  << Potion::potionCostArray[i] << '\n';
    }
}

int main()
{
    shop();
    return 0;
}
