class UI(object):
    def __init__(self):
        self._commands = {
            "1":self._ui_print_number_of_vertices,
            "2":self._ui_print_set_of_vertices,
            "3":self._ui_is_edge,
            "4":self._ui_get_degrees_of_vertex,
            "5":self._ui_print_outbound_edges_of_a_vertex,
            "6":self._ui_print_inbound_edges_of_a_vertex,
            "7":self._ui_retrieve_or_modify_the_cost_of_an_edge,
            "8":self._ui_modify_the_graph,
            "9":self.ui_read_a_graph,
            "10":self._ui_write_a_graph
        }

    def _ui_print_number_of_vertices(self):
        pass

    def _ui_print_set_of_vertices(self):
        pass

    def _ui_is_edge(self):
        pass

    def _ui_get_degrees_of_vertex(self):
        pass

    def _ui_print_outbound_edges_of_a_vertex(self):
        pass

    def _ui_print_inbound_edges_of_a_vertex(self):
        pass

    def _ui_retrieve_or_modify_the_cost_of_an_edge(self):
        pass

    def _ui_modify_the_grapth(self):
        pass

    def _ui_print_options(self):
        '''
            function which prints the menu
            :return: -
        '''
        print("1. Get the number of vertices")
        print("2. Iterate the set of vertices")
        print("3. Find if there is an edge between 2 vertices")
        print("4. Get the in degree and out degree of a vertex")
        print("5. Parse the set of outbound edges of a vertex")
        print("6. Parse the set of inbound edges of a vertex")
        print("7. Retrieve or modify the cost of a given edge")
        print("8. Modify the graph")
        print("9. Read a graph from a text file")
        print("10. Write a graph to a text file")

    def run(self):
        while True:
            try:
                self._ui_print_options()
                cmd = input(">>>")
                if cmd in self._commands:
                    self._commands[cmd]()
                else:
                    raise ValueError("Invalid command! Please try again!")
            except ValueError as ve:
                print(ve)