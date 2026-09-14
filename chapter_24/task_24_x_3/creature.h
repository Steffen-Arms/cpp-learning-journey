#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <string_view>

class Creature
{
  protected:
    std::string m_name;
    char m_symbol{};
    int m_health{};
    int m_attack{};
    int m_gold{};

  public:
    Creature(std::string_view name, char symbol, int health, int attack,
             int gold)
        : m_name{name}, m_symbol{symbol}, m_health{health}, m_attack{attack},
          m_gold{gold}
    {
    }

    void reduceHealth(int x) { m_health -= x; }

    bool isDead() const { return m_health <= 0; }

    void addGold(int extraGold) { m_gold += extraGold; }

    const std::string& getName() const { return m_name; }

    char getSymbol() const { return m_symbol; }

    int getHealth() const { return m_health; }

    int getAttack() const { return m_attack; }

    int getGold() const { return m_gold; }
};

#endif
