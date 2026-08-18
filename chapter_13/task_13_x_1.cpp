#include <iostream>
#include <string>
#include <string_view>

enum MonsterType
{
    ogre,
    dragon,
    orc,
    giant_Spider,
    slime
};

struct Monster
{
    MonsterType monsterTyp{ogre};
    std::string name{};
    int health{0};
};

constexpr std::string_view getMonsterName(MonsterType mt)
{
    switch (mt)
    {
    case ogre:
        return "Ogre";
    case dragon:
        return "Dragon";
    case orc:
        return "Orc";
    case giant_Spider:
        return "Giant Spider";
    case slime:
        return "Slim";
    default:
        return "???";
    }
}

std::ostream &operator<<(std::ostream &out, const MonsterType mt)
{
    return out << getMonsterName(mt);
}

std::ostream &operator<<(std::ostream &out, const Monster &m)
{
    return out << "This " << m.monsterTyp << " is named " << m.name
               << " and has " << m.health << " health. \n";
}

int main()
{

    Monster monster1{ogre, "Torge", 145};
    Monster monster2{slime, "Blurp", 23};

    std::cout << monster1;
    std::cout << monster2;
    return 0;
}
