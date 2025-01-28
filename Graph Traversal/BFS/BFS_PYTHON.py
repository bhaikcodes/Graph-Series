from collections import deque

def bfs(graph, visited, start):
    queue = deque([start])
    visited[start] = True
    result = []

    while queue:
        node = queue.popleft()
        result.append(node)

        for neighbor in graph[node]:
            if not visited[neighbor]:
                queue.append(neighbor)
                visited[neighbor] = True

    return result

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
result = []

# Perform BFS for all components
for i in range(n):
    if not visited[i]:
        result.extend(bfs(graph, visited, i))

print("BFS Traversal:", result)

# OUTPUT:
# BFS Traversal: [0, 5, 1, 2, 3, 6, 4]
