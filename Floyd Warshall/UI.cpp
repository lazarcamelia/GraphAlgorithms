#include "UI.h"
#include "Parsings.h"
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <bitset>

#define inf 0x3f3f3f3f

using namespace std;

void UI::writeMenu() {
	cout << "____________________________________________________________________________" << endl;
	cout << "1. Add a new vertex" << endl;
	cout << "2. Add a new edge" << endl;
	cout << "3. Remove a vertex" << endl;
	cout << "4. Remove an edge" << endl;
	cout << "5. Check if a given edge exist in the directed graph" << endl;
	cout << "6. Get the indegree and outdegree of a given vertex" << endl;
	cout << "7. Get all vertices" << endl;
	cout << "8. Get the number of vertices" << endl;
	cout << "9. Get all outbound edges of a given vertex" << endl;
	cout << "10. Get all inbound edges of a given vertex" << endl;
	cout << "11. Modify an edge" << endl;
	cout << "12. Create a copy of the graph" << endl;
	cout << "13. Read the graph from a file" << endl;
	cout << "14. Write the graph to a given file" << endl;
	cout << "15. Create a random graph with a given number of vertices and edges" << endl;
	cout << "16. Read an undirected graph and get its connected components" << endl;
	cout << "17. Read a directed graph and get its strongly connected components" << endl;
	cout << "18. Find a lowest cost walk between 2 vertices" << endl;
	//cout << "19. Find the number of distinct walks of minimum cost between the given vertices" << endl;
	cout << "0. Exit the function" << endl;
}

void uiAddVertex(DirectedGraph& graph) {
	int vertex;
	cout << "The vertex to be added is = ";
	cin >> vertex;

	graph.addVertex(vertex);
}

void uiAddEdge(DirectedGraph& graph) {
	int startVertex, endVertex, costOfEdge;
	cout << "The start vertex is = ";
	cin >> startVertex;
	cout << "The end vertex is = ";
	cin >> endVertex;
	cout << "The cost of the edge is = ";
	cin >> costOfEdge;

	graph.addEdge(startVertex, endVertex, costOfEdge);
}

void uiRemoveVertex(DirectedGraph& graph) {
	int vertex;
	cout << "The vertex to be removed is = ";
	cin >> vertex;

	graph.removeVertex(vertex);
}

void uiRemoveEdge(DirectedGraph& graph) {
	int startVertex, endVertex;
	cout << "The start vertex is = ";
	cin >> startVertex;
	cout << "The end vertex is = ";
	cin >> endVertex;

	graph.removeEdge(startVertex, endVertex);
}

void uiIsEdge(DirectedGraph& graph) {
	int startVertex, endVertex;
	cout << "The start vertex is = ";
	cin >> startVertex;
	cout << "The end vertex is = ";
	cin >> endVertex;

	bool isEdge = graph.isEdge(startVertex, endVertex);
	if (isEdge)
		cout << "The edge is in the graph" << endl;
	else
		cout << "The edge is not in the graph" << endl;
}

void uiIsVertex(DirectedGraph& graph) {
	int vertex;
	cout << "The vertex to be checked is = ";
	cin >> vertex;
	bool isVertex = graph.isVertex(vertex);
	if (isVertex)
		cout << "The vertex is in the graph" << endl;
	else
		cout << "The vertex is not in the graph" << endl;
}

void uiGetIndegreeAndOutDegree(DirectedGraph& graph) {
	int vertex;
	cout << "The vertex to be checked is = ";
	cin >> vertex;
	cout << "The indegree of the vertex is " << graph.getIndegreeOfAVertex(vertex) << endl;
	cout << "The outdegree of the vertex is " << graph.getOutdegreeOfAVertex(vertex) << endl;
}

void uiGetAllVertices(DirectedGraph& graph) {
	vector<int> vertices = graph.getAllVertices();

	cout << "The vertices are ";
	for (auto it = vertices.begin(); it != vertices.end(); it++) {
		cout << *it << " ";
	}
	cout << "\n";
}

void uiGetNumberOfVertices(DirectedGraph& graph) {
	cout << "The total number of vertices is " << graph.getNumberOfVertices() << endl;
}

void uiGetOutboundEdges(DirectedGraph& graph) {
	int vertex;
	cout << "The vertex is = ";
	cin >> vertex;

	vector<pair<pair<int, int>, int>> outboundEdges = graph.getOutboundEdgesOfAVertex(vertex);
	if (outboundEdges.size() == 0) {
		cout << "The vertex doesn't have outbound edges" << endl;
		return;
	}
	cout << "The outbound edges of the vertex are: " << endl;
	pair<pair<int, int>, int> edge;
	for (auto it = outboundEdges.begin(); it != outboundEdges.end(); it++) {
		edge = *it;
		cout << edge.first.first << " " << edge.first.second << " " << edge.second << "\n";
	}
	cout << endl;
}

