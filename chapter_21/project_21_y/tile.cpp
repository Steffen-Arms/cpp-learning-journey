#include "tile.h"
#include <iostream>

Tile::Tile(int tileName) : m_tileName{tileName} {}

bool Tile::isEmpty() const
{
    if (m_tileName == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Tile::getNum() const { return m_tileName; }

// implicitly using here the maximum size of the board 4x4
std::ostream& operator<<(std::ostream& out, Tile tile)
{
    if (tile.m_tileName > 9)
    {
        out << ' ' << tile.m_tileName << ' ';
    }
    else if (tile.m_tileName > 0)
    {
        out << "  " << tile.m_tileName << " ";
    }
    else
    {
        out << "    ";
    }
    return out;
}
