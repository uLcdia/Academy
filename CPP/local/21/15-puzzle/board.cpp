#include "board.h"

Board::Board()
{
    initializeTiles();
    std::cout << *this;

    std::this_thread::sleep_for(std::chrono::milliseconds(CONSTRUCTOR_SLEEP_TIME));

    randomize(MOVE_COUNT);
}

void Board::move(const KeyInput::Action& action)
{
    Point point {m_emptyTilePoint};
    Point adjacentPoint {point.getAdjacentPoint(action)};

    if (adjacentPoint.isValid())
    {
        std::swap(m_tiles[point.getY()][point.getX()], m_tiles[adjacentPoint.getY()][adjacentPoint.getX()]);
        point = adjacentPoint;
        adjacentPoint = point.getAdjacentPoint(action);
        m_emptyTilePoint = point;
    }
}

void Board::randomize(int moveCount)
{
    KeyInput::Action action {};

    for (int i {0}; i < moveCount; ++i)
    {
        action = static_cast<KeyInput::Action>(Random::get(4));
        move(action);
        // std::cout << *this;
        // std::this_thread::sleep_for(std::chrono::milliseconds(RANDOMIZE_SLEEP_TIME));
    }
}

std::ostream& operator<< (std::ostream& out, const Board& source)
{
    system("cls");

    for (auto i : source.m_tiles)
    {
        for (auto j : i)
        {
            out << j;
        }
        out << '\n';
    }

    return out;
}

void Board::initializeTiles()
{
    m_tiles.resize(Point::SIZE, std::vector<Tile>(Point::SIZE));
    m_completedTiles.resize(Point::SIZE, std::vector<Tile>(Point::SIZE));

    int count = 1;
    for (int i = 0; i < Point::SIZE; ++i)
    {
        for (int j = 0; j < Point::SIZE; ++j)
        {
            if (count < Point::SIZE * Point::SIZE)
            {
                m_tiles[i][j] = Tile {count};
                m_completedTiles[i][j] = Tile {count};
                ++count;
            }
            else
            {
                m_tiles[i][j] = Tile {0};
                m_completedTiles[i][j] = Tile {0};
            }
        }
    }
}