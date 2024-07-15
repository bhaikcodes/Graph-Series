class GraphAdjMatrix:
    def __init__(self, num_vertices):
        self.num_vertices = num_vertices
        self.adj_matrix = [[0] * num_vertices for _ in range(num_vertices)]

    def add_edge(self, i, j):
        self.adj_matrix[i][j] = 1
        self.adj_matrix[j][i] = 1  # For undirected graph

    def print_graph(self):
        for row in self.adj_matrix:
            print(" ".join(map(str, row)))

if __name__ == "__main__":
    graph = GraphAdjMatrix(6)
    graph.add_edge(0, 1)
    graph.add_edge(0, 2)
    graph.add_edge(1, 2)
    graph.add_edge(2, 3)
    graph.add_edge(4, 5)

    graph.print_graph()


#   >>> OUTPUT <<<
#
#  0 1 1 0 0 0 
#  1 0 1 0 0 0 
#  1 1 0 1 0 0 
#  0 0 1 0 0 0 
#  0 0 0 0 0 1 
#  0 0 0 0 1 0 

