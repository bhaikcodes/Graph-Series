import java.util.LinkedList;

public class GraphAdjList {
    private LinkedList<Integer>[] adjList;
    private int numVertices;

    public GraphAdjList(int numVertices) {
        this.numVertices = numVertices;
        adjList = new LinkedList[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjList[i] = new LinkedList<>();
        }
    }

    public void addEdge(int i, int j) {
        adjList[i].add(j);
        adjList[j].add(i); // For undirected graph
    }

    public void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            System.out.print("Vertex " + i + ":");
            for (Integer v : adjList[i]) {
                System.out.print(" -> " + v);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        GraphAdjList graph = new GraphAdjList(6);
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 2);
        graph.addEdge(2, 3);
        graph.addEdge(4, 5);

        graph.printGraph();
    }
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
