#ifndef BOARD_H
#define BOARD_H

#include "constants.h"
#include "convertingFunctions.h"
#include "point.h"
#include "tile.h"
#include "userInput.h"
#include <array>
#include <iosfwd>

// 4x4 grid of tile
// new Board is in solved state
class Board
{
  private:
    std::array<Tile, g_boardSizeSize> m_board{};

    Point m_currentPositionMissingTile{};

  public:
    Board();

    void randomizeBoard();
    bool isInWinningState();

    friend std::ostream& operator<<(std::ostream& out, const Board& board);

    Tile getTileCoordinate(int x, int y);

    void applyDirection(UserInput::Direction currentDirection);
};

#endif
