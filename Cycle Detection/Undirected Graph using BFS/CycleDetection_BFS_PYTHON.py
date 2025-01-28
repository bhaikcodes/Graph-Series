from collections import deque

def check_cycle(start, visited, parent, adj):
    q = deque([start])
    visited[start] = True

    while q:
        a = q.popleft()

        for x in adj[a]:
            if not visited[x]:
                q.append(x)
                visited[x] = True
                parent[x] = a
            elif x != parent[a]:
                return True
    return False

def is_cycle(V, adj):
    visited = [False] * V
    parent = [-1] * V

    for i in range(V):
        if not visited[i]:
            if check_cycle(i, visited, parent, adj):
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
# CYCLE DETECTED:  True
