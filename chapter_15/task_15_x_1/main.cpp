#include "random.h"
#include <iostream>
#include <string>

class Monster
{
  public:
    enum MonsterType
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        maxMonsterType,
    };

    Monster(MonsterType monster, std::string_view name, std::string_view roar,
            int hitPoints)
        : m_type{monster}, m_name{name}, m_roar{roar}, m_hitPoints{hitPoints}
    {
    }

    void print();
    constexpr std::string_view getTypeString();

  private:
    MonsterType m_type{};
    std::string m_name{"???"};
    std::string m_roar{"???"};
    int m_hitPoints{0};
};

constexpr std::string_view Monster::getTypeString()
{
    switch (m_type)
    {
    case Monster::dragon:
        return "Dragon";
    case Monster::goblin:
        return "Goblin";
    case Monster::ogre:
        return "Ogre";
    case Monster::skeleton:
        return "Skeleton";
    case Monster::troll:
        return "Troll";
    case Monster::vampire:
        return "Vampire";
    case Monster::zombie:
        return "Zombie";
    default:
        return "???";
    }
}

void Monster::print()
{
    std::cout << m_name << " the " << getTypeString();
    if (m_hitPoints <= 0)
    {
        std::cout << " is dead. \n";
    }
    else
    {
        std::cout << " has " << m_hitPoints << " hit points and says " << m_roar
                  << ". \n";
    }
}

//////////////////////////////////////////////////////
//
namespace MonsterGenerator
{
std::string_view getName(int i)
{
    switch (i)
    {
    case 0:
        return "Peter";
    case 1:
        return "Klaus";
    case 2:
        return "jojo";
    case 3:
        return "emi";
    case 4:
        return "olaf";
    case 5:
        return "jochen";
    default:
        return "name_???";
    }
}

std::string_view getRoar(int index)
{
    switch (index)
    {
    case 0:
        return "rrrrr";
    case 1:
        return "llllll";
    case 2:
        return "wwwww";
    case 3:
        return "mmmmm";
    case 4:
        return "ddddd";
    case 5:
        return "sssss";
    default:
        return "roar_???";
    }
}

Monster generate()
{
    return Monster{static_cast<Monster::MonsterType>(
                       Random::get(0, Monster::maxMonsterType - 1)),
                   getName(Random::get(0, 5)), getRoar(Random::get(0, 6)),
                   Random::get(0, 100)};
}

} // namespace MonsterGenerator

////////////////

int main()
{

    Monster m{MonsterGenerator::generate()};
    m.print();

    return 0;
}
