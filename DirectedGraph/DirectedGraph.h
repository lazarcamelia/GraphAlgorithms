#pragma once

#include <map>
#include <vector>
//#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

class DirectedGraph {
private:
	map<int, vector<int>> inboundNeighbours;
	map<int, vector<int>> outboundNeighbours;
	map<pair<int, int>, int> costOfEdge;

public:
	//constructor
	DirectedGraph(int numberOfvertices = 0);
	void clearAll();
	bool isEdge(int startVertex, int endVertex);
	bool isVertex(int vertex);
	void addVertex(int vertex);
	void addEdge(int startVertex, int endVertex, int costOfEdge);
	void removeEdge(int startVertex, int endVertex);
	void removeVertex(int vertex);
	void modifyCostOfAnEdge(int startVertex, int endVertex, int newCost);
	int getNumberOfVertices();
	int getCostOfAnEdge(int startVertex, int endVertex);
	int getIndegreeOfAVertex(int vertex);
	int getOutdegreeOfAVertex(int vertex);
	int getNumberOfEdges();

	vector<int> getAllVertices();
	void copyGraph(DirectedGraph& copyOfGraph);
	vector<pair<pair<int, int>, int>> getInboundEdgesOfAVertex(int vertex);
	vector<pair<pair<int, int>, int>> getOutboundEdgesOfAVertex(int vertex);
	vector<pair<pair<int, int>, int>> getAllEdges();
};

void createRandomGraph(DirectedGraph& randomGeneratedGraph,  int numberOfVertices = 0, int numberOfEdges = 0);
void writeToFile(DirectedGraph graphToBeReadToFile, string filename);
void readFromFile(DirectedGraph& directedGraph, string filename);