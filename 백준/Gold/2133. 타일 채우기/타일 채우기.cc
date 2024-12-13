#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		int sum = dp[i - 2] * 3;
		for (int j = 4; j <= i; j += 2) {
			sum += dp[i - j] * 2;
		}
		dp[i] = sum;
	}
	cout << dp[n];
	return 0;
}