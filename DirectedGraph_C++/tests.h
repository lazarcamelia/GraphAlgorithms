#pragma once
#include "DirectedGraph.h"

void testAll();
void testAddVertex_ValidInput_AddedToGraph();
void testAddEdge_ValidInput_AddedToGraph();
void testIsVertex_ValidInput_ReturnedTrue();
void testIsVertex_InvalidInput_ReturnedFalse();
void testIsEdge_ValidInput_ReturnedTrue();
void testIsEdge_InvalidInput_ReturnedFalse();
void testRemoveEdge_ValidInput_RemovedFromGraph();
void testRemoveVertex_ValidInput_RemovedFromGraph();
void testGetCostOfAnEgde_ValidInput_GetInt();
void testModifyCostOfAnEdge_ValidInput_ModifiedTheCost();
void testGetNumberOfVertices_ValidInput_ReturnedInt();
void testGetNumberOfEdges_ValidInput_ReturnedInt();
void testGetNumberOfInboundNeighboursOfAVertices_ValidInput_ReturnedInt();
void testGetNumberOfOutboundNeighboursOfAVertices_ValidInput_ReturnedInt();

void testGetAllVertices_ValidInput_ReturnedVectorOfInt();
void testGetAllEdges_ValidInput_ReturnedVectorOfPairs();
void testGetInboundNeighboursOfAVertex_ValidInput_ReturnedVectorOfInt();
void testGetOutboundNeighboursOfAVertex_ValidInput_ReturnedVectorOfInt();

void testCopyOfGraph_ValidInput_CopiesTheGraph();
void testWriteToFile_ValidInput_WriteToFile();
void testReadFromFile_ValidInut_ReadFromFile();
