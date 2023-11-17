#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int c, n, result = 0x7fffffff;
int dp[100001];
vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n;
	for (int i = 0; i < n; i++) {
		int cost, p;
		cin >> cost >> p;
		for (int j = cost; j <= c * 100; j++) {
			dp[j] = max(dp[j], dp[j - cost] + p);
			if (dp[j] >= c)
				result = min(result, j);
		}
	}
	cout << result;
	return 0;
}