#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;

    for (int x : adj[node]) {
        if (!visited[x]) {
            if (dfs(x, node, adj, visited)) {
                return true;
            }
        } else if (x != parent) {
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> adj(V);

    // Add edges
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[1].push_back(4);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(1);
    adj[4].push_back(3);

    cout << "CYCLE DETECTED: " << (isCycle(V, adj) ? "Yes" : "No") << endl;
    return 0;
}


// OUTPUT:
// CYCLE DETECTED: Yes