#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, res = 0;
	int dp[1001][1001] = { 0, };
	cin >> n >> m;
	for (register int i = 1; i <= n; i++) {
		for (register int j = 1; j <= m; j++) {
			int x;
			cin >> x;
			if (x == 0) {
				dp[i][j] = min({ dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] }) + 1;
				res = max(dp[i][j], res);
			}
		}
	}
	cout << res << '\n';
	return 0;
}