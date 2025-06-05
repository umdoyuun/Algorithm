#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long res;
vector<int> v[123457];
long long arr[123457];

long long dfs(int x, int pre) {
	long long child_sum = 0;

	for (auto y : v[x]) {
		if (y == pre) continue;
		child_sum += dfs(y, x);
	}

	long long total = child_sum + arr[x];
	return max(total, (long long)0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	char c;
	long long cnt;
	int x;
	for (int i = 2; i <= n; i++) {
		cin >> c >> cnt >> x;
		v[i].push_back(x);
		v[x].push_back(i);
		if (c == 'S') {
			arr[i] = cnt;
		}
		else {
			arr[i] = -cnt;
		}
	}
	res = dfs(1, 0);
	cout << res << '\n';
	return 0;
}