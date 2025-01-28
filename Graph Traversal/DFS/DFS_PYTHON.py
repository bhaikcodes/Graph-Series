def dfs(graph, visited, node):
    if visited[node]:
        return

    visited[node] = True
    print(node, end=" ")  # Print the current node

    for neighbor in graph[node]:
        dfs(graph, visited, neighbor)  # Recur for all connected nodes


# Number of nodes (0 to 6)
n = 7
graph = [[] for _ in range(n)]

# Add edges
graph[0].append(5)
graph[1].append(2)
graph[2].extend([1, 3, 6])
graph[3].extend([2, 4])
graph[4].extend([3, 6])
graph[5].append(0)
graph[6].extend([2, 4])

visited = [False] * n
print("DFS Traversal:")

# Perform DFS for all components
for i in range(n):
    if not visited[i]:
        dfs(graph, visited, i)


# OUTPUT:
# DFS Traversal:
# 0 5 1 2 3 4 6 