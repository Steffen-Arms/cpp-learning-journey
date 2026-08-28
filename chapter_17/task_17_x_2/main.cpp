#include "inputValidation.h"
#include "player.h"
#include "shopItems.h"
#include <iostream>

void printShop()
{
    std::cout << "Here is our selection for today: \n";

    for (auto i : Potion::potionTypesArray)
    {
        std::cout << i << ") " << Potion::potionNamesArray[i] << " costs "
                  << Potion::potionCostArray[i] << '\n';
    }
    std::cout << '\n';
}

void buyPotion(Potion::Type potionType, Player& player)
{
    if (player.getGold() < Potion::potionCostArray[potionType])
    {
        std::cout << "sry, you don't haven enough money \n";
    }
    else
    {
        player.subtractGold(Potion::potionCostArray[potionType]);
        player.inkrementInventory(potionType);
        std::cout << "You purchased a potion of "
                  << Potion::potionNamesArray[potionType] << ". You have "
                  << player.getGold() << " left. \n";
    }
}

void shopping(Player& player)
{
    printShop();
    while (true)
    {
        std::cout << "Enter the number of the potion you'd like to buy, or 'q' "
                     "to quit: ";
        char inputUser{};
        std::cin >> inputUser;
        ignoreLine();
        std::cout << '\n';

        if (!clearFailedExtraction())
        {

            switch (inputUser)
            {
            case 'q':
                player.printInventory();
                std::cout
                    << "Thanks for shopping at Roscoe's potion emporium! \n";
                return;

            default:
                int castInputUser{static_cast<int>(inputUser) -
                                  static_cast<int>('0')};
                if (castInputUser > Potion::max_potions || castInputUser < 0)
                {
                    std::cout << "Invalid Number try again: \n";
                    continue;
                }
                buyPotion(static_cast<Potion::Type>(castInputUser), player);
            }
        }
        else
        {
            std::cout << "Invalid Input try again: \n";
        }
    }
}

std::string getName()
{
    while (true)
    {
        std::cout << "Enter your name: ";
        std::string inputName{};
        std::cin >> inputName;
        std::cout << '\n';
        if (clearFailedExtraction())
        {
            ignoreLine();
            std::cout << "Invalid Input try again \n";
        }
        else
        {
            return inputName;
        }
    }
}

int main()
{
    std::cout << "Welcome to Roscoe's potion emporium! \n";
    std::string name{getName()};
    Player newPlayer{name};
    std::cout << "Hello, " << name << ", you have " << newPlayer.getGold()
              << " gold. \n";
    shopping(newPlayer);

    return 0;
}
