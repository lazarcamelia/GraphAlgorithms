#include "DirectedGraph.h"


void createRandomGraph(DirectedGraph& randomGeneratedGraph, int numberOfVertices, int numberOfEdges);
void writeToFile(DirectedGraph graphToBeReadToFile, string filename);
void readFromFile(DirectedGraph& directedGraph, string filename);