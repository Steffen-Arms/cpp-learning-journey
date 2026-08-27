#include <array>
#include <iostream>
#include <limits>
#include <string>
#include <string_view>

namespace Animal
{

enum AnimalNames
{
    chicken,
    dog,
    cat,
    elephant,
    duck,
    snake,
    max_animal,
};

struct Data
{
    AnimalNames name{};
    int numberOfLegs{};
    std::string_view sound{};
};

using namespace std::string_view_literals;
constexpr std::array<Animal::Data, max_animal> animalArray{{
    {chicken, 2, "ticktick"sv},
    {dog, 4, "wuffwuff"sv},
    {cat, 4, "miaumiau"sv},
    {elephant, 4, "toroooo"sv},
    {duck, 2, "quarckquarck"sv},
    {snake, 0, "ssssss"sv},
}};

constexpr std::array<std::string_view, max_animal> animalNameStringArray{
    "chicken", "dog", "cat", "elephant", "duck", "snake"};

static_assert(std::size(animalNameStringArray) == max_animal);
static_assert(std::size(animalArray) == max_animal);
} // namespace Animal

constexpr std::string_view getAnimalName(Animal::AnimalNames animalName)
{
    return Animal::animalNameStringArray[static_cast<std::size_t>(animalName)];
}

std::ostream& operator<<(std::ostream& out, Animal::Data animalData)
{
    return out << "A " << getAnimalName(animalData.name) << " has "
               << animalData.numberOfLegs << " legs and says "
               << animalData.sound << ".";
}

std::istream& operator>>(std::istream& in, Animal::AnimalNames& userAnimalName)
{
    std::string input{};
    std::getline(in >> std::ws, input); // std::ws delete following whitespaces

    for (std::size_t index = 0; index < Animal::max_animal; ++index)
    {
        if (input == Animal::animalNameStringArray[index])
        {
            userAnimalName = static_cast<Animal::AnimalNames>(index);
            return in;
        }
    }
    in.setstate(std::ios_base::failbit);
    return in;
}

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// returns true if extraction failed, false otherwise
bool clearFailedExtraction()
{
    // Check for failed extraction
    if (!std::cin) // If the previous extraction failed
    {
        if (std::cin.eof()) // If the stream was closed
        {
            std::exit(0); // Shut down the program now
        }

        // Let's handle the failure
        std::cin.clear(); // Put us back in 'normal' operation mode
        ignoreLine();     // And remove the bad input
        std::cout << '\n';

        return true;
    }

    return false;
}

int main()
{
    bool falseAnimal{false};

    while (!falseAnimal)
    {
        std::cout << "Enter an animal: ";
        Animal::AnimalNames userAnimal{};
        std::cin >> userAnimal;

        if (clearFailedExtraction())
        {
            std::cout << "That animal couldn't be found. \n";
        }
        else
        {
            falseAnimal = true;

            std::cout << Animal::animalArray[userAnimal];
            std::cout << '\n';
            std::cout << '\n';

            std::cout << "Here is the data for the rest of the animals: \n";
            for (int i{0}; i < Animal::max_animal; ++i)
            {
                if (userAnimal != static_cast<Animal::AnimalNames>(i))
                {
                    std::cout
                        << Animal::animalArray[static_cast<std::size_t>(i)];

                    std::cout << '\n';
                }
            }
        }
    }
}
