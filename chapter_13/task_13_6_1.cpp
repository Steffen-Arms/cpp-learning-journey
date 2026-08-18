#include <iostream>
#include <string_view>

enum class Animal
{
    pig,
    chicken,
    cat,
    dog,
    duck,
};

constexpr std::string_view getAnimalName(Animal animal)
{
    using enum Animal;
    switch (animal)
    {
    case pig:
        return "pig";
    case chicken:
        return "chicken";
    case cat:
        return "cat";
    case dog:
        return "dog";
    case duck:
        return "duck";
    default:
        return "???";
    }
}

std::ostream &operator<<(std::ostream &out, Animal animal)
{
    return out << getAnimalName(animal);
}

int printNumberOfLegs(Animal animal)
{
    using enum Animal;
    switch (animal)
    {
    case pig:
    case cat:
    case dog:
        return 4;
    case chicken:
    case duck:
        return 2;
    default:
        return 0;
    }
}

int main()
{
    using enum Animal;
    std::cout << "A " << cat << " has " << printNumberOfLegs(cat) << " legs \n";
    std::cout << "A " << chicken << " has " << printNumberOfLegs(chicken)
              << " legs \n";

    return 0;
}
