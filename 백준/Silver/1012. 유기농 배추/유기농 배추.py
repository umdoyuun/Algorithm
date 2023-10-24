import sys
sys.setrecursionlimit(10000)

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def dfs(graphlist, x, y, visitedlist, n):   #dfs, 좌표는 n, x, y
    visitedlist[n][x][y] = True     #방문
    for i in range(4):
        ax = x + dx[i]      
        ay = y + dy[i]
        if ax >= 0 and ax < xlist[n] and ay >= 0 and ay < ylist[n]:         #좌표 앞뒤 양옆이 케이스를 벗어나지는 않는지
            if not visitedlist[n][ax][ay] and graphlist[n][ax][ay] == 1:        #좌표 앞뒤 양옆에 방문을 했는지, 배추가 있는지
                dfs(graphlist, ax, ay, visitedlist, n)                          #있으면 재귀


num = int(input())
xlist, ylist, slist = [], [], []
graphlist = [[] for i in range(num)]
visitedlist = [[] for i in range(num)]
countlist = []
count = 0

for i in range(num):
    a, b, c = map(int, input().split())
    xlist.append(a)               #x, y, s list에 케이스 크기, 배추 개수 저장
    ylist.append(b)
    slist.append(c)
    graph = [[0 for q in range(b)] for w in range(a)]        #케이스 크기에 맞게 0으로 초기화
    visited = [[False for q in range(b)] for w in range(a)]     #방문 False로 초기화
    for j in range(c):
        a1, b1 = map(int, input().split())  #입력
        graph[a1][b1] = 1                   #배추 위치 1로 변경
    graphlist[i] = graph            #케이스 개수만큼 list에 추가
    visitedlist[i] = visited        #케이스 개수만큼 list에 추가
    graph = []
    visited = []
    
            
for n in range(num):    #케이스 수 대로
    for i in range(xlist[n]):
        for j in range(ylist[n]):
            if not visitedlist[n][i][j] and graphlist[n][i][j] == 1:    #방문 안했고, 배추 있을 때
                dfs(graphlist, i, j, visitedlist, n)    #dfs
                count += 1
    countlist.append(count)     #리스트에 count 추가
    count = 0           #count 초기화
for i in range(len(countlist)): #count 수 차례대로 출력
    print(countlist[i])
