#include <iostream>
#include "point.h"

Point Point::getAdjacentPoint(const KeyInput::Action& direction) const
{
    // m_point: first = x, second = y ( board.h m_tile[y][x] )
    switch (direction)
    {
    case KeyInput::Action::up:      // emptyTile moves up, return the immediate lower tile point (action up, return down)
        return Point {m_point.first, m_point.second + 1};
    case KeyInput::Action::down:    // emptyTile moves down, return the immediate higher tile point (action down, return up) 
        return Point {m_point.first, m_point.second - 1};
    case KeyInput::Action::left:    // emptyTile moves left, return the immediate right tile point (action left, return right)
        return Point {m_point.first + 1, m_point.second};
    case KeyInput::Action::right:   // emptyTile moves right, return the immediate left tile point (action right, return left)
        return Point {m_point.first - 1, m_point.second};
    default:
        return {-1, -1};
    }
}