#pragma once

#include <map>
#include <vector>
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
	void initialize(int numberOfVertices = 0);
	bool isEdge(int startVertex, int endVertex) const;
	bool isVertex(int vertex) const;
	void addVertex(int vertex);
	void addEdge(int startVertex, int endVertex, int costOfEdge);
	void removeEdge(int startVertex, int endVertex);
	void removeVertex(int vertex);
	void modifyCostOfAnEdge(int startVertex, int endVertex, int newCost);
	int getNumberOfVertices() const;
	int getCostOfAnEdge(int startVertex, int endVertex);
	int getIndegreeOfAVertex(int vertex);
	int getOutdegreeOfAVertex(int vertex);
	int getNumberOfEdges() const;

	vector<int> getAllVertices() const;
	vector<int> getOutBoundVerticesOfAVertex(int vertex);
	vector<int> getInBoundVerticesOfAVertex(int vertex);
	void copyGraph(DirectedGraph& copyOfGraph) const;
	vector<pair<pair<int, int>, int>> getInboundEdgesOfAVertex(int vertex) const;
	vector<pair<pair<int, int>, int>> getOutboundEdgesOfAVertex(int vertex) const;
	vector<pair<pair<int, int>, int>> getAllEdges() const;
};