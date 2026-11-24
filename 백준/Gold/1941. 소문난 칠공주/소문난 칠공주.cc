#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

char graph[5][5];
bool visited[5][5];
unordered_set<int> seen;
vector<pair<int, int>> v;
int B, sCnt, yCnt, res;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void add(int x, int y) {
    visited[x][y] = true;
    B |= 1 << (x * 5 + y);
    if (graph[x][y] == 'S') sCnt++;
    else yCnt++;
    v.push_back({ x, y });
}

void remove(int x, int y) {
    visited[x][y] = false;
    B &= ~(1 << (x * 5 + y));
    if (graph[x][y] == 'S') sCnt--;
    else yCnt--;
    v.pop_back();
}

void dfs() {
    if (yCnt > 3 || seen.count(B)) return;
    seen.insert(B);

    if (sCnt + yCnt == 7) {
        res++;
        return;
    }

    int sz = v.size();
    for (int k = 0; k < sz; k++) {
        int x = v[k].first, y = v[k].second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || visited[nx][ny]) continue;
            add(nx, ny);
            dfs();
            remove(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            add(i, j);
            dfs();
            remove(i, j);
        }
    }

    cout << res << '\n';
    return 0;
}