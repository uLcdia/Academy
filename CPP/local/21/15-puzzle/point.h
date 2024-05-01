#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "keyInput.h"

class Point
{
public:
    static constexpr int SIZE = 4;

    Point(int x = 0, int y = 0)
        : m_point {x, y}
    {}

    Point getAdjacentPoint(const KeyInput::Action& direction) const;

    bool isValid() const
    {return (m_point.first >= 0)   && (m_point.second >= 0)     // top/left edge
        &&  (m_point.first < SIZE) && (m_point.second < SIZE);} // bottom/right edge

    int getX() const {return m_point.first;}
    int getY() const {return m_point.second;}

    friend bool operator== (const Point& lhs, const Point& rhs) {return lhs.m_point == rhs.m_point;}
    friend bool operator!= (const Point& lhs, const Point& rhs) {return lhs.m_point != rhs.m_point;}

private:
    std::pair<int, int> m_point {}; // first = x, second = y ( board.h m_tile[y][x] )
};


#endif