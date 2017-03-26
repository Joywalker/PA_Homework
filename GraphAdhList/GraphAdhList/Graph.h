#pragma once
#include <iostream>	
#include <vector>
#include <string>

class Graph
{
	typedef std::vector<std::vector<int>> AdjList;
private:
	void initGraph(int lv_nbNodes);
	void printLine(std::vector<std::vector<int>>::const_iterator iter);
	bool isOK(int source);
	int nbOfNodes;
	int nbEdges;
	Graph::AdjList *nodesList;
public:
	Graph();
	Graph(int lv_nbNodes);
	void addEdge(int source, int destination);
	void printGraph();
	int getNbNodes() const { return nbOfNodes; }
	int getNbEdges() const { return nbEdges; }
	~Graph();
};

