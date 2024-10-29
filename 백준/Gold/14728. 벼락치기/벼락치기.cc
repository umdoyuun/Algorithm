#include <iostream>
#include <algorithm>
using namespace std;

int n, total_time;
int dp[10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> total_time;
	for (int i = 0; i < n; i++) {
		int t, score;
		cin >> t >> score;
		for (int i = total_time; i >= t; i--) {
			dp[i] = max(dp[i - t] + score, dp[i]);
		}
	}
	cout << dp[total_time] << '\n';
	return 0;
}