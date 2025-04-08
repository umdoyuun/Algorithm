#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, k1, k2, res, cnt;
vector<int> v[2][301];
int visit[301];
int d[301];

bool dfs(int x, int team) {
	if (visit[x] == cnt) return false;
	visit[x] = cnt;
	for (auto y : v[team][x]) {
		if (d[y] == 0) {
			d[y] = x;
			return true;
		}
	}
	for (auto y : v[team][x]) {
		if (dfs(d[y], team)) {
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
	cin >> n >> m >> k1 >> k2;
	for (int i = 0;i < k1; i++) {
		int x, y;
		cin >> x >> y;
		v[0][x].push_back(y);
	}
	for (int i = 0; i < k2; i++) {
		int x, y;
		cin >> x >> y;
		v[1][x].push_back(y);
	}
	for (int i = 1; i <= n; i++) {
		cnt++;
		if (dfs(i, 0)) res++;
	}
	memset(d, 0, sizeof(d));
	for (int i = 1; i <= n; i++) {
		cnt++;
		if (dfs(i, 1)) res--;
		if (res < 0) break;
	}
	if (res < 0) cout << "네 다음 힐딱이\n";
	else cout << "그만 알아보자\n";

	return 0;
}