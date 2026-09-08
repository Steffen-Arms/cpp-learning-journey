#include "board.h"
#include "tile.h"
#include "userInput.h"
#include <iostream>

int main()
{
    Board board{};
    std::cout << board;

    UserInput::Direction currentDirection{};

    while (true)
    {
        currentDirection = UserInput::getUserInput();
        if (currentDirection == UserInput::quit)
        {
            std::cout << "\n\nBye!\n\n";
            break;
        }
        std::cout << UserInput::directionName[currentDirection] << '\n';
    }

    return 0;
}
