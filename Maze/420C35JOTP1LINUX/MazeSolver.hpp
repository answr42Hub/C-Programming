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
	Stack<Position>* path;
	// TODO : Déclarations.

public:
	MazeSolver(Maze* maze) {
		this->maze = maze;
		// TODO : Instanciations.
	}

	~MazeSolver() {
		// TODO : Libérations.
		delete maze;
	}

	void onUpdate() {
		// TODO : Avancer d'un pas.

	}

	void onRefresh() {
		// TODO : Afficher le labyrinthe.
		for(int i = 0; i < 53; i++){
			for(int j = 0; j < 53; j++) {
				Window::drawSquare(maze->getSquare(j, i), j, i);
			}
		}
		// TODO : Afficher le chemin parcouru.
		onUpdate();
	}
};

#endif