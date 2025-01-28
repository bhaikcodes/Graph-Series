import java.util.*;

class CycleDetectionDFS {
    public static void main(String[] args) {
        int V = 5; // Number of vertices
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

        // Initialize adjacency list
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        // Add edges
        adj.get(0).add(1);
        adj.get(1).add(0);
        adj.get(1).add(2);
        adj.get(1).add(4);
        adj.get(2).add(1);
        adj.get(2).add(3);
        adj.get(3).add(2);
        adj.get(3).add(4);
        adj.get(4).add(1);
        adj.get(4).add(3);

        boolean hasCycle = isCycle(V, adj);

        System.out.println("CYCLE DETECTED: " + hasCycle);
    }

    public static boolean isCycle(int V, ArrayList<ArrayList<Integer>> adj) {
        boolean[] visited = new boolean[V];

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(adj, visited, i, -1)) {
                    return true;
                }
            }
        }
        return false;
    }

    private static boolean dfs(ArrayList<ArrayList<Integer>> adj, boolean[] visited, int a, int parent) {
        visited[a] = true;

        for (int x : adj.get(a)) {
            if (!visited[x]) {
                if (dfs(adj, visited, x, a)) {
                    return true;
                }
            } else if (x != parent) {
                return true;
            }
        }
        return false;
    }
}


// OUTPUT:
// CYCLE DETECTED: true