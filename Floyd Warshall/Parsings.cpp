#include "Parsings.h"
#include <stack>
#include <fstream>

#define inf 0x3f3f3f3f

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

void GenerateCostMatrixOfADirectedGraph(DirectedGraph& graph, vector<vector<int>>& cost, vector<vector<int>>& next) {
	cost = vector<vector<int>>();
	next = vector<vector<int>>();

	int n = graph.getNumberOfVertices();
	for (int i = 0; i < n; i++) {
		cost.push_back(vector<int>()); //add an empty element
		next.push_back(vector<int>()); //add an empty element
		for (int j = 0; j < n; j++) {
			cost[i].push_back(inf); //we suppose there is no edge between i and j
			next[i].push_back(-1);
			if (graph.isEdge(i, j)) { //if we find an edge we change the cost and the successor
				cost[i][j] = graph.getCostOfAnEdge(i, j);
				next[i][j] = j;
			}
		}
	}
}

void FloydWarshall(DirectedGraph& graph, vector<vector<int>>& cost, vector<vector<int>>& next) {
	vector<int>path = vector<int>();

	int N = graph.getNumberOfVertices(); //get the number of vertices in the graph

	ofstream fout{ "executie.txt" };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fout << next[i][j] << " ";
		}
		fout << "\n";
	}

	for (int k = 0; k < N; k++) { //we parse the graph N times, so that we can construct a path between any 2 vertices
		fout << "Using k = " << k << " as intermediate vertex" << endl;
		fout << "The cost matrix is: " << endl;
		for (int i = 0; i < N; i++) { 
			for (int j = 0; j < N; j++) {
				if (cost[i][j] > cost[i][k] + cost[k][j]) { //if we have found a lowest cost path between the vertices i and j
					cost[i][j] = cost[i][k] + cost[k][j]; //we update the cost
					next[i][j] = next[i][k]; //we update the successor
				}
				if (cost[i][j] == inf)
					fout << "inf ";
				else
					fout << cost[i][j] << " "; 
			}
		fout << "\n";
		}

		fout << "The successor matrix is: " << endl;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				fout << next[i][j] << " ";
			fout << "\n";
		} 
	}
}

/*int DijkstraWithSeveralPaths(DirectedGraph& graph, int startVertex, int endVertex) {
	priority_queue<int> queue = priority_queue<int>();
	vector<int> distinctPaths = vector<int>();
	vector<int> cost = vector<int>();

	int N = graph.getNumberOfVertices();
	
	for (int i = 0; i < N; i++) {
		distinctPaths.push_back(0);
		cost.push_back(inf);
	}

	queue.push(startVertex);

	int vertex, endNode;

	vector<pair<pair<int, int>, int>> edges;

	while (!queue.empty()) {
		vertex = queue.top();
		queue.pop();

		if (vertex == endVertex) 
			return distinctPaths[vertex];
		
		edges = graph.getOutboundEdgesOfAVertex(vertex);

		for (auto edge : edges) {
			endNode = edge.first.second;

			if (cost[endNode] > cost[vertex] + edge.second) {
				cost[endNode] = cost[vertex] + edge.second;
				distinctPaths[endNode] = 1;
			}
			else if (cost[endNode] == cost[vertex] + edge.second)
				distinctPaths[endNode]++;
		}
	}

	return 0;
} */