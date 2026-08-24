#include <cassert>
#include <iostream>
#include <vector>

namespace names
{

enum animals
{
    chicken,
    dog,
    cat,
    elephant,
    duck,
    snake,
    max_animals,
};

const std::vector<int> animal_list{2, 4, 4, 4, 2, 0};
} // namespace names

int main()
{

    assert(std::size(names::animal_list) == names::max_animals);

    std::cout << "Elephant has " << names::animal_list[names::elephant]
              << " legs.\n";
}
