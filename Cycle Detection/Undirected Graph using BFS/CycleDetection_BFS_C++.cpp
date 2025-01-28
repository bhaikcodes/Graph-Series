#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

bool checkCycle(int start, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& parent) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int a = q.front();
        q.pop();

        for (int x : adj[a]) {
            if (!visited[x]) {
                q.push(x);
                visited[x] = true;
                parent[x] = a;
            } else if (x != parent[a]) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (checkCycle(i, adj, visited, parent)) {
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

    cout << "CYCLE DTETECTED: " << (isCycle(V, adj) ? "Yes" : "No") << endl;
    return 0;
}


// OUTPUT: 
// CYCLE DTETECTED: Yes
