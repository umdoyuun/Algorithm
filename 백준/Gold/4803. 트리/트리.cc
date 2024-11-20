#include <iostream>
#include <vector>
using namespace std;

int n, m, res;
vector<int> v[501];
bool visit[501];
bool flag;

void init() {
	for (int i = 1; i <= n; i++) {
		v[i].clear();
		visit[i] = false;
	}
	res = 0;
}

void dfs(int x, int pre) {
	if (visit[x]) {
		flag = true;
		return;
	}
	visit[x] = true;
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (y == pre) continue;
		dfs(y, x);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc = 0;
	while (true) {
		tc++;
		init();
		cin >> n >> m;
		if (!n && !m) break;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				flag = false;
				dfs(i, 0);
				if (!flag) res++;
			}
		}
		if (res == 1) {
			cout << "Case " << tc << ": There is one tree.\n";
		}
		else if (res == 0) {
			cout << "Case " << tc << ": No trees.\n";
		}
		else {
			cout << "Case " << tc << ": A forest of " << res << " trees.\n";
		}
	}
	return 0;
}