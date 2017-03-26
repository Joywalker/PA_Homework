#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
class DataReader
{
	typedef std::vector<std::pair<int, int>> edgesList;
private:
	const std::string filePath;
	int nodesCount;
	edgesList* edgeList;
    void getDataFromFile(const std::string lv_filePath);

public:
	DataReader(const std::string lv_FilePath);
	edgesList& getEdgeList() const { return *edgeList; }
	int getNodesCount() const { return nodesCount; }
	~DataReader();
};

