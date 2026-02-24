#include <iostream>
using namespace std;

const int mx = 10007;

int n;
int dp[1001][10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < 10; i++) {
		dp[0][i] = 10 - i;
	}
	for (int i = 1; i < n; i++) {
		dp[i][9] = dp[i - 1][9];
		for (int j = 8; j >= 0; j--) {
			dp[i][j] = (dp[i][j + 1] + dp[i - 1][j]) % mx;
		}
	}
	cout << dp[n - 1][0];
	return 0;
}