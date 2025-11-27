#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, res = 1;
vector<int> arr;
int dp[10010], lis[1001], r_lis[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	arr.reserve(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	lis[0] = arr[0];
	int size = 1;
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		if (lis[size - 1] < arr[i]) {
			lis[size] = arr[i];
			dp[i] = ++size;
		}
		else {
			int pos = lower_bound(lis, lis + size, arr[i]) - lis;
			lis[pos] = arr[i];
			dp[i] = pos + 1;
		}
		res = max(res, dp[i]);
	}
	size = 1;
	r_lis[0] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (r_lis[size - 1] < arr[i]) {
			r_lis[size] = arr[i];
			dp[i] += size++;
		}
		else {
			int pos = lower_bound(r_lis, r_lis + size, arr[i]) - r_lis;
			r_lis[pos] = arr[i];
			dp[i] += pos;
		}
		res = max(res, dp[i]);
	}
	cout << res;
	return 0;
}