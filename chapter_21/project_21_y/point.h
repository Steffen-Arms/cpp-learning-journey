
#ifndef POINT_H
#define POINT_H

// #include "board.h"
// extern int g_boardSize;
#include <iostream>

class Point
{
  private:
    int xCoordinate{};
    int yCoordinate{};

  public:
    Point() = default;
    Point(int x, int y) : xCoordinate{x}, yCoordinate{y} {}

    int getXCoordinate() { return xCoordinate; }

    int getYCoordinate() { return yCoordinate; }

    int getArrayIndex() { return (yCoordinate * g_boardSize + xCoordinate); }

    int getArrayIndexDown()
    {
        return ((yCoordinate + 1) * g_boardSize + xCoordinate);
    }

    int getArrayIndexUp()
    {
        return ((yCoordinate - 1) * g_boardSize + xCoordinate);
    }

    int getArrayIndexRight()
    {
        return (yCoordinate * g_boardSize + xCoordinate + 1);
    }

    int getArrayIndexLeft()
    {
        return (yCoordinate * g_boardSize + xCoordinate - 1);
    }

    void newCoordinates(int arrayIndex)
    {
        // std::cout << "newCoordinates, index " << arrayIndex << '\n';
        yCoordinate = arrayIndex / g_boardSize;
        xCoordinate = arrayIndex % g_boardSize;

        // std::cout << "new x: " << xCoordinate << '\n';
        // std::cout << "new y: " << yCoordinate << '\n';
    }
};

#endif
