#ifndef USERINPUT_H
#define USERINPUT_H

#include <array>
#include <string_view>

namespace UserInput
{

enum Direction
{
    up,
    down,
    right,
    left,
    quit,
    invalidInput,
    max_Directions,
};

using namespace std::string_view_literals;
constexpr std::array directionName{"up"sv,   "down"sv, "right"sv,
                                   "left"sv, "quit"sv, "invalidInput"sv};
static_assert(std::size(directionName) == Direction::max_Directions);

void ignoreLine();

// returns true if extraction failed, false otherwise
bool clearFailedExtraction();

Direction charToDirection(char userInput);

Direction getUserInput();
} // namespace UserInput

#endif
