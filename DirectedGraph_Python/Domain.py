import copy

class DirectedGraph(object):
    def __init__(self, numberOFVertices = 0):
        """
        initialize the directed graph
        :param numberOFVertices: integer, the number of vertices
        """
        self._dict_in = {}
        self._dict_out = {}
        self._dict_cost = {}
        for i in range(numberOFVertices):
            self._dict_in[i] = []
            self._dict_out[i] = []

    def initialize(self, numberOfVertices):
        self._dict_in = {}
        self._dict_out = {}
        self._dict_cost = {}
        for i in range(numberOfVertices):
            self._dict_in[i] = []
            self._dict_out[i] = []

    def isEdge(self, sourceVertex, destinationVertex):
        """
        check if the edge sourceVertex->destinationVertex is an edge
        :param sourceVertex: integer, the first vertex
        :param destinationVertex: integer, the second vertex
        :return: True if exists the edge, False otherwise
        """
        edge = (sourceVertex, destinationVertex)

        if edge in self._dict_cost.keys():
            return True
        return False

    def isVertex(self, vertex):
        """
        check if the vertex exists
        :param vertex: integer
        :return: True if vertex is a vertex in graph, False otherwise
        """
        if vertex in self._dict_in.keys():
            return True
        return False

    def addVertex(self, vertex):
        """
        Add a vertex to the graph
        Precondition: the vertex is not already added to the graph
        :param vertex: integer, vertex to be added
        :return: -
        """
        if self.isVertex(vertex) == True:
            return
        self._dict_in[vertex] = []
        self._dict_out[vertex] = []

    def addEdge(self, sourceVertex, destinationVertex, costOfTheEdge):
        """
        add a new adge to the directed graph
        precondition: the edge doesn't exist
        :param sourceVertex: integer, the source vertex
        :param destinationVertex: integer, the destination vertex
        :param costOfTheEdge: integer, cost of the edge
        :return: -
        """
        edge = (sourceVertex, destinationVertex)
        if self.isEdge(sourceVertex, destinationVertex):
            return

        if self.isVertex(sourceVertex):
            self.addVertex(sourceVertex)
        if self.isVertex(destinationVertex):
            self.addVertex(destinationVertex)

        self._dict_out[sourceVertex].append(destinationVertex)
        self._dict_in[destinationVertex].append(sourceVertex)
        self._dict_cost[edge] = costOfTheEdge


    def removeVertex(self, vertex):
        """
        remove a vertex from the directed graph
        :param vertex:
        :return:
        """
        if self.isVertex(vertex):
            Neigbours = self._dict_out[vertex]
            for secondVertex in Neigbours:
                if self.isEdge(vertex, secondVertex):
                    self.removeEdge(vertex, secondVertex)

            Neigbours = self._dict_in[vertex]
            for firstVertex in Neigbours:
                if self.isEdge(firstVertex, vertex):
                    self.removeEdge(firstVertex, vertex)

            del self._dict_in[vertex]
            del self._dict_out[vertex]

    def removeEdge(self, sourceVertex, destinationVertex):
        """
        remove an edge from the directed graph
        :param sourceVertex: integer, the source vertex of the edge to be removed
        :param destinationVertex: integer, the destination vertex of the edge to be removed
        :return: -
        """
        if self.isEdge(sourceVertex, destinationVertex):
            edge = (sourceVertex, destinationVertex)
            del self._dict_cost[edge]
        else:
            return

        self._dict_out[sourceVertex].remove(destinationVertex)
        self._dict_in[destinationVertex].remove(sourceVertex)

    def getNumberOfVertices(self):
        """
        get the number of all the vertices
        :return: integer, the number of vertices
        """
        return len(self.getAllVertices())

    def getAllVertices(self):
        """
        return a list of all the vertices
        :return: list - containing all the vertices
        """
        return self._dict_out.keys()

    def getAllEdges(self):
        """
        return the list of all the edges
        :return: tuple of 3 elements consisting of (startVertex, endVertex, costOfEdge)
        """
        edges = self._dict_cost.keys()
        edgesWithCost = []
        for edge in edges:
            edgeWithCost = (edge[0], edge[1], self._dict_cost[edge])
            edgesWithCost.append(edgeWithCost)

        return edgesWithCost

    def getOutboundEdges(self, vertex):
        """
        return a list of all the outbound neighbours of a vertex
        :param vertex:
        :return:
        """
        outboundEdges = []

        for edge in self._dict_cost.keys():
            if edge[0] == vertex:
                costOfEdge = self._dict_cost[edge]
                edgeWithCost = (edge[0], edge[1], costOfEdge)
                outboundEdges.append(edgeWithCost)

        return outboundEdges

    def getInboundEdges(self, vertex):
        """
        return a list of all the inbound neighbours of a vertex
        :param vertex: integer
        :return: list
        """
        inboundEdges = []

        for edge in self._dict_cost.keys():
            if edge[1] == vertex:
                costOfEdge = self._dict_cost[edge]
                edgeWithCost = (edge[0], edge[1], costOfEdge)
                inboundEdges.append(edgeWithCost)
        return inboundEdges

    def getInDegreeOfAVertex(self, vertex):
        """
        return the indegree of a vertex
        :param vertex: integer
        :return: integer
        """
        if self.isVertex(vertex):
            return len(self.getInboundEdges(vertex))
        return 0

    def getOutDegreeOfAVertex(self, vertex):
        """
        return the  outdegree of a vertex
        :param vertex: integer
        :return: integer
        """
        if self.isVertex(vertex):
            return len(self.getOutboundEdges(vertex))
        return 0

    def modifyEdge(self, sourceVertex, destinationVertex, newCost):
        """
        modifiy the cost of the edge (sourceVertex, destinationVertex)
        :param sourceVertex: integer, the start of the edge
        :param destinationVertex: integer, the end of the edge
        :param newCost: integer, the new cost attached to the edge
        :return: -
        """
        if self.isEdge(sourceVertex, destinationVertex):
            edge = (sourceVertex, destinationVertex)
            self._dict_cost[edge] = newCost
        else:
            self.addEdge(sourceVertex, destinationVertex, newCost)

    def copyGraph(self):
        """
        function which creates a copy of a graph
        :return: a copy of a directed graph given as parameter
        """
        directed_graph = DirectedGraph(self.getNumberOfVertices())
        directed_graph._dict_in = copy.deepcopy(self._dict_in)
        directed_graph._dict_out = copy.deepcopy(self._dict_out)
        directed_graph._dict_cost = copy.deepcopy(self._dict_cost)
        '''
        for vertex in self._dict_in.keys():
            directed_graph._dict_in[vertex] = self.getInboundVertices(vertex)

        for vertex in self._dict_out.keys():
            directed_graph._dict_out[vertex] = self.getOutboundVertices(vertex)

        directed_graph._dict_cost = self._dict_cost 
        '''
        return directed_graph

    def clearAll(self):
        self._dict_in.clear()
        self._dict_out.clear()
        self._dict_cost.clear()