#include "Application.hpp"
#include "MazeSolver.hpp"

int main(int argc, char* argv[]) {
	Application::getInstance()->addWindow(new MazeSolver(new Maze(3)));
	Application::getInstance()->start();

	return 0;
}