#include "LeeAlgorithm.h"



bool LeeAlgorithm::isOK(int i, int j)
{
	if (i < 0 || j < 0 || i >= mazeMatrix->size() || j >= mazeMatrix->size())
		return false;
	if (mazeMatrix->at(i).at(j) == 0)
		return false;
	return true;
}

LeeAlgorithm::LeeAlgorithm(Maze* newMaze)
{
	stack = new std::queue<std::pair<int, int>>();
	mazeMatrix = newMaze;

}

void LeeAlgorithm::findShortestPath(std::pair<int,int> startPoint)
{
	int i, j, next_i, next_j;
	mazeMatrix->at(startPoint.first).at(startPoint.second) = 1;
	stack->push(startPoint);

	while (!stack->empty())
	{
		i = stack->front().first;
		j = stack->front().second;
		
		stack->pop();
		for (int k = 0; k < 4; k++)
		{
			next_i = i + dx[k];
			next_j = j + dy[k];

			if (isOK(next_i, next_j) && mazeMatrix->at(next_i).at(next_j) == 1)
			{
				mazeMatrix->at(next_i).at(next_j) =1 + mazeMatrix->at(i).at(j);
				pointsVector.push_back(std::make_pair(next_i, next_j));
				stack->push(std::make_pair(next_i, next_j));
			}
		}
	}
}


void LeeAlgorithm::printMaze()
{
	std::vector<std::vector<int>>::const_iterator itMaze;
	std::vector<int>::const_iterator itVect;

	for (itMaze = mazeMatrix->begin(); itMaze != mazeMatrix->end(); itMaze++)
	{
		for (itVect = (*itMaze).begin(); itVect != (*itMaze).end(); itVect++)
		{
			std::cout << *itVect << " ";
		}
		std::cout << std::endl;
	}

}

void LeeAlgorithm::printVector()
{
	std::vector<std::pair<int, int>>::const_iterator it;
	for (it = pointsVector.begin(); it != pointsVector.end(); it++)
	{
		std::cout << "[" << (*it).first << "," << (*it).second << "]";
		std::cout << std::endl;
	}
}
LeeAlgorithm::~LeeAlgorithm()
{
	delete mazeMatrix;
	delete stack;
}
