#ifndef MONSTER_H
#define MONSETR_H

#include "creature.h"
#include "random.h"

class Monster : public Creature
{
  public:
    enum Type
    {
        dragon,
        orc,
        slime,
        max_types,
    };

  private:
    static inline Creature monsterData[]{Creature{"dragon", 'D', 20, 4, 100},
                                         Creature{"orc", 'o', 4, 2, 25},
                                         Creature{"slime", 's', 1, 1, 10}};

    static_assert(std::size(monsterData) == Type::max_types);

  public:
    Monster(Type monsterType) : Creature{monsterData[monsterType]} {}

    static Monster getRandomMonster()
    {
        int randomInt{Random::get(0, Type::max_types - 1)};
        return Monster(static_cast<Type>(randomInt));
    }
};

#endif
