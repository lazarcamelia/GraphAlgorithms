from Domain import DirectedGraph
from random import randint

def read_graph_from_file():
    filename = input("filename =")
    access_type = "r"
    fin = open(filename, access_type)

    for line in fin:
        return
    pass
    return graph

def print_number_of_vertices(graph):
    vertices = graph.getNumberOfVertices()
    print("The number of vertices is =", vertices)
    return graph

def print_set_of_vertices(graph):
    vertices = graph.getAllVertices()

    print("The vertices are:")
    for vertex in vertices:
        print(vertex)
    return graph

def is_edge(graph):
    startVertex = int(input("The start vertex is ="))
    endVertex = int(input("The end vertex is ="))
    isEdge = graph.isEdge(startVertex, endVertex)

    if isEdge:
        print("The edge is in the graph")
    else:
        print("The edge is not in the graph")

    return graph

def is_vertex(graph):
    vertex = int(input("The vertex is ="))

    if graph.isVertex(vertex):
        print("The vertex is in the graph")
    else:
        print("The vertex is not in the graph")
    return graph

def add_edge(graph):
    startVertex = int(input("The start vertex is ="))
    endVertex = int(input("The end vertex is ="))
    costOfEdge = int(input("The cost of the edge is ="))

    if graph.isEdge(startVertex, endVertex) == False:
        graph.addEdge(startVertex, endVertex, costOfEdge)
    else:
        print("The edge already exist")
    return graph

def add_vertex(graph):
    vertex = int(input("The vertex is ="))
    if graph.isVertex(vertex):
        print("The vertex already exist")
    graph.addVertex(vertex)
    return graph

def remove_vertex(graph):
    vertex = int(input("The vertex is ="))
    if graph.isVertex(vertex) == False:
        print("The vertex doesn't exist")
    else:
        graph.removeVertex(vertex)
    return graph

def remove_edge(graph):
    startVertex = int(input("The start vertex is ="))
    endVertex = int(input("The end vertex is ="))
    if graph.isEdge(startVertex, endVertex):
        graph.removeEdge(startVertex, endVertex)
    else:
        print("The edge doesn't exist")
    return graph


def get_degrees_of_vertex(graph):
    vertex = int(input("The vertex is ="))

    if graph.isVertex(vertex) == False:
        print("The vertex doesn't exist")
        return graph

    indegree = graph.getInDegreeOfAVertex(vertex)
    outdegree = graph.getOutDegreeOfAVertex(vertex)

    print("The indegree of the vertex is", indegree)
    print("The outdegree of a vertex is", outdegree)

    return graph

def print_outbound_edges_of_a_vertex(graph):
    vertex = int(input("The vertex is = "))
    if graph.isVertex(vertex) == False:
        print("The vertex doesn't exist")
        return graph

    edges = graph.getOutboundEdges(vertex)

    print("The outbound edges of the vertex are:")
    for edge in edges:
        print("The edge is", edge[0], edge[1], edge[2])

    return graph

def print_inbound_edges_of_a_vertex(graph):
    vertex = int(input("The vertex is = "))

    if graph.isVertex(vertex) == False:
        print("The vertex doesn't exist")
        return graph

    edges = graph.getInboundEdges(vertex)

    print("The inbound edges of the vertex are:")
    for edge in edges:
        print("The edge is", edge[0], edge[1], edge[2])

    return graph


def retrieve_or_modify_the_cost_of_an_edge(graph):
    startVertex = int(input("The start vertex is = "))
    endVertex = int(input("The end vertex is = "))
    newCostOfEdge = int(input("The new cost of the edge is = "))

    if graph.isEdge(startVertex, endVertex):
        graph.modifyEdge(startVertex, endVertex, newCostOfEdge)
    else:
        print("The edge doesn't exist")
    return graph

def copy_the_graph(graph):
    copyOfGraph = graph.copyGraph()
    return graph

def read_a_graph(graph):
    filename = "graph.in"
    fin = open(filename, "r")
    line = fin.readline().strip()
    line = line.split(" ")
    numberOfVertices = int(line[0])
    numberOfEdges = int(line[1])

    graph.clearAll()
    graph.initialize(numberOfVertices)

    graph = DirectedGraph(numberOfVertices)

    for i in range(numberOfEdges):
        line = fin.readline().strip()
        line = line.split(' ')

        startVertex = int(line[0])
        endVertex = int(line[1])
        costOfEdge = int(line[2])

        graph.addEdge(startVertex, endVertex, costOfEdge)

    return graph


def write_a_graph(graph):
    filename = "graph.out"
    fout = open(filename, "w")

    edges = graph.getAllEdges()

    for edge in edges:
        fout.write(str(edge[0]) + " " + str(edge[1]) + " " + str(edge[2]) + "\n")

    vertices = graph.getAllVertices()

    for vertex in vertices:
        if graph.getOutDegreeOfAVertex(vertex) == 0 or graph.getInDegreeOfAVertex(vertex) == 0:
            fout.write(str(vertex) + " -1" + "\n")

    return graph


def init_random_graph(graph):
    graph.clearAll()

    numberOfVertices = int(input("The number of vetices is = "))
    numberOfEdges = int(input("The number of edges is  = "))

    if numberOfEdges > numberOfVertices * 2:
        return graph

    graph.initialize(numberOfVertices)

    i = 0

    while i < numberOfEdges:
        startVertex = randint(0, numberOfVertices - 1)
        endVertex = randint(0, numberOfVertices - 1)
        costOfEdge = randint(0, 1000)

        if graph.isEdge(startVertex, endVertex) == False:
            graph.addEdge(startVertex, endVertex, costOfEdge)
            i += 1

    return graph

def print_options():
    '''
        function which prints the menu
        :return: -
    '''
    print("1. Get the number of vertices")
    print("2. Iterate the set of vertices")
    print("3. Find if there is an edge between 2 vertices")
    print("4. Check if a given number if a vertex in graph")
    print("5. Add a new edge")
    print("6. Add a new vertex")
    print("7. Remove an edge")
    print("8. Remove a vertex")
    print("9. Get the in degree and out degree of a vertex")
    print("10. Parse the set of outbound edges of a vertex")
    print("11. Parse the set of inbound edges of a vertex")
    print("12. Retrieve or modify the cost of a given edge")
    print("13. Modify the graph")
    print("14. Read a graph from a text file")
    print("15. Write a graph to a text file")
    print("16. Generate a random graph")


def run(commands, graph):
    while True:
        try:
            print_options()
            cmd = input(">>>")
            if cmd in commands:
                graph = commands[cmd](graph)
            else:
                raise ValueError("Invalid command! Please try again!")
        except ValueError as ve:
            print(ve)

if __name__ == '__main__':
    commands = {
        "1": print_number_of_vertices,
        "2": print_set_of_vertices,
        "3": is_edge,
        "4": is_vertex,
        "5": add_edge,
        "6": add_vertex,
        "7": remove_edge,
        "8": remove_vertex,
        "9": get_degrees_of_vertex,
        "10": print_outbound_edges_of_a_vertex,
        "11": print_inbound_edges_of_a_vertex,
        "12": retrieve_or_modify_the_cost_of_an_edge,
        "13": copy_the_graph,
        "14": read_a_graph,
        "15": write_a_graph,
        "16": init_random_graph
    }

    graph = DirectedGraph()

    run(commands, graph)