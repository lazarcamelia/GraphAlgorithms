#include "tests.h"
#include <assert.h>
#include <iostream>

void testAddVertex_ValidInput_AddedToGraph() {
	DirectedGraph myGraph = DirectedGraph();
	myGraph.addVertex(1);
	assert(myGraph.getNumberOfVertices() == 1);
}

void testAddEdge_ValidInput_AddedToGraph() {
	DirectedGraph myGraph = DirectedGraph();
	myGraph.addVertex(1);
	myGraph.addVertex(2);
	myGraph.addEdge(1, 2, 10);
	assert(myGraph.getNumberOfEdges() == 1);
	//assert(myGraph.getNumberOfVertices() == 2);
}

void testIsVertex_ValidInput_ReturnedTrue() {
	DirectedGraph myGraph = DirectedGraph();
	myGraph.addVertex(1);
	assert(myGraph.isVertex(1) == true);
}

void testIsVertex_InvalidInput_ReturnedFalse() {
	DirectedGraph myGraph = DirectedGraph();
	assert(myGraph.isVertex(1) == false);
}

void testIsEdge_ValidInput_ReturnedTrue() {
	DirectedGraph myGraph = DirectedGraph(2);
	myGraph.addEdge(1, 2, 10);
	assert(myGraph.isEdge(1, 2) == true);
}

void testIsEdge_InvalidInput_ReturnedFalse() {
	DirectedGraph myGraph = DirectedGraph(2);
	assert(myGraph.isEdge(0, 1) == false);
}

void testRemoveEdge_ValidInput_RemovedFromGraph() {
	DirectedGraph myGraph = DirectedGraph();
	myGraph.addVertex(1);
	myGraph.addVertex(2);
	myGraph.addEdge(1, 2, 10);
	myGraph.addEdge(2, 1, -10);
	myGraph.removeEdge(1, 2);
	assert(myGraph.isEdge(1, 2) == false);
	//assert(myGraph.getNumberOfEdges() == 1);
}

void testRemoveVertex_ValidInput_RemovedFromGraph() {
	DirectedGraph myGraph = DirectedGraph(3);
	assert(myGraph.isVertex(2) == true);
	myGraph.removeVertex(2);
	assert(myGraph.isVertex(2) == false);
}

void testGetCostOfAnEgde_ValidInput_GetInt() {
	DirectedGraph myGraph = DirectedGraph(5);
	myGraph.addEdge(3, 4, 20);
	assert(myGraph.getCostOfAnEdge(3, 4) == 20);
}

void testModifyCostOfAnEdge_ValidInput_ModifiedTheCost() {
	DirectedGraph myGraph = DirectedGraph(5);
	myGraph.addEdge(3, 4, 20);
	myGraph.modifyCostOfAnEdge(3, 4, 21);
	assert(myGraph.getCostOfAnEdge(3, 4) == 21);
}

void testGetNumberOfVertices_ValidInput_ReturnedInt() {
	DirectedGraph myGraph = DirectedGraph(5);
	myGraph.addVertex(6);
	assert(myGraph.getNumberOfVertices() == 6);
}

void testGetNumberOfEdges_ValidInput_ReturnedInt() {
	DirectedGraph myGraph = DirectedGraph(5);
	myGraph.addEdge(0, 2, 50);
	myGraph.addEdge(2, 0, 50);
	myGraph.addEdge(1, 3, -50);
	assert(myGraph.getNumberOfEdges() == 3);
}

void testGetNumberOfInboundNeighboursOfAVertices_ValidInput_ReturnedInt() {
	DirectedGraph myGraph = DirectedGraph(5);
	myGraph.addEdge(0, 2, 50);
	myGraph.addEdge(3, 2, 50);
	myGraph.addEdge(1, 3, -50);
	assert(myGraph.getIndegreeOfAVertex(2) == 2);
	assert(myGraph.getIndegreeOfAVertex(0) == 0);
}

void testGetNumberOfOutboundNeighboursOfAVertices_ValidInput_ReturnedInt() {
	DirectedGraph myGraph = DirectedGraph(5);
	myGraph.addEdge(0, 2, 50);
	myGraph.addEdge(3, 2, 50);
	myGraph.addEdge(1, 3, -50);
	
	assert(myGraph.getOutdegreeOfAVertex(0) == 1);
	assert(myGraph.getOutdegreeOfAVertex(2) == 0);

}

void testGetAllVertices_ValidInput_ReturnedVectorOfInt() {
	DirectedGraph myGraph = DirectedGraph(5);
	myGraph.removeVertex(3);

	vector<int> vertices = myGraph.getAllVertices();
	assert(vertices.size() == 4);
}

