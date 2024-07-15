#include <iostream>
#include <vector>
#include <list>

class GraphAdjList {
private:
    std::vector<std::list<int>> adjList;
    int numVertices;

public:
    GraphAdjList(int numVertices) {
        this->numVertices = numVertices;
        adjList.resize(numVertices);
    }

    void addEdge(int i, int j) {
        adjList[i].push_back(j);
        adjList[j].push_back(i); // For undirected graph
    }

    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            std::cout << "Vertex " << i << ":";
            for (auto v : adjList[i]) {
                std::cout << " -> " << v;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    GraphAdjList graph(6);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(4, 5);

    graph.printGraph();
    return 0;
}

/*
*   >>> OUTPUT <<<
*
*  Vertex 0: 1 -> 2
*  Vertex 1: 0 -> 2
*  Vertex 2: 0 -> 1 -> 3
*  Vertex 3: 2
*  Vertex 4: 5
*  Vertex 5: 4
*/