void uiGetInboundEdges(DirectedGraph& graph) {
	int vertex;
	cout << "The vertex is = ";
	cin >> vertex;

	vector<pair<pair<int, int>, int>> inboundEdges = graph.getInboundEdgesOfAVertex(vertex);
	if (inboundEdges.size() == 0) {
		cout << "The vertex doesn't have inbound edges" << endl;
		return;
	}
	cout << "The inbound edges of the vertex are " << endl;
	pair<pair<int, int>, int> edge;
	for (auto it = inboundEdges.begin(); it != inboundEdges.end(); it++) {
		edge = *it;
		cout << edge.first.first << " " << edge.first.second << " " << edge.second << "\n";
	}
	cout << endl;
}

void uiModifyEdge(DirectedGraph& graph) {
	int startVertex, endVertex, newCostOfEdge;
	cout << "The start vertex is = ";
	cin >> startVertex;
	cout << "The end vertex is = ";
	cin >> endVertex;
	cout << "The new cost of the edge is = ";
	cin >> newCostOfEdge;

	graph.modifyCostOfAnEdge(startVertex, endVertex, newCostOfEdge);
}

void uiCreateCopy(DirectedGraph& graph) {
	DirectedGraph graph2;
	graph.copyGraph(graph2);
}

void uiReadGraph(DirectedGraph& graph) {
	string filename;
	cout << "The name of the file is = ";
	cin >> filename;

	readFromFile(graph, filename);
}

void uiWriteGraph(DirectedGraph& graph) {
	string filename;
	cout << "The name of the file is = ";
	cin >> filename;

	writeToFile(graph, filename);
}

void uiCreateRandomGraph(DirectedGraph& graph) {
	int numberOfvertices, numberOfEdges;
	cout << "The number of vertices is = ";
	cin >> numberOfvertices;
	cout << "The number of edges is = ";
	cin >> numberOfEdges;
	createRandomGraph(graph, numberOfvertices, numberOfEdges);
}


void computeConnectedComponents(DirectedGraph& graph) {
	int numberOfVertices = graph.getNumberOfVertices();
	bitset<MAXN> visitedVertices;

	vector<int> vertices = graph.getAllVertices();
	int numberOfConnectedComponents = 0;
	vector<DirectedGraph> connectedComponent = vector<DirectedGraph>();

	for (auto it : vertices) {
		if (!visitedVertices[it]) {
			connectedComponent.push_back(DirectedGraph());
			BFS(graph, it, connectedComponent[numberOfConnectedComponents], visitedVertices);

			cout << "Connected commponent no. " << numberOfConnectedComponents << " is formed by: " << endl;
			cout << "The vertices are: ";
			for (auto vertex : connectedComponent[numberOfConnectedComponents].getAllVertices()) {
				cout << vertex << " ";
			}
			cout << endl;
			/*if (connectedComponent[numberOfConnectedComponents].getNumberOfEdges() == 0)
				cout << "There are no edges" << endl;
			else {
				cout << "The edges are :" << endl;
				for (auto edge : connectedComponent[numberOfConnectedComponents].getAllEdges()) {
					cout << "The edge is " << edge.first.first << " " <<  edge.first.second << " " <<  edge.second << "\n";
				}
			} */
			numberOfConnectedComponents++;
		}
	}
}


void uiGetConnectedComponentsOfAGraph(DirectedGraph& graph) {
	string filename;
	cout << "The filename is = ";
	cin >> filename;
	readUndirectedFromFile(graph, filename);
	computeConnectedComponents(graph);
}

void computeStronglyConnectedComponents(DirectedGraph& graph) {
	bitset<MAXN> visited;
	stack<int> processed;
	for (auto vertex : graph.getAllVertices()) {
		if (!visited[vertex])
			DFS(vertex, graph, visited, processed);
	}

	int vertex, v;

	visited.reset();

	queue <int> q;

	int numberOfComponents = 0;
	vector<DirectedGraph> connectedComponent;
	vector<int> neighbours;

	int cost;

	while (!processed.empty()) {
		vertex = processed.top();
		processed.pop();

		if (visited[vertex])
			continue;

		connectedComponent.push_back(DirectedGraph());

		q.push(vertex);
		while (!q.empty()) {
			v = q.front();
			connectedComponent[numberOfComponents].addVertex(v);
			q.pop();
			visited[v] = 1;
			neighbours = graph.getInBoundVerticesOfAVertex(v);
			for (auto inbound : neighbours) {
				if (!visited[inbound]) {
					q.push(inbound);
					connectedComponent[numberOfComponents].addVertex(inbound);
					cost = graph.getCostOfAnEdge(v, inbound);
					connectedComponent[numberOfComponents].addEdge(inbound, v, cost);
				}
				else {
					cost = graph.getCostOfAnEdge(v, inbound);
					connectedComponent[numberOfComponents].addEdge(inbound, v, cost);
				}
			}
		}
		numberOfComponents++;
	}

	cout << "The number of strongly connected components is " << numberOfComponents << endl;

	for (int i = 1; i <= numberOfComponents; i++) {
		cout << "The strongly connected component no " << i << " has the edges: ";

		for (auto vertex : connectedComponent[i - 1].getAllVertices())
			cout << vertex << " ";
		cout << endl;

		/*if (connectedComponent[i - 1].getNumberOfEdges() == 0)
			cout << "The strongly connected component no " << i << " doesn't have edges" << endl;
		else {
			cout << "The strongly connected component no " << i << " has the edges: " << endl;

			for (auto edge : connectedComponent[i - 1].getAllEdges())
				cout << edge.first.first << " " << edge.first.second << " " << edge.second << endl;
		} */
	}
}

