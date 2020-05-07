#include "Parsings.h"
#include <stack>

//Write a program that finds the connected components of an undirected graph using a breadth - first traversal of the graph.


vector<int> outboundVertices;
queue<int> firstq;

void BFS(DirectedGraph& graph, int start,  DirectedGraph& connectedCompnent, bitset<MAXN>& visitedVertices) {
	connectedCompnent.addVertex(start);
	visitedVertices[start] = 1;
	firstq.push(start);
	int vertex, cost;
	while (!firstq.empty()) {
		vertex = firstq.front();

		outboundVertices = graph.getOutBoundVerticesOfAVertex(vertex);
		for (auto neighbourVertex : outboundVertices) {
			if (!visitedVertices[neighbourVertex]) {
				visitedVertices[neighbourVertex] = 1;
				firstq.push(neighbourVertex);
				connectedCompnent.addVertex(neighbourVertex);
				cost = graph.getCostOfAnEdge(vertex, neighbourVertex);
				if (!connectedCompnent.isEdge(neighbourVertex, vertex))
					connectedCompnent.addEdge(vertex, neighbourVertex, cost);
			}
			else {
				cost = graph.getCostOfAnEdge(vertex, neighbourVertex);
				if (!connectedCompnent.isEdge(neighbourVertex, vertex))
					connectedCompnent.addEdge(vertex, neighbourVertex, cost);
			}
		}

		firstq.pop();
	}
}


void DFS(int vertex, DirectedGraph& graph, bitset<MAXN>& visited, stack <int>& processed) {
	visited[vertex] = 1;
	if (graph.getOutdegreeOfAVertex(vertex) != 0) {
		for (auto x : graph.getOutBoundVerticesOfAVertex(vertex)) {
			if (!visited[x]) {
				DFS(x, graph, visited, processed);
			}
		}
	}
	processed.push(vertex);
}
