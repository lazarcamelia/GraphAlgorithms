#pragma once
#include "DirectedGraph.h"

#include <queue>
#include <bitset>
#include <vector>
#include <stack>

#define MAXN 10000

using namespace std;

void BFS(DirectedGraph& graph, int start, DirectedGraph& connectedCompnent, bitset<MAXN>& visitedVertices);
void DFS(int vertex, DirectedGraph& graph, bitset<MAXN>& visited, stack <int>& processed);
void GenerateCostMatrixOfADirectedGraph(DirectedGraph& graph, vector<vector<int>>& cost, vector<vector<int>>& next);
void FloydWarshall(DirectedGraph& graph, vector<vector<int>>& cost, vector<vector<int>>& next);
//int DijkstraWithSeveralPaths(DirectedGraph& graph, int startVertex, int endVertex);
