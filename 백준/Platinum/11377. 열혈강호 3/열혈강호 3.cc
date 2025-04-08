#include <iostream>
#include <vector>
using namespace std;

int n, m, k, res;
int d[1001];
vector<int> v[1001];
bool visit[1001];

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
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		int s, x;
		cin >> s;
		for (int j = 0; j < s; j++) {
			cin >> x;
			v[i].push_back(x);
		}
	}
	for (int i = 1; i <= n; i++) {
		fill(visit, visit + n + 1, false);
		if (dfs(i)) res++;
		if (res == m) break;
	}
	for (int i = 1; i <= n; i++) {
		if (!k || res == m) break;
		fill(visit, visit + n + 1, false);
		if (dfs(i)) {
			res++;
			k--;
		}
	}
	cout << res << '\n';
	return 0;
}