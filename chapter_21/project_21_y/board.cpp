#include "board.h"
#include "constants.h"
#include "random.h"
#include "userInput.h"
#include <iostream>

Board::Board() : m_currentPositionMissingTile{g_boardSize - 1, g_boardSize - 1}
{
    for (int i{1}; i < g_boardSizeSize; ++i)
    {
        m_board[toUz(i - 1)] = Tile(i);
    }
    m_board[g_boardSizeSize - 1] = Tile(0);
}

void Board::randomizeBoard()
{
    for (int i{0}; i < g_boardRandomizedIterations; ++i)
    {
        int random{Random::get(0, UserInput::Direction::max_Directions - 1)};
        this->applyDirection(UserInput::Direction(random));
    }
}

bool Board::isInWinningState()
{
    for (int i{0}; i < g_boardSizeSize - 1; ++i)
    {
        if (m_board[toUz(i)].getNum() != i + 1)
        {
            return false;
        }
    }
    return true;
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

// Assume x, y < g_boardSize{4}
Tile Board::getTileCoordinate(int x, int y)
{
    return Board::m_board[toUz(x * g_boardSize + y)];
}

void Board::applyDirection(UserInput::Direction currentDirection)
{

    // check if we can even do the direciton if we are at the corner of the
    // field if we can't apply the direction we do nothing
    if (currentDirection == UserInput::Direction::up)
    {
        if (Board::m_currentPositionMissingTile.getYCoordinate() ==
            g_boardSize - 1)
        {
            std::cout << "Can't move something up.";
            return;
        }
        else
        {
            std::cout << "tile coordinate "
                      << Board::m_currentPositionMissingTile.getYCoordinate();
            // If we move up we need the coordinate down from current tile(0)
            m_board[toUz(m_currentPositionMissingTile.getArrayIndex())] =
                m_board[toUz(m_currentPositionMissingTile.getArrayIndexDown())];

            m_board[toUz(m_currentPositionMissingTile.getArrayIndexDown())] =
                Tile(0);

            m_currentPositionMissingTile.newCoordinates(
                m_currentPositionMissingTile.getArrayIndexDown());
        }
    }

    if (currentDirection == UserInput::Direction::down)
    {
        if (Board::m_currentPositionMissingTile.getYCoordinate() == 0)
        {
            std::cout << "Can't move something down";
            return;
        }
        else
        {
            m_board[toUz(m_currentPositionMissingTile.getArrayIndex())] =
                m_board[toUz(m_currentPositionMissingTile.getArrayIndexUp())];

            m_board[toUz(m_currentPositionMissingTile.getArrayIndexUp())] =
                Tile(0);

            m_currentPositionMissingTile.newCoordinates(
                m_currentPositionMissingTile.getArrayIndexUp());
        }
    }

    if (currentDirection == UserInput::Direction::right)
    {
        if (Board::m_currentPositionMissingTile.getXCoordinate() == 0)
        {
            std::cout << "Can't move something right";
            return;
        }
        else
        {
            // std::cout << " x coordinate: "
            //          << Board::m_currentPositionMissingTile.getXCoordinate()
            //           << '\n';
            m_board[toUz(m_currentPositionMissingTile.getArrayIndex())] =
                m_board[toUz(m_currentPositionMissingTile.getArrayIndexLeft())];

            m_board[toUz(m_currentPositionMissingTile.getArrayIndexLeft())] =
                Tile(0);

            m_currentPositionMissingTile.newCoordinates(
                m_currentPositionMissingTile.getArrayIndexLeft());
        }
    }

    if (currentDirection == UserInput::Direction::left)
    {
        if (Board::m_currentPositionMissingTile.getXCoordinate() >=
            g_boardSize - 1)
        {
            std::cout << "Can't move something left";
            return;
        }
        else
        {
            m_board[toUz(m_currentPositionMissingTile.getArrayIndex())] =
                m_board[toUz(
                    m_currentPositionMissingTile.getArrayIndexRight())];

            m_board[toUz(m_currentPositionMissingTile.getArrayIndexRight())] =
                Tile(0);

            m_currentPositionMissingTile.newCoordinates(
                m_currentPositionMissingTile.getArrayIndexRight());
        }
    }
}
