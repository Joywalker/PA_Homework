#pragma once
#include <iostream>
#include <vector>
#include <queue>
class LeeAlgorithm
{
	typedef std::vector<std::vector<int>> Maze;

private:
	Maze* mazeMatrix;
	std::queue<std::pair<int, int>>* stack;
	std::vector<std::pair<int, int>> pointsVector;
	bool isOK(int i, int j);
	const int dx[4] = { 0,0,1,-1 };
	const int dy[4] = { 1,-1,0,0 };
public:
	LeeAlgorithm(Maze* newMaze);
	void findShortestPath(std::pair<int, int> startPoint);
	Maze& getMazeMatrix() const { return *mazeMatrix; }
	std::vector<std::pair<int, int>> getPointsVector() { return pointsVector; }
	void printMaze();
	void printVector();
	~LeeAlgorithm();
};

