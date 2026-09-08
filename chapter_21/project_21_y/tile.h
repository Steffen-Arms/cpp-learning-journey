#ifndef TILE_H
#define TILE_H

#include <iosfwd>

class Tile
{
  private:
    int m_tileName{};

  public:
    Tile() = default;
    explicit Tile(int tileName);

    friend std::ostream& operator<<(std::ostream& out, Tile tile);

    bool isEmpty() const;

    int getNum() const;
};

#endif
