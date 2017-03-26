#include <iostream>
#include "DataReader.h"
#include "LeeAlgorithm.h"

int main()
{
	std::string filePath = "maze.txt";
	DataReader* tempReader = new DataReader(filePath);
	LeeAlgorithm* tempLeeAlg = new LeeAlgorithm(&tempReader->getMazeMatrix());
	tempLeeAlg->findShortestPath(std::make_pair(4, 2));
	tempLeeAlg->printMaze();
	tempLeeAlg->printVector();

	return 0;
}