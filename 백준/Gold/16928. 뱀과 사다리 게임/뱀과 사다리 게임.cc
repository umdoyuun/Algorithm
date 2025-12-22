#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int n, m;
map<int, int> Map;
int dp[110];

void dfs(int x) {
	if (x > 100) return;
	for (int i = 6; i > 0; i--) {
		int y = x + i;
		if (Map.find(y) != Map.end()) {
			y = Map[y];
		}
		if (!dp[y]) {
			dp[y] = dp[x] + 1;
			dfs(y);
		}
		else if (dp[y] > (dp[x] + 1)) {
			dp[y] = dp[x] + 1;
			dfs(y);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		int x, y;
		cin >> x >> y;
		Map[x] = y;
	}
	dfs(1);
	cout << dp[100];
	return 0;
}