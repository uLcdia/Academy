#include "tile.h"

std::ostream& operator<<(std::ostream& out, Tile source)
{
    if (source.m_num > 9) // if two digit number
    {
        out << " " << source.m_num << " ";
    }
    else if (source.m_num > 0) // if one digit number
    {
        out << "  " << source.m_num << " ";
    }
    else if (source.m_num == 0) // if empty spot
    {
        out << "    ";
    }
    return out;
}