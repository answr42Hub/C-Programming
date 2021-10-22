#ifndef MAZESOLVER_HPP
#define MAZESOLVER_HPP

#include "Maze.hpp"
#include "Window.hpp"
// TODO : Inclusions.

class MazeSolver : public Window {
private:
	Maze* maze;
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
		// TODO : Afficher le chemin parcouru.
	}
};

#endif