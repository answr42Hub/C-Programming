#include "Application.hpp"
#include "MazeSolver.hpp"
#include "Stack.hpp"
#include "Position.hpp"

int main(int argc, char* argv[]) {
	Application::getInstance()->addWindow(new MazeSolver(new Maze(3)));
	Application::getInstance()->start();

	return 0;
}