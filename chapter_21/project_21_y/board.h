#ifndef BOARD_H
#define BOARD_H

#include "tile.h"
#include <array>
#include <iosfwd>

constexpr int g_boardSize{4};
constexpr int g_boardSizeSize{g_boardSize * g_boardSize};

constexpr std::size_t toUz(int value)
{
    return static_cast<std::size_t>(value);
}

// 4x4 grid of tile
// new Board is in solved state
class Board
{
  private:
    std::array<Tile, g_boardSizeSize> m_board{};

  public:
    Board();

    friend std::ostream& operator<<(std::ostream& out, const Board& board);
};

#endif