void testGetAllEdges_ValidInput_ReturnedVectorOfPairs() {
	DirectedGraph myGraph = DirectedGraph(5);
	myGraph.addEdge(0, 2, 50);
	myGraph.addEdge(3, 2, 50);
	myGraph.addEdge(1, 3, -50);

	vector<pair<pair<int, int>, int>> edges = myGraph.getAllEdges();
	assert(edges.size() == 3);

	/*for (auto it = edges.begin(); it != edges.end(); it++) {
		pair<int, int> edge = *it;
		std::cout << edge.first << " " << edge.second << "\n";
	} */
}

/*void testGetInboundNeighboursOfAVertex_ValidInput_ReturnedVectorOfInt() {
	DirectedGraph myGraph = DirectedGraph(5);
	myGraph.addEdge(0, 2, 50);
	myGraph.addEdge(3, 2, 50);
	myGraph.addEdge(1, 3, -50);

	vector<int> inboundNeighbours = myGraph.getInboundNeighboursOfAVertex(2);
	assert(inboundNeighbours.size() == 2);
}

void testGetOutboundNeighboursOfAVertex_ValidInput_ReturnedVectorOfInt() {
	DirectedGraph myGraph = DirectedGraph(5);
	myGraph.addEdge(0, 2, 50);
	myGraph.addEdge(3, 2, 50);
	myGraph.addEdge(0, 3, -50);

	vector<int> outboundNeighbours = myGraph.getOutboundNeighboursOfAVertex(0);
	assert(outboundNeighbours.size() == 2);
} */

void testCopyOfGraph_ValidInput_CopiesTheGraph() {
	DirectedGraph myGraph = DirectedGraph(5);
	myGraph.addEdge(0, 2, 50);
	myGraph.addEdge(3, 2, 50);
	myGraph.addEdge(0, 3, -50);

	DirectedGraph graph2 = DirectedGraph();
	myGraph.copyGraph(graph2);

	assert(graph2.getNumberOfVertices() == 5);

	myGraph.removeVertex(4);
	assert(myGraph.getNumberOfVertices() == 4);
	assert(graph2.getNumberOfVertices() == 5);
}

void testWriteToFile_ValidInput_WriteToFile() {
	DirectedGraph directedGraph = DirectedGraph();
	createRandomGraph(directedGraph, 4, 8);
	writeToFile(directedGraph, "graph.txt");
}

void testReadFromFile_ValidInut_ReadFromFile() {
	DirectedGraph directedGraph = DirectedGraph();
	readFromFile(directedGraph, "graph.txt");
	vector<pair<pair<int, int>, int>> edges = directedGraph.getAllEdges();
	for (auto it = edges.begin(); it != edges.end(); it++) {
		pair<pair<int, int>, int> edge = *it;
		cout << edge.first.first << " ";
		cout << edge.first.second << " ";
		cout << edge.second << "\n";
	}

	assert(directedGraph.getNumberOfEdges() == 8);
}

void testAll() {
	testAddVertex_ValidInput_AddedToGraph();
	testAddEdge_ValidInput_AddedToGraph();
	testIsVertex_ValidInput_ReturnedTrue();
	testIsVertex_InvalidInput_ReturnedFalse();
	testIsEdge_ValidInput_ReturnedTrue();
	testIsEdge_InvalidInput_ReturnedFalse();
	testRemoveEdge_ValidInput_RemovedFromGraph();
	testRemoveVertex_ValidInput_RemovedFromGraph();
	testGetCostOfAnEgde_ValidInput_GetInt();
	testModifyCostOfAnEdge_ValidInput_ModifiedTheCost();
	testGetNumberOfVertices_ValidInput_ReturnedInt();
	testGetNumberOfEdges_ValidInput_ReturnedInt();
	testGetNumberOfInboundNeighboursOfAVertices_ValidInput_ReturnedInt();
	testGetNumberOfOutboundNeighboursOfAVertices_ValidInput_ReturnedInt();

	testGetAllVertices_ValidInput_ReturnedVectorOfInt();
	testGetAllEdges_ValidInput_ReturnedVectorOfPairs();
	//testGetInboundNeighboursOfAVertex_ValidInput_ReturnedVectorOfInt();
	//testGetOutboundNeighboursOfAVertex_ValidInput_ReturnedVectorOfInt(); 

	testCopyOfGraph_ValidInput_CopiesTheGraph();
	//testWriteToFile_ValidInput_WriteToFile();
	testReadFromFile_ValidInut_ReadFromFile();
} 
