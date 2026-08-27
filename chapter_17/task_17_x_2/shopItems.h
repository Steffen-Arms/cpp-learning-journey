#include <array>
#include <string_view>

namespace Potion
{
enum Type
{
    healing,
    mana,
    speed,
    invisibility,
    max_potions,
};

inline constexpr std::array potionTypesArray{healing, mana, speed,
                                             invisibility};

inline constexpr std::array potionNamesArray{
    "healing",
    "mana",
    "speed",
    "invisibility",
};

inline constexpr std::array<int, max_potions> potionCostArray{20, 30, 12, 50};
;

static_assert(std::size(potionTypesArray) == max_potions);
static_assert(std::size(potionNamesArray) == max_potions);
static_assert(std::size(potionCostArray) == max_potions);
}; // namespace Potion
