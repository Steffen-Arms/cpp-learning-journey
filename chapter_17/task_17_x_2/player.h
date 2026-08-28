

#ifndef PLAYER_H
#define PLAYER_H

#include "shopItems.h"
#include <array>
#include <iostream>
#include <string>

class Player
{
  private:
    static constexpr int s_minStartGold{80};
    static constexpr int s_maxStartGold{120};
    std::string m_name{};
    int m_gold{};
    std::array<int, Potion::max_potions> m_playerInventory{0, 0, 0, 0};
    std::string getName();

  public:
    explicit Player(std::string_view);

    int getGold() { return m_gold; }
    void subtractGold(int subtractGold)
    {
        if (m_gold - subtractGold < 0)
        {
            std::cout << "something went wrong to little gold";
        }
        else
        {
            m_gold -= subtractGold;
        }
    }

    std::array<int, Potion::max_potions> getInventory()
    {
        return m_playerInventory;
    }
    void inkrementInventory(Potion::Type potionType)
    {
        ++m_playerInventory[potionType];
    }

    void printInventory()
    {
        std::cout << "Your inventory contains: \n";
        for (auto item : Potion::potionTypesArray)
        {
            std::cout << m_playerInventory[item] << "x potion of "
                      << Potion::potionNamesArray[item] << '\n';
        }
        std::cout << "You escaped with " << m_gold << " gold remaining. \n";
    }
};

#endif
