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

	// Mets les dirrections possibles de la position actuelle dans le tableau dir
	void getDir() {
		path->top()->dir[0] = (maze->getSquare(path->top()->x, path->top()->y-1) != Square::WALL);//NORD
		path->top()->dir[1] = (maze->getSquare(path->top()->x, path->top()->y+1) != Square::WALL);//SUD
		path->top()->dir[2] = (maze->getSquare(path->top()->x+1, path->top()->y) != Square::WALL);//EST
		path->top()->dir[3] = (maze->getSquare(path->top()->x-1, path->top()->y) != Square::WALL);//OUEST
	}

	// Retourne 0 : Nord, 1 : SUD, 2 : EST, 3: OUEST
	unsigned char getWay() {
		unsigned char count = 0;
		for(unsigned char i = 0; i < 4; i++) {
			if(path->top()->dir[i])
				count++;
		}

		if(!count)
			return 4;

		else if(count > 1) {
			unsigned char randWay;
			do
				randWay = rand()%4;
			while (!path->top()->dir[randWay]);
			return randWay;
		}
		else {
			for(unsigned char i = 0; i < 4; i++) {
				if(path->top()->dir[i])
					return i;
			}
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
					path->push(new Position(j, i));
					j=53;
					i=53;
				}
			}
		}
		getDir();
	}

	~MazeSolver() {
		// Libérations.
		delete maze;
		while(path->size()) {
			delete path->top();
			path->pop();
		}
		delete path;
	}

	void onUpdate() {
		if(maze->getSquare(path->top()->x, path->top()->y) == Square::EXIT)
			return;
		// Avancer d'un pas.
		unsigned char provWay;
		switch(getWay()) {
			case 0 :// NORD
				path->top()->dir[0] = false;
				path->push(new Position(path->top()->x, path->top()->y-1));
				provWay = 1;
				break;
			case 1 :// SUD
				path->top()->dir[1] = false;
				path->push(new Position(path->top()->x, path->top()->y+1));
				provWay = 0;
				break;
			case 2 :// EST
				path->top()->dir[2] = false;
				path->push(new Position(path->top()->x+1, path->top()->y));
				provWay = 3;
				break;
			case 3 :// OUEST
				path->top()->dir[3] = false;
				path->push(new Position(path->top()->x-1, path->top()->y));
				provWay = 2;
				break;
			default :
				delete path->top();
				path->pop();
				return;
		}
		getDir();
		path->top()->dir[provWay] = false;
		
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
	}
};

#endif