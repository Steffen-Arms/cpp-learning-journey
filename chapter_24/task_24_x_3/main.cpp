#include "creature.h"
#include "monster.h"
#include "player.h"
#include <iostream>
#include <string>

int main()
{
    Monster m{Monster::Type::orc};
    std::cout << "A " << m.getName() << " (" << m.getSymbol()
              << ") was created.\n";

    return 0;
}
