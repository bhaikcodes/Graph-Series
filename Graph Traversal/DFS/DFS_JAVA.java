import java.util.*;

class Main {
    public static void main(String[] args) {
        int n = 7; // Number of nodes (0 to 6)
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();

        // Initialize adjacency list
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        // Add edges
        graph.get(0).add(5);
        graph.get(1).add(2);
        graph.get(2).add(1);
        graph.get(2).add(3);
        graph.get(2).add(6);
        graph.get(3).add(2);
        graph.get(3).add(4);
        graph.get(4).add(3);
        graph.get(4).add(6);
        graph.get(5).add(0);
        graph.get(6).add(2);
        graph.get(6).add(4);

        // Perform DFS for all components
        boolean[] visited = new boolean[n];
        System.out.print("DFS Traversal: ");

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(graph, visited, i);
            }
        }
    }

    public static void dfs(ArrayList<ArrayList<Integer>> adj, boolean[] visited, int a) {
        if (visited[a]) return;

        visited[a] = true;
        System.out.print(a + " "); // Print the current node

        for (int x : adj.get(a)) {
            dfs(adj, visited, x); // Recur for all connected nodes
        }
    }
}

// OUTPUT:
// DFS Traversal: 0 5 1 2 3 4 6 
