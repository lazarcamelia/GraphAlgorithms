#pragma once
#include "DirectedGraph.h"
#include "ExternalFunctions.h"

typedef void (*func)(DirectedGraph&);

class UI {
public:
	void run();
	void writeMenu();
};
