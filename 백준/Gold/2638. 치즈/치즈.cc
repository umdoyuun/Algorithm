#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 105;

int n, m, res, cnt;
int graph[MAX][MAX];
int visit[MAX][MAX];
vector<pair<int, int>> clist;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx > n || ny > m) continue;
        if (visit[nx][ny]) {
            if (graph[nx][ny] && visit[nx][ny] == 1) {
                visit[nx][ny]++;
                clist.push_back({ nx, ny });
            }
            continue;
        }
        visit[nx][ny] = 1;
        if (graph[nx][ny] == 1) continue;        
        dfs(nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> graph[i][j];
            if (graph[i][j]) cnt++;
        }
    }
    while (cnt) {
        clist.clear();
        memset(visit, 0, sizeof(visit));
        res++;
        visit[0][0] = 1;
        dfs(0, 0);
        cnt -= clist.size();
        for (auto p : clist) {
            graph[p.first][p.second] = 0;
        }
    }
    cout << res << '\n';
    return 0;
}