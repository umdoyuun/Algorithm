#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class node {
public:
    int x, y, cost;
};

int n, m, min_res;
int par[1001];
vector<int> costs;

vector<node> v;
vector<pair<int, int>> path[1001];

bool cmp(node a, node b) {
    return a.cost < b.cost;
}

int getPar(int x) {
    if (x == par[x]) return x;
    else return par[x] = getPar(par[x]);
}

bool unionPar(int x, int y) {
    x = getPar(x);
    y = getPar(y);
    if (x == y) return false;
    par[y] = x;
    return true;
}

pair<int, int> dfs(int x, int pre, int c) {
    pair<int, int> max_path = { x, c };
    bool flag = true;
    for (auto next : path[x]) {
        if (next.first == pre) continue;
        flag = false;
        pair<int, int> ret = dfs(next.first, x, c + next.second);
        if (ret.second > max_path.second) {
            max_path = ret;
        }
    }
    return max_path;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int x, y, cost;
        cin >> x >> y >> cost;
        v.push_back({ x, y, cost });
    }
    sort(v.begin(), v.end(), cmp);
    int cnt = 1;
    for (auto edge : v) {
        if (unionPar(edge.x, edge.y)) {
            min_res += edge.cost;
            path[edge.x].push_back({ edge.y, edge.cost });
            path[edge.y].push_back({ edge.x, edge.cost });
            cnt++;
            if (cnt == n) break;
        }
    }
    pair<int, int> ret_f = dfs(0, -1, 0);
    pair<int, int> ret_s = dfs(ret_f.first, -1, 0);
    
    cout << min_res << '\n' << ret_s.second << '\n';
    return 0;
}