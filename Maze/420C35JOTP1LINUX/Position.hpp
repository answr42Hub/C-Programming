#include <cstdlib>

class Position {
    private:
        char x, y;
        bool* dir;
    
    public:
        Position(char x, char y, bool dir[4]) {
            this->x = x;
            this->y = y;
            this->dir = dir;
    }

    char getX() {return x;}
    char getY() {return y;}
    bool* getDir() {return dir;}
};