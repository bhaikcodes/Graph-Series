class GraphAdjList:
    def __init__(self, num_vertices):
        self.num_vertices = num_vertices
        self.adj_list = [[] for _ in range(num_vertices)]

    def add_edge(self, i, j):
        self.adj_list[i].append(j)
        self.adj_list[j].append(i)  # For undirected graph

    def print_graph(self):
        for i in range(self.num_vertices):
            print(f"Vertex {i}:", " -> ".join(map(str, self.adj_list[i])))

if __name__ == "__main__":
    graph = GraphAdjList(6)
    graph.add_edge(0, 1)
    graph.add_edge(0, 2)
    graph.add_edge(1, 2)
    graph.add_edge(2, 3)
    graph.add_edge(4, 5)

    graph.print_graph()



#   >>> OUTPUT <<<
#
#  Vertex 0: 1 -> 2
#  Vertex 1: 0 -> 2
#  Vertex 2: 0 -> 1 -> 3
#  Vertex 3: 2
#  Vertex 4: 5
#  Vertex 5: 4
