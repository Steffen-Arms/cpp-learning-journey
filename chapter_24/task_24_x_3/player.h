#ifndef PLAYER_H
#define PLAYER_H

#include "creature.h"
#include <iostream>

class Player : public Creature
{
  private:
    int m_level{1};

  public:
    Player(std::string_view name) : Creature(name, '@', 10, 1, 0) {}

    void levelUp()
    {
        ++m_level;
        ++m_attack;
    }

    int getLevel() const { return m_level; }

    bool hasWon() const { return m_level >= 20; }

    friend std::ostream& operator<<(std::ostream& out, const Player& player);
};

std::ostream& operator<<(std::ostream& out, const Player& player)
{
    out << "You have health: " << player.getHealth()
        << " level: " << player.getLevel() << " attack: " << player.getAttack()
        << " gold: " << player.getGold();
    return out;
}

#endif
