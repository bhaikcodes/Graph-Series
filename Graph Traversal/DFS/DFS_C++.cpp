#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& visited, int node) {
    if (visited[node]) return;

    visited[node] = true;
    cout << node << " "; // Print the current node

    for (int neighbor : adj[node]) {
        dfs(adj, visited, neighbor); // Recur for all connected nodes
    }
}

int main() {
    int n = 7; // Number of nodes (0 to 6)
    vector<vector<int>> graph(n);

    // Add edges
    graph[0].push_back(5);
    graph[1].push_back(2);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[2].push_back(6);
    graph[3].push_back(2);
    graph[3].push_back(4);
    graph[4].push_back(3);
    graph[4].push_back(6);
    graph[5].push_back(0);
    graph[6].push_back(2);
    graph[6].push_back(4);

    vector<bool> visited(n, false);
    cout << "DFS Traversal:" << endl;

    // Perform DFS for all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(graph, visited, i);
        }
    }

    return 0;
}


// OUTPUT:
// DFS Traversal:
// 0 5 1 2 3 4 6 