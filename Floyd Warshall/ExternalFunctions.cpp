#include "ExternalFunctions.h"

void createRandomGraph(DirectedGraph& randomGeneratedGraph, int numberOfVertices, int numberOfEdges) {
	int startVertex, endVertex, costOfEdge;


	randomGeneratedGraph.clearAll();

	while (numberOfEdges) {
		startVertex = rand() % numberOfVertices;
		endVertex = rand() % numberOfVertices;
		costOfEdge = rand() % 100;

		if (!randomGeneratedGraph.isVertex(startVertex))
			randomGeneratedGraph.addVertex(startVertex);
		if (!randomGeneratedGraph.isVertex(endVertex))
			randomGeneratedGraph.addVertex(endVertex);

		if (!randomGeneratedGraph.isEdge(startVertex, endVertex)) {
			randomGeneratedGraph.addEdge(startVertex, endVertex, costOfEdge);
			numberOfEdges--;
		}
	}
}

void writeToFile(DirectedGraph graphToBeReadToFile, string filename) {
	ofstream fout;
	fout.open(filename);
	vector<pair<pair<int, int>, int>> edges = graphToBeReadToFile.getAllEdges();

	for (auto it = edges.begin(); it != edges.end(); it++) {
		fout << it->first.first << " " << it->first.second << " " << it->second << "\n";
	}

	vector<int> vertices = graphToBeReadToFile.getAllVertices();

	int inboundVertices, outboundVertices;
	for (auto it = vertices.begin(); it != vertices.end(); it++) {
		inboundVertices = graphToBeReadToFile.getIndegreeOfAVertex(*it);
		outboundVertices = graphToBeReadToFile.getOutdegreeOfAVertex(*it);

		if (inboundVertices == 0 || outboundVertices == 0)
			fout << *it << " " << -1 << "\n";
	}

	fout.close();
}

void readFromFile(DirectedGraph& directedGraph, string filename) {
	ifstream(fin);

	fin.open(filename);
	int numberOfVertices, numberOfEdges, startVertex, endVertex, costOfEdge;

	directedGraph.clearAll();

	fin >> numberOfVertices >> numberOfEdges;

	directedGraph.initialize(numberOfVertices);

	for (int i = 0; i < numberOfEdges; i++) {
		fin >> startVertex >> endVertex >> costOfEdge;
		if (!directedGraph.isVertex(startVertex))
			directedGraph.addVertex(startVertex);
		if (!directedGraph.isVertex(endVertex))
			directedGraph.addVertex(endVertex);
		if (!directedGraph.isEdge(startVertex, endVertex))
			directedGraph.addEdge(startVertex, endVertex, costOfEdge);
	}
	fin.close();
}

void readUndirectedFromFile(DirectedGraph& directedGraph, string filename) {
	ifstream(fin);

	fin.open(filename);
	int numberOfVertices, numberOfEdges, startVertex, endVertex, costOfEdge;

	directedGraph.clearAll();

	fin >> numberOfVertices >> numberOfEdges;
	directedGraph.initialize(numberOfVertices);

	for (int i = 0; i < numberOfEdges; i++) {
		fin >> startVertex >> endVertex >> costOfEdge;

		if (!directedGraph.isVertex(startVertex))
			directedGraph.addVertex(startVertex);
		if (!directedGraph.isVertex(endVertex))
			directedGraph.addVertex(endVertex);

		if (!directedGraph.isEdge(startVertex, endVertex))
			directedGraph.addEdge(startVertex, endVertex, costOfEdge);
		if (!directedGraph.isEdge(endVertex, startVertex))
			directedGraph.addEdge(endVertex, startVertex, costOfEdge);
	}
	fin.close();
}


