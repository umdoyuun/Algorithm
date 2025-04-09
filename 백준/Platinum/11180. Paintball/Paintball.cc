#include <iostream>
#include <vector>
using namespace std;

vector<int> v[1001];
int d[1001], visit[1001], cnt;

bool dfs(int x) {
	if (visit[x] == cnt) return false;
	visit[x] = cnt;
	for (auto y : v[x]) {
		if (d[y] == 0) {
			d[y] = x;
			return true;
		}
	}
	for (auto y : v[x]) {
		if (dfs(d[y])) {
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
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int match = 0;
	for (int i = 1; i <= n; i++) {
		cnt++;
		if (dfs(i)) match++;
	}
	if (match == n) {
		for (int i = 1; i <= n; i++) {
			cout << d[i] << '\n';
		}
	}
	else {
		cout << "Impossible\n";
	}
	return 0;
}