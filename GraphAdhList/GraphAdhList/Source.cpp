#pragma once
#include <iostream>
#include "DataReader.h"
#include "Graph.h"

int main()
{
	std::string filePath = "test_file.txt";
	DataReader* tempReader = new DataReader(filePath);
	int nodesCount = tempReader->getNodesCount();
	Graph* graph = new Graph(nodesCount);
	std::vector<std::pair<int, int>> tempDataVector = tempReader->getEdgeList();
	std::vector<std::pair<int, int>>::const_iterator it;

	for (it = tempDataVector.begin(); it != tempDataVector.end(); it++)
	{
		graph->addEdge(it->first, it->second);
	}
	graph->printGraph();
	return 0;
}