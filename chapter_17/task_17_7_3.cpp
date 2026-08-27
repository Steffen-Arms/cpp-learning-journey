#include <iostream>
#include <iterator>

namespace Data
{
constexpr int perfectSquares[]{0, 1, 4, 9};
}

bool isInArray(int input)
{
    for (const auto& e : Data::perfectSquares)
    {
        if (e == input)
        {
            return true;
        }
    }
    return false;
}

int main()
{

    while (true)
    {
        std::cout << "Enter a single digit integer, or -1 to quit:";
        int userInput{};
        std::cin >> userInput;

        if (userInput == -1)
        {
            break;
        }
        else
        {
            if (isInArray(userInput))
            {
                std::cout << userInput << " is a perfect square \n";
            }
            else
            {
                std::cout << userInput << " is not a perfect square \n";
            }
        }
    }
    std::cout << "Bey";
}
