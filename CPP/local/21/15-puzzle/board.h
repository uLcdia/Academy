#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <thread>
#include <chrono>
#include "keyInput.h"
#include "point.h"
#include "tile.h"
#include "random.h"

class Board
{
public:
    Board();

    void move(const KeyInput::Action& action);

    void randomize(int moveCount);

    bool isCompleted() const {return m_tiles == m_completedTiles;}

    friend std::ostream& operator<< (std::ostream& out, const Board& source);

private:
    std::vector<std::vector<Tile>> m_tiles;

    std::vector<std::vector<Tile>> m_completedTiles;

    Point m_emptyTilePoint {Point::SIZE - 1, Point::SIZE - 1};

    static constexpr int MOVE_COUNT {100 * Point::SIZE}; // used in randomize(MOVE_COUNT) in Board()
    [[maybe_unused]] static constexpr int CONSTRUCTOR_SLEEP_TIME {1500}; // used in sleep_for() in Board(), millisecond
    [[maybe_unused]] static constexpr int RANDOMIZE_SLEEP_TIME {10}; // used in sleep_for() in randomize(), millisecond

    void initializeTiles();
};


#endif