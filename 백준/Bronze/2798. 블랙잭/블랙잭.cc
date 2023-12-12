#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, t;
int result;
vector<int> v;
void dfs(int cnt, int idx, int sum) {
	if (cnt == 3) {
		if (sum <= t) result = max(sum, result);
		return;
	}
	for (int i = idx + 1; i < n; i++) {
		dfs(cnt + 1, i, sum + v[i]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	dfs(0, 0, 0);
	cout << result;
	return 0;
}