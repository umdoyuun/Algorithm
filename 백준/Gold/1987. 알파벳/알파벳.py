import sys
sys.setrecursionlimit(100000)

dx = [0,0,1,-1]
dy = [1,-1,0,0]
result = 0

def dfs(x, y, cnt):
    global result
    result = max(cnt, result)
    visited[graph[x][y]] = 1
    for i in range(4):
        ax = x+dx[i]
        ay = y+dy[i]
        if r > ax >= 0 and c > ay >= 0:
            if visited[graph[ax][ay]] == -1:
                dfs(ax, ay, cnt+1)
                visited[graph[ax][ay]] = -1

visited = [-1 for i in range(26)]

r,c = map(int, input().split())
graph = [[0 for i in range(c)] for j in range(r)]
for i in range(r):
    str1 = input()
    for j in range(c):
        graph[i][j] = ord(str1[j]) - ord('A')

dfs(0,0,1)
print(result)