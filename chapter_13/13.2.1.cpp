#include <iostream>

namespace MonsterType
{
enum MonsterType
{
    orc,
    goblinc,
    troll,
    ogre,
    skeleton,
};

}

int main()
{

    MonsterType::MonsterType monster{MonsterType::troll};
    if (monster == MonsterType::troll)
    {
        std::cout << "Its a troll";
    }
    return 0;
}
