#include "Random.h"
#include <algorithm> // std::find, std::min_element
#include <cmath>     // std::abs
#include <cstddef>   // std::size_t
#include <iostream>
#include <vector>

using Numbers = std::vector<int>;

namespace config
{
constexpr int multiplierMin{2};
constexpr int multiplierMax{6};
} // namespace config

constexpr std::size_t toUZ(std::integral auto value)
{
    return static_cast<std::size_t>(value);
}

Numbers generateNumbers(int start, int count, int multiplier)
{
    Numbers numbers(static_cast<std::size_t>(count));

    std::ranges::generate(numbers,
                          [start, multiplier, i = 0]() mutable
                          {
                              int v = start + i++;
                              return v * v * multiplier;
                          });

    return numbers;
}

Numbers setupGame()
{
    int start{};
    std::cout << "Start where?";
    std::cin >> start;

    int count{};
    std::cout << "How many?";
    std::cin >> count;

    int multiplier{Random::get(config::multiplierMin, config::multiplierMax)};

    std::cout << "I generated " << count
              << " square numbers. Do you know what each number is after "
                 "multiplying it by "
              << multiplier << " ? \n";

    return generateNumbers(start, count, multiplier);
}

int getUserGuess()
{
    int guess{};
    std::cout << "> ";
    std::cin >> guess;

    return guess;
}

bool findAndRemove(Numbers numbers, int guess)
{

    auto found{std::find(numbers.begin(), numbers.end(), guess)};

    if (found == numbers.end())
    {
        return false;
    }
    numbers.erase(found);
    return true;
}

int findClosestNumber(const Numbers numbers, int guess)
{
    return *std::min_element(
        numbers.begin(), numbers.end(), [=](int a, int b)
        { return std::abs(a - guess) < std::abs(b - guess); });
}
void printFailure(const Numbers& numbers, int guess)
{

    int closest{findClosestNumber(numbers, guess)};

    std::cout << guess << " is wrong!\n";
    std::cout << "Try " << closest << " next time.\n";
}

void printSuccess(const Numbers& numbers)
{
    std::cout << "Nice! ";
    if (numbers.size() == 0)
    {
        std::cout << "You found all numbers, good job!\n";
    }
    else
    {
        std::cout << numbers.size() << " numbers left. \n";
    }
}

int main()
{
    Numbers numbers{setupGame()};

    while (true)
    {
        int guess{getUserGuess()};

        if (!findAndRemove(numbers, guess))
        {
            printFailure(numbers, guess);
            break;
        }
        printSuccess(numbers);
        if (numbers.size() == 0)
        {
            break;
        }
    }
}
