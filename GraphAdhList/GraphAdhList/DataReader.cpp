#include "DataReader.h"

void DataReader::getDataFromFile(std::string lv_filePath)
{
	std::ifstream myFile(lv_filePath);
	edgeList = new edgesList();
	int nodesCount;
	int source, destination;
	if (myFile.is_open())
	{
		myFile >> nodesCount;
		while (!myFile.eof())
		{
			myFile >> source >> destination;
			edgeList->push_back(std::make_pair(source, destination));
		}
	}
	this->nodesCount = nodesCount;
}

DataReader::DataReader(const std::string lv_FilePath)
{
	 getDataFromFile(lv_FilePath);
}

DataReader::~DataReader()
{
	delete &edgeList;
}
