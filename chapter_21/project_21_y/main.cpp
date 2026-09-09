#include "board.h"
#include "tile.h"
#include "userInput.h"
#include <iostream>

int main()
{
    Board board{};
    board.randomizeBoard();
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
        board.applyDirection(currentDirection);

        std::cout << board;

        if (board.isInWinningState())
        {
            std::cout << "You did it champ! \n";
            break;
        }

        // std::cout << "Random: " << UserInput::getRandomDirection() << '\n';
    }

    return 0;
}
