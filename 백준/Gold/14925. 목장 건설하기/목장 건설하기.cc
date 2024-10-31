#include <iostream>
#include <algorithm>
using namespace std;

int n, m, res;
int map[1001][1001];
int dp[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				dp[i][j] = min({ dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] }) + 1;
				res = max(dp[i][j], res);
			}
		}
	}
	cout << res << '\n';
	return 0;
}