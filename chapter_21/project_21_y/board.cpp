#include "board.h"
#include <iostream>

constexpr int g_consoleLines{25};

Board::Board()
{
    for (int i{1}; i < g_boardSizeSize; ++i)
    {
        m_board[toUz(i - 1)] = Tile(i);
    }
    m_board[g_boardSizeSize - 1] = Tile(0);
}

std::ostream& operator<<(std::ostream& out, const Board& board)
{
    for (int i{0}; i < g_consoleLines; ++i)
    {
        std::cout << '\n';
    }

    for (int i{0}; i < g_boardSize; ++i)
    {
        for (int j{0}; j < g_boardSize; ++j)
        {
            out << board.m_board[toUz(i * g_boardSize + j)];
        }
        out << '\n';
    }
    return out;
}
