#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, res;
vector<int> v[501];
bool visit[501];

void bfs() {
    queue<pair<int, int>> q;
    q.push({ 1, 0 });
    visit[1] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int cnt = q.front().second;
        res++;
        q.pop();
        for (int y : v[x]) {
            if (visit[y] || cnt > 1) continue;
            visit[y] = true;;
            q.push({ y, cnt + 1 });
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs();
    cout << res - 1 << '\n';
    return 0;
}