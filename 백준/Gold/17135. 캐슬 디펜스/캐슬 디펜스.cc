#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, d, ret;
vector<pair<int, int>> enemy;

struct Target {
    int dist, col, idx;
    bool operator<(const Target& other) const {
        if (dist != other.dist) return dist > other.dist;
        return col > other.col;
    }
};

int findTarget(int archer_col, int move, vector<bool>& killed) {
    priority_queue<Target> pq;

    for (int i = 0; i < enemy.size(); i++) {
        if (killed[i]) continue;

        int enemy_row = enemy[i].first + move;
        int enemy_col = enemy[i].second;

        if (enemy_row >= n) continue;

        int dist = abs(n - enemy_row) + abs(archer_col - enemy_col);

        if (dist <= d) {
            pq.push({ dist, enemy_col, i });
        }
    }

    if (!pq.empty()) {
        return pq.top().idx;
    }
    return -1;
}

int func(int a, int b, int c) {
    int res = 0, move = 0;
    vector<bool> killed(enemy.size(), false);

    while (true) {
        bool hasEnemy = false;
        for (int i = 0; i < enemy.size(); i++) {
            if (!killed[i] && enemy[i].first + move < n) {
                hasEnemy = true;
                break;
            }
        }
        if (!hasEnemy) break;

        vector<int> targets;
        targets.push_back(findTarget(a, move, killed));
        targets.push_back(findTarget(b, move, killed));
        targets.push_back(findTarget(c, move, killed));

        for (int target : targets) {
            if (target != -1 && !killed[target]) {
                killed[target] = true;
                res++;
            }
        }

        move++;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val;
            cin >> val;
            if (val == 1) {
                enemy.push_back({ i, j });
            }
        }
    }

    for (int a = 0; a < m - 2; a++) {
        for (int b = a + 1; b < m - 1; b++) {
            for (int c = b + 1; c < m; c++) {
                ret = max(ret, func(a, b, c));
            }
        }
    }

    cout << ret << '\n';
    return 0;
}