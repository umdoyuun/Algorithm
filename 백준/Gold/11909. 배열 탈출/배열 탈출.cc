#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int arr[2223][2223];
int dp[2223][2223];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		arr[0][i] = arr[1][i] + 1;
		arr[i][0] = arr[i][1] + 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 && j == 1) continue;
			int x = 0, y = 0;
			if (i == 1) y = 1e9;
			if (j == 1) x = 1e9;
			if (arr[i - 1][j] <= arr[i][j]) y = arr[i][j] - arr[i - 1][j] + 1;
			if (arr[i][j - 1] <= arr[i][j]) x = arr[i][j] - arr[i][j - 1] + 1;
			dp[i][j] = min(dp[i - 1][j] + y, dp[i][j - 1] + x);
		}
	}
	int ret = dp[n][n];
	cout << ret << '\n';
	return 0;
}