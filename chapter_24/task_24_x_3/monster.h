#ifndef MONSTER_H
#define MONSETR_H

#include "creature.h"

class Monster : public Creature
{

  private:
    static inline Creature monsterData[]{Creature{"dragon", 'D', 20, 4, 100},
                                         Creature{"orc", 'o', 4, 2, 25},
                                         Creature{"slime", 's', 1, 1, 10}};

  public:
    enum Type
    {
        dragon,
        orc,
        slime,
        max_types,
    };

    Monster(Type monsterType) : Creature{monsterData[monsterType]} {}
};

#endif
