#include "Graph.h"
Graph::Graph()
{
	initGraph(0);
}

Graph::Graph(int lv_nbNodes)
{
	initGraph(lv_nbNodes);
}

void Graph::initGraph(int lv_nbNodes)
{
	nbOfNodes = lv_nbNodes;
	std::vector<int>* newLine = new std::vector<int>();
	nodesList = new AdjList();
	for (int i = 0; i < nbOfNodes; i++)
	{
		nodesList->push_back(*newLine);
	}
}

bool Graph::isOK(int nodeToAdd)
{
	(nodeToAdd < 0) || (nodeToAdd >= nbOfNodes) ? throw std::exception("Not in between 0,",nbOfNodes) : false;
}

void Graph::addEdge(int source, int destination)
{
	bool isBondOK = false;
	isOK(source) && isOK(destination) ? isBondOK = true : isBondOK = false;
	if (isBondOK)
	{
		this->nbEdges++;
		nodesList->at(source).emplace_back(destination);
		nodesList->at(destination).emplace_back(source);
	}
}

void Graph::printLine(std::vector<std::vector<int>>::const_iterator iter)
{
	std::vector<int>::const_iterator it;
	for (it = iter->begin(); it != iter->end(); it++)
	{
		std::cout << "->" << *it;
	}
	std::cout << std::endl;
}
void Graph::printGraph()
{
	AdjList::const_iterator it;
	int currentNode = 0;
	for (it = nodesList->begin(); it != nodesList->end(); it++)
	{
		if(it->size()!=0)
		{ 
			std::cout << "Adjacency list of vertex " << currentNode << std::endl;
			std::cout << "HEAD";
			printLine(it);
			currentNode++;
			std::cout << std::endl;
		}
	}
}

Graph::~Graph()
{
	delete nodesList;
}
