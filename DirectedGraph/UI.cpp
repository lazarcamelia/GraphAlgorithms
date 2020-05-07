#include "UI.h"
#include <string>
#include <iostream>
#include <fstream>
#include <map>

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

	vector<pair<pair<int, int>, int>> outboundEdges= graph.getOutboundEdgesOfAVertex(vertex);
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
	cout <<  "The name of the file is = ";
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
