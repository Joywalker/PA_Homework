#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
class DataReader
{
	typedef std::vector<std::vector<int>> Maze;
private :
	const std::string filePath;
	Maze* mazeMatrix;
	void readData(const std::string lv_filePath);
	void storeInMaze(std::string lineToStore);
	bool isNumber(const char& value);

public:
	DataReader(const std::string lv_filePath);
	Maze& getMazeMatrix() const { return *mazeMatrix; }
	~DataReader();
};

