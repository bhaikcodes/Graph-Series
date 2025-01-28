def dfs(node, parent, adj, visited):
    visited[node] = True

    for x in adj[node]:
        if not visited[x]:
            if dfs(x, node, adj, visited):
                return True
        elif x != parent:
            return True
    return False

def is_cycle(V, adj):
    visited = [False] * V

    for i in range(V):
        if not visited[i]:
            if dfs(i, -1, adj, visited):
                return True
    return False

# Example graph
V = 5
adj = [[] for _ in range(V)]
adj[0].append(1)
adj[1].extend([0, 2, 4])
adj[2].extend([1, 3])
adj[3].extend([2, 4])
adj[4].extend([1, 3])

print("CYCLE DETECTED: ", is_cycle(V, adj))

# OUTPUT:
# CYCLE DETECTED: True