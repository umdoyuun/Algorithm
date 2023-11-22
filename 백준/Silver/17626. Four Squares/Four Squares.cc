#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int dp[50001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = i;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		int x = i * i;
		for (int j = x; j <= n; j++) {
			dp[j] = min(dp[j], 1 + dp[j - x]);
		}
	}
	cout << dp[n];
	return 0;
}