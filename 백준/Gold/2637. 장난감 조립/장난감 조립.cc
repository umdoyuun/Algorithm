#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int n, m;
int indegree[101];
long long res[101];
bool basic[101];
map<int, long long> needs[101];
vector<int> edges[101];

void topology_sort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            basic[i] = true;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto y : edges[x]) {
            indegree[y]--;
            if (!basic[x]) {
                long long x_count = needs[y][x];
                needs[y].erase(x);

                for (auto need : needs[x]) {
                    needs[y][need.first] += need.second * x_count;
                }
            }
            if (!indegree[y]) {
                q.push(y);
            }
        }
    }

    for (auto need : needs[n]) {
        if (basic[need.first]) {
            res[need.first] = need.second;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        needs[x][y] = k;
        edges[y].push_back(x);
        indegree[x]++;
    }

    topology_sort();

    for (int i = 1; i <= n; i++) {
        if (res[i] > 0) {
            cout << i << ' ' << res[i] << '\n';
        }
    }
    return 0;
}