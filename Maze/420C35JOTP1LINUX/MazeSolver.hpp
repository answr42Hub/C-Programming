#ifndef MAZESOLVER_HPP
#define MAZESOLVER_HPP

#include "Maze.hpp"
#include "Window.hpp"
#include "Position.hpp"
#include "Stack.hpp"
// TODO : Inclusions.

class MazeSolver : public Window {
private:
	Maze* maze;
	Stack<Position*>* path;
	Position* pos;
	unsigned char x;
	unsigned char y;
	
	// Mets les dirrections possibles de la position actuelle dans le tableau dir
	void getDir() {
	
		pos->dir[0] = (maze->getSquare(x, y-1) != Square::WALL);//NORD
		pos->dir[1] = (maze->getSquare(x, y+1) != Square::WALL);//SUD
		pos->dir[2] = (maze->getSquare(x+1, y) != Square::WALL);//EST
		pos->dir[3] = (maze->getSquare(x-1, y) != Square::WALL);//OUEST
	}

	// Retourne 0 : Nord, 1 : SUD, 2 : EST, 3: OUEST
	unsigned char getWay() {
		unsigned char ways[3];
		unsigned char count = 0;

		for(unsigned char j = 0; j < 4; j++) {
			if(pos->dir[j]) {
				ways[count] = j;
				count++;
			}
		}

		switch (count) {
			case 1 :
				return ways[0];
			case 2 :
				return ways[rand()%2];
			case 3 :
				return ways[rand()%3];
			default :
				return NULL;
		}
	}

public:
	MazeSolver(Maze* maze) {
		// Instanciations.
		this->maze = maze;
		path = new Stack<Position*>;
		// Trouver l'entree et instancier x et y
		for(unsigned char i = 0; i < 53; i++){
			for(unsigned char j = 0; j < 53; j++) {
				if(maze->getSquare(j, i) == Square::ENTRY) {
					x = j;
					y = i;
					j=53;
					i=53;
				}
			}
		}
	}

	~MazeSolver() {
		// Libérations.
		delete maze;
		delete path;
	}

	void onUpdate() {
		// Avancer d'un pas.
		unsigned char provWay;
		if(path->size()) {
			switch(getWay()) {
				case 0 :// NORD
					path->top()->dir[0] = false; //dans un coin dir : {FTFT}
					y--;
					provWay = 1;
					break;
				case 1 :// SUD
					path->top()->dir[1] = false;
					y++;
					provWay = 0;
					break;
				case 2 :// EST
					path->top()->dir[2] = false;
					x++;
					provWay = 3;
					break;
				case 3 :// OUEST
					path->top()->dir[3] = false;
					x--;
					provWay = 2;
					break;
				default :
					path->pop();
			}
			pos = new Position(x, y);
			getDir();
			pos->dir[provWay] = false;

			path->push(pos);
		}
		else {
			pos = new Position(x, y);
			getDir();
			path->push(pos);
		}
	}
		

	void onRefresh() {
		// Afficher le labyrinthe.
		for(int i = 0; i < 53; i++){
			for(int j = 0; j < 53; j++) {
				drawSquare(maze->getSquare(j, i), j, i);
			}
		}
		// Afficher le chemin parcouru.
		drawSquare(Square::PATH, path->top()->x, path->top()->y);
		if(maze->getSquare(path->top()->x, path->top()->y) == Square::EXIT)
			exit(0);
	}
};

#endif