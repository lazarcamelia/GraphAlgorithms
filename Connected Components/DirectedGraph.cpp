#include "DirectedGraph.h"

DirectedGraph::DirectedGraph(int noOfVertices) {
	for (int i = 0; i < noOfVertices; i++) {
		this->inboundNeighbours[i] = vector<int>();
		this->outboundNeighbours[i] = vector<int>();
	}
}

void DirectedGraph::clearAll() {
	this->inboundNeighbours.clear();
	this->outboundNeighbours.clear();
	this->costOfEdge.clear();
}

void DirectedGraph::initialize(int noOfVertices) {
	for (int i = 0; i < noOfVertices; i++) {
		this->inboundNeighbours[i] = vector<int>();
		this->outboundNeighbours[i] = vector<int>();
	}
}

bool DirectedGraph::isEdge(int startVertex, int endVertex) const {
	if (this->costOfEdge.find(make_pair(startVertex, endVertex)) != this->costOfEdge.end())
		return true;
	return false;
}

bool DirectedGraph::isVertex(int vertex) const {
	if (this->inboundNeighbours.find(vertex) != this->inboundNeighbours.end())
		return true;
	return false;
}

void DirectedGraph::addVertex(int vertex) {
	if (this->isVertex(vertex))
		return;
	this->inboundNeighbours[vertex] = vector<int>();
	this->outboundNeighbours[vertex] = vector<int>();
}

void DirectedGraph::addEdge(int startVertex, int endVertex, int costOfEdge) {
	if (this->isEdge(startVertex, endVertex))
		return;
	if (!this->isVertex(startVertex) || !this->isVertex(endVertex))
		return;
	this->outboundNeighbours[startVertex].push_back(endVertex);
	this->inboundNeighbours[endVertex].push_back(startVertex);
	pair<int, int> edge = make_pair(startVertex, endVertex);
	this->costOfEdge[edge] = costOfEdge;

}

void DirectedGraph::removeEdge(int startVertex, int endVertex) {
	if (!this->isEdge(startVertex, endVertex))
		return;

	auto it = this->outboundNeighbours[startVertex].begin();

	while (it != this->outboundNeighbours[startVertex].end()) {
		if (*it == endVertex) {
			this->outboundNeighbours[startVertex].erase(it);
			break;
		}
		it++;
	}

	it = this->inboundNeighbours[endVertex].begin();

	while (it != this->inboundNeighbours[endVertex].end()) {
		if (*it == startVertex) {
			this->inboundNeighbours[endVertex].erase(it);
			break;
		}
		it++;
	}

	this->costOfEdge.erase(make_pair(startVertex, endVertex));
}


void DirectedGraph::removeVertex(int vertex) {
	if (!this->isVertex(vertex)) return;
	vector<int> Neighbours = this->inboundNeighbours[vertex];
	for (auto it : Neighbours) {
		if (isEdge(it, vertex))
			this->removeEdge(it, vertex);
	}
	Neighbours = this->outboundNeighbours[vertex];
	for (auto it : Neighbours) {
		if (isEdge(vertex, it))
			this->removeEdge(vertex, it);
	}
}

void DirectedGraph::modifyCostOfAnEdge(int startVertex, int endVertex, int newCost) {
	if (!this->isEdge(startVertex, endVertex))
		return;
	this->costOfEdge[make_pair(startVertex, endVertex)] = newCost;
}

int DirectedGraph::getNumberOfVertices() const {
	return this->inboundNeighbours.size();
}


int DirectedGraph::getCostOfAnEdge(int startVertex, int endVertex) {
	if (!this->isEdge(startVertex, endVertex))
		return 0;
	return this->costOfEdge[make_pair(startVertex, endVertex)];
}

int DirectedGraph::getIndegreeOfAVertex(int vertex) {
	if (!this->isVertex(vertex))
		return 0;
	return this->inboundNeighbours[vertex].size();
}

int DirectedGraph::getOutdegreeOfAVertex(int vertex) {
	if (!this->isVertex(vertex))
		return 0;
	return this->outboundNeighbours[vertex].size();
}

int DirectedGraph::getNumberOfEdges() const {
	return this->costOfEdge.size();
}

vector<int> DirectedGraph::getAllVertices() const {
	vector<int> vertices = vector<int>();
	for (auto it = this->inboundNeighbours.begin(); it != this->inboundNeighbours.end(); it++) {
		vertices.push_back(it->first);
	}
	return vertices;
}

vector<int> DirectedGraph::getOutBoundVerticesOfAVertex(int vertex)
{
	if (this->isVertex(vertex))
		return this->outboundNeighbours[vertex];
	return vector<int>();
}

vector<int> DirectedGraph::getInBoundVerticesOfAVertex(int vertex)
{
	if (this->isVertex(vertex))
		return this->inboundNeighbours[vertex];
	return vector<int>();
}

vector<pair<pair<int, int>, int>> DirectedGraph::getAllEdges() const {
	pair<pair<int, int>, int> edge;
	vector< pair<pair<int, int>, int>> edges;
	pair<int, int> vertices;

	for (auto it = this->costOfEdge.begin(); it != this->costOfEdge.end(); it++) {
		vertices = it->first;
		edge = make_pair(vertices, it->second);

		edges.push_back(edge);
	}
	return edges;
}

vector<pair<pair<int, int>, int>> DirectedGraph::getInboundEdgesOfAVertex(int vertex) const {
	vector<pair<pair<int, int>, int>> inboundEdges = vector<pair<pair<int, int>, int>>();
	pair<int, int> vertices;
	int cost;
	for (auto it = this->costOfEdge.begin(); it != this->costOfEdge.end(); it++) {
		vertices = it->first;
		cost = it->second;

		if (vertices.second == vertex)
			inboundEdges.push_back(make_pair(vertices, cost));
	}
	return inboundEdges;
}


vector<pair<pair<int, int>, int>> DirectedGraph::getOutboundEdgesOfAVertex(int vertex) const {
	vector<pair<pair<int, int>, int>> outboundEdges = vector<pair<pair<int, int>, int>>();
	pair<int, int> vertices; int cost;
	for (auto it = this->costOfEdge.begin(); it != this->costOfEdge.end(); it++) {
		vertices = it->first;
		cost = it->second;

		if (vertices.first == vertex)
			outboundEdges.push_back(make_pair(vertices, cost));
	}
	return outboundEdges;
}

void DirectedGraph::copyGraph(DirectedGraph& copyOfGraph) const {
	vector<int> vertices = this->getAllVertices();

	for (auto it = vertices.begin(); it != vertices.end(); it++) {
		copyOfGraph.addVertex(*it);
	}

	vector<pair<pair<int, int>, int>> edges = this->getAllEdges();
	pair<pair<int, int>, int> edge;

	for (auto it = edges.begin(); it != edges.end(); it++) {
		edge = *it;
		copyOfGraph.addEdge(edge.first.first, edge.first.second, edge.second);
	}
}