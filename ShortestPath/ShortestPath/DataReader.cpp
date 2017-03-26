#include "DataReader.h"
void DataReader::readData(const std::string lv_filePath)
{
	std::ifstream myFile(lv_filePath);
	std::string line;
	mazeMatrix = new Maze();
	if (myFile.is_open())
	{
		while (std::getline(myFile,line))
		{
			storeInMaze(line);
		}
	}
}
void DataReader::storeInMaze(std::string lineToStore)
{
	std::vector<int> *tempRow = new std::vector<int>();
	std::stringstream sstream(lineToStore);
	for (int i = 0; i < lineToStore.length(); i++)
	{
		isNumber(lineToStore[i]) ? tempRow->push_back((int)(lineToStore[i]-48)) : false ;
	}
	mazeMatrix->push_back(*tempRow);
}

bool DataReader::isNumber(const char & value)
{
	return ((value >= '0') && (value <= '9'));
}

DataReader::DataReader(const std::string lv_filePath)
{
	readData(lv_filePath);
}

DataReader::~DataReader()
{
	delete mazeMatrix;
}
