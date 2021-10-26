#include <cstdlib>

class Position {
    private:
        unsigned char x, y;
        bool* dir;
    
    public:
        Position(unsigned char x, unsigned char y, bool dir[4]) {
            this->x = x;
            this->y = y;
            this->dir = dir;
    }

    unsigned char getX() {return x;}
    unsigned char getY() {return y;}
    bool* getDir() {return dir;}
};