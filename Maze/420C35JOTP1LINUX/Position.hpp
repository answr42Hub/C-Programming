#include <cstdlib>
#include "Maze.hpp"

class Position {
public:
    unsigned char x, y;
    bool dir[4];

    Position(unsigned char x, unsigned char y) {
        this->x = x;
        this->y = y;
        dir[0] = false;
        dir[1] = false;
        dir[2] = false;
        dir[3] = false;
    }

};