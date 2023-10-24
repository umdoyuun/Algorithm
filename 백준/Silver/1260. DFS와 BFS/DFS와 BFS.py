from collections import deque

def dfs(graph, v, visited):
    visited[v] = True
    print(v, end = ' ')
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)

def bfs(graph, v, visited):
    queue = deque([v])
    visited[v] = False
    while queue:
        v = queue.popleft()
        print(v, end = ' ')
        for i in graph[v]:
            if visited[i]:
                queue.append(i)
                visited[i] = False

vert, edge, n = map(int, input().split()) #첫째 줄 입력

graph = [[] for i in range(vert + 1)]
visited = [False for i in range(vert+1)]
for i in range(edge):   #둘째 줄 입력
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(vert + 1):
    graph[i].sort(reverse = False) #그래프 내부 정렬

dfs(graph, n, visited)
print()
bfs(graph, n, visited)