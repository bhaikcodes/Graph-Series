#include <iostream>
#include <vector>

class GraphAdjMatrix {
private:
    std::vector<std::vector<int>> adjMatrix;
    int numVertices;

public:
    GraphAdjMatrix(int numVertices) {
        this->numVertices = numVertices;
        adjMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
    }

    void addEdge(int i, int j) {
        adjMatrix[i][j] = 1;
        adjMatrix[j][i] = 1; // For undirected graph
    }

    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    GraphAdjMatrix graph(6);
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
*  0 1 1 0 0 0 
*  1 0 1 0 0 0 
*  1 1 0 1 0 0 
*  0 0 1 0 0 0 
*  0 0 0 0 0 1 
*  0 0 0 0 1 0 
*/

