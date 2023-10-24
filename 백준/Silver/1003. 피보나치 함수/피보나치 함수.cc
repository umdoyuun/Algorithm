#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int cnt1, cnt0;
int dp[42];

void init() {
	memset(dp, -1, sizeof(dp));
	cnt1 = 0;
	cnt0 = 0;
}

int fibo(int n) {
	if (n == 0) {
		return dp[0] = 0;
	}
	if (n == 1)
		return dp[1] = 1;
	if (dp[n] == -1)
		return dp[n] = fibo(n - 1) + fibo(n - 2);
	
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T, x;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		init();
		cin >> x;
		if (x == 0)
			cout << "1 0" << '\n';
		else
			cout << fibo(x - 1) << ' ' << fibo(x) << '\n';
	}
	return 0;
}