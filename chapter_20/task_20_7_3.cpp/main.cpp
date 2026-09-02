#include "Random.h"
#include <algorithm>
#include <iostream>
#include <vector>

static const int MinRandomNumber{2};
static const int MaxRandomNumber{4};

int main()
{
    std::cout << "Welcome to a very fun game \n";
    std::cout << "Start where? ";
    std::size_t startNumber{};
    std::cin >> startNumber;

    std::cout << "How many? ";
    std::size_t intervallSize{};
    std::cin >> intervallSize;
    std::cout << '\n';

    int randomNumber{Random::get(MinRandomNumber, MaxRandomNumber)};

    auto generteVector{[](std::size_t startNumber, std::size_t intervallSize,
                          int randomNumber) -> std::vector<std::size_t>
                       {
                           std::vector<std::size_t> newVector(intervallSize);
                           for (std::size_t i{0}; i < intervallSize; ++i)
                           {
                               newVector[i] =
                                   (startNumber + i) *
                                   static_cast<std::size_t>(randomNumber);
                           }
                           return newVector;
                       }};
    std::vector<std::size_t> secretNumbers{
        generteVector(startNumber, intervallSize, randomNumber)};

    std::cout << "I generated " << intervallSize
              << " square numbers. Do you know what each number is after "
                 "multiplying it by "
              << randomNumber << '\n';

    std::size_t numbersLeft{intervallSize};

    // print vector
    std::cout << "This is the generated vector: \n";
    for (std::size_t i{0}; i < secretNumbers.size(); ++i)
    {
        std::cout << secretNumbers[i] << " ";
    }
    std::cout << '\n';

    while (true)
    {
        int userInput{};
        std::cin >> userInput;
        std::vector<std::size_t>::iterator iterator{
            std::find(secretNumbers.begin(), secretNumbers.end(), userInput)};

        if (iterator == secretNumbers.end())
        {
            auto nearestCorrectNumber = std::min_element(
                secretNumbers.begin(), secretNumbers.end(),
                [userInput](std::size_t a, std::size_t b) -> bool
                {
                    return std::abs(static_cast<int>(a) - userInput) <
                           std::abs(static_cast<int>(b) - userInput);
                });
            std::cout << userInput << " is wrong! Try " << *nearestCorrectNumber
                      << " next time. \n";
        }
        else
        {
            --numbersLeft;
            std::cout << "Nice! " << numbersLeft << " number(s) left.";
            secretNumbers.erase(iterator);
        }

        if (secretNumbers.size() == 0)
        {
            std::cout << "You did it champ! \n";
            break;
        }
    }
}
