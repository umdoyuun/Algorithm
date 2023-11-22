#include <iostream>
using namespace std;

int n;
long long dp[91];

long long fibo(int x) {
	if (x == 0) return dp[0] = 0;
	else if (x == 1) return dp[1] = 1;
	else if (dp[x] == 0) return dp[x] = fibo(x - 1) + fibo(x - 2);
	else return dp[x];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	fibo(n);
	cout << dp[n];
	return 0;
}