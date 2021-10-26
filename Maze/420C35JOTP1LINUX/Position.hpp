#include <cstdlib>

class Position {
    private:
        char x, y;
        bool dir[4];
    
    public:
        Position(char x, char y, bool dir[4]) {
            this->x = x;
            this->y = y;
            this->dir[4] = dir[4];
    }
};