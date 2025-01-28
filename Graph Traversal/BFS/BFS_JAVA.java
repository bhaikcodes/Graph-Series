import java.util.*;

class BFSExample {
    public static void main(String[] args) {
        int n = 7; // Number of nodes (0 to 6)
        List<List<Integer>> graph = new ArrayList<>();
        
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

        // Perform BFS for all components
        List<Integer> result = new ArrayList<>();
        boolean[] visited = new boolean[n];

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                result.addAll(bfs(graph, visited, i));
            }
        }

        System.out.println("BFS Traversal: " + result);
    }

    public static List<Integer> bfs(List<List<Integer>> graph, boolean[] visited, int start) {
        Queue<Integer> queue = new LinkedList<>();
        List<Integer> ans = new ArrayList<>();

        queue.add(start);
        visited[start] = true;

        while (!queue.isEmpty()) {
            int node = queue.poll();
            ans.add(node);

            for (int neighbor : graph.get(node)) {
                if (!visited[neighbor]) {
                    queue.add(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        
        return ans;
    }
}

//OUTPUT:
//BFS Traversal: [0, 5, 1, 2, 3, 6, 4]