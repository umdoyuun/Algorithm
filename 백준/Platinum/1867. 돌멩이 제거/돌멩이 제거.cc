#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, k;
vector<int> v[501];
bool check[501], visit[501];
int d[501];

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
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		check[x] = true;
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (!check[i]) continue;
		memset(visit, false, sizeof(visit));
		if (dfs(i)) res++;
	}
	cout << res << '\n';
	return 0;
}