void uiGetStronglyConnectedComponentsOfAGraph(DirectedGraph& graph) {
	string filename;
	cout << "The filename is = ";
	cin >> filename;
	readFromFile(graph, filename);
	computeStronglyConnectedComponents(graph);
}

void uiWritePath(vector<vector<int>>next, int startVertex, int endVertex, DirectedGraph& graph) {
	//cout << startVertex << " ";
	int cost;
	while (startVertex != endVertex) {
		cost = graph.getCostOfAnEdge(startVertex, next[startVertex][endVertex]);

		cout <<  "((" << startVertex << ", " << next[startVertex][endVertex] << "), " << cost << ") ";
		startVertex = next[startVertex][endVertex];

	}
	cout << endl;
}

	void uiFindLowestPathBetweenTwoVertices(DirectedGraph& graph) {
		string filename;

		cout << "The filename is = ";
		cin >> filename; //reading the filename
		readFromFile(graph, filename); //reading the graph from file

		int startVertex, endVertex;
		cout << "The start vertex is = ";
		cin >> startVertex; //reading the start vertex 
		cout << "The end vertex is = ";
		cin >> endVertex; //reading the end vertex

		vector<vector<int>> cost = vector<vector<int>>();
		vector<vector<int>> next = vector<vector<int>>();
		GenerateCostMatrixOfADirectedGraph(graph, cost, next); //generate the cost matrix of the graph
		FloydWarshall(graph, cost, next); //computing the shortest pahts from all the nodes to all the nodes in graph
		if (cost[startVertex][endVertex] != inf) { //if exists at least one path between the start vertex and end vertex
			cout << "The lowest cost path has the cost " << cost[startVertex][endVertex] << "\n";
			uiWritePath(next, startVertex, endVertex, graph);
		}
		else
			cout << "It doesn't exist a path between " << startVertex << " and " << endVertex << "\n";
	}

/*void uiDistinctPaths(DirectedGraph& graph) {
	string filename;

	cout << "The filename is = ";
	cin >> filename;
	readFromFile(graph, filename);

	int startVertex, endVertex;
	cout << "The start vertex is = ";
	cin >> startVertex;
	cout << "The end vertex is = ";
	cin >> endVertex;

	int numberOfDistinctPaths = DijkstraWithSeveralPaths(graph, startVertex, endVertex);

	cout << "The number of distinct paths is " << numberOfDistinctPaths << endl;
} */

void uiExitFunction(DirectedGraph& graph) {
	return;
}


void initCommands(map<string, func>& commands) {
	commands["0"] = uiExitFunction;
	commands["1"] = uiAddVertex;
	commands["2"] = uiAddEdge;
	commands["3"] = uiRemoveVertex;
	commands["4"] = uiRemoveEdge;
	commands["5"] = uiIsEdge;
	commands["6"] = uiGetIndegreeAndOutDegree;
	commands["7"] = uiGetAllVertices;
	commands["8"] = uiGetNumberOfVertices;
	commands["9"] = uiGetOutboundEdges;
	commands["10"] = uiGetInboundEdges;
	commands["11"] = uiModifyEdge;
	commands["12"] = uiCreateCopy;
	commands["13"] = uiReadGraph;
	commands["14"] = uiWriteGraph;
	commands["15"] = uiCreateRandomGraph;
	commands["16"] = uiGetConnectedComponentsOfAGraph;
	commands["17"] = uiGetStronglyConnectedComponentsOfAGraph;
	commands["18"] = uiFindLowestPathBetweenTwoVertices;
	//commands["19"] = uiDistinctPaths;
}

void UI::run() {
	string inputCommand = "";
	map<string, func> commands;
	initCommands(commands);
	DirectedGraph graph = DirectedGraph();

	while (inputCommand != "0") {
		writeMenu();
		try {
			cout << "Your command is = ";
			cin >> inputCommand;
			if (commands.find(inputCommand) == commands.end())
				throw exception();
			func command = commands[inputCommand];
			(*command)(graph);
		}
		catch (exception) {
			cout << "Invalid command! Please try again!\n";
		}
	}
}
