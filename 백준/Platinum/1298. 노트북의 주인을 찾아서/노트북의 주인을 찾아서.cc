#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 101

int n, m, res;
int d[MAX];
vector<int> v[MAX];
bool visit[MAX];

bool dfs(int x) {
	if (visit[x]) return false;
	visit[x] = true;
	for (int y : v[x]) {
		if (d[y] == 0 || dfs(d[y])) {
			d[y] = x;
			return true;
		}
	}
	return false;
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
	}
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		if (dfs(i)) res++;
	}
	cout << res << '\n';
	return 0;
}