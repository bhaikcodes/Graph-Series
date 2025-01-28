import java.util.*;

class CycleDetectionBFS {
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

        System.out.println("CYCLE DTETECTED: " + hasCycle);
    }

    public static boolean isCycle(int V, ArrayList<ArrayList<Integer>> adj) {
        boolean[] visited = new boolean[V];
        int[] parent = new int[V];
        Arrays.fill(parent, -1);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (checkCycle(i, visited, parent, adj)) {
                    return true;
                }
            }
        }
        return false;
    }

    private static boolean checkCycle(int start, boolean[] visited, int[] parent, ArrayList<ArrayList<Integer>> adj) {
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        visited[start] = true;

        while (!q.isEmpty()) {
            int a = q.poll();

            for (int x : adj.get(a)) {
                if (!visited[x]) {
                    q.add(x);
                    visited[x] = true;
                    parent[x] = a;
                } else if (x != parent[a]) {
                    return true;
                }
            }
        }
        return false;
    }
}


// OUTPUT: 
// CYCLE DTETECTED: true
