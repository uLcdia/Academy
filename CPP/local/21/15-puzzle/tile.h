#ifndef TILE_H
#define TILE_H

#include <iostream>
#include "point.h"

class Tile
{
public:
    Tile () = default;
    
    explicit Tile (int num)
        : m_num {num}
    {}

    friend std::ostream& operator<<(std::ostream& out, Tile source);
    friend bool operator== (const Tile& lhs, const Tile& rhs) {return lhs.m_num == rhs.m_num;}

    bool isEmpty() const {return m_num == 0;}

    int getNum() const {return m_num;}

private:
    int m_num {};
    Point m_point {};
};

#endif