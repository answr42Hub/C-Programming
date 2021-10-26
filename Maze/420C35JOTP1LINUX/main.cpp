#include "Application.hpp"
#include "MazeSolver.hpp"
#include "Maze.hpp"
#include "Stack.hpp"
#include "Position.hpp"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	Application::getInstance()->addWindow(new MazeSolver(new Maze(1)));
	Application::getInstance()->start();


	return 0;
}