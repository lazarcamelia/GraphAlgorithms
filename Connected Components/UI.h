#pragma once
#include "DirectedGraph.h"
#include "ExternalFunctions.h"

#define MAXN 10000

typedef void (*func)(DirectedGraph&);

class UI {
public:
	void run();
	void writeMenu();
};
