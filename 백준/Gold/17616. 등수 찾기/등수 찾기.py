from collections import deque

def bfs(graph, start, visited):
    z=1
    queue = deque()
    queue.append(x)
    visited[x] = True

    while queue:
        v = queue.popleft()
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True
                z += 1
    return z

n, m, x = map(int, input().split())
up = [[] for i in range(n+1)]
down = [[] for i in range(n+1)]
visited = [False] * (n+1)

for i in range(m):
    a, b = map(int, input().split())
    up[a].append(b)
    down[b].append(a)


                
print(bfs(down, x, visited), end = ' ')
visited = []
visited = [False] * (n+1)
print(n - bfs(up, x, visited) + 1)