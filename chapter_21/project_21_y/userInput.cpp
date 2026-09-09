#include "userInput.h"
#include "random.h"
#include <cstdlib>
#include <iostream>
#include <limits>

namespace UserInput
{

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

        return true;
    }

    return false;
}

Direction charToDirection(char userInput)
{
    switch (userInput)
    {
    case 'w':
        return Direction::up;
    case 'a':
        return Direction::left;
    case 's':
        return Direction::down;
    case 'd':
        return Direction::right;
    case 'q':
        return Direction::quit;
    default:
        return Direction::invalidInput;
    }
}

Direction getUserInput()
{
    while (true)
    {
        std::cout << "Enter a command: ";
        char userInput{};
        std::cin >> userInput;
        if (clearFailedExtraction())
        {
            std::cout << "Ooops, invalid input \n";
            continue;
        }
        ignoreLine();
        Direction userDirection{charToDirection(userInput)};
        if (!(userDirection == Direction::invalidInput))
        {
            return userDirection;
        }
        else
        {
            std::cout << "Sry, this is not a valid command. Try again \n";
        }
    }
}

Direction getRandomDirection()
{
    return static_cast<Direction>(
        Random::get(0, Direction::max_Directions - 1));
}
} // namespace UserInput
