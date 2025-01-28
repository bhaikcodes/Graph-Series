#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>>& graph, vector<bool>& visited, int start, vector<int>& result) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
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
    vector<int> result;

    // Perform BFS for all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(graph, visited, i, result);
        }
    }

    // Print BFS Traversal
    cout << "BFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}


//OUTPUT:
//BFS Traversal: [0, 5, 1, 2, 3, 6, 4]