#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> lis;
int dp[1001], res[1001], arr[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	lis.reserve(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		auto pos = lower_bound(lis.begin(), lis.end(), arr[i]);
		if (pos == lis.end()) {
			dp[i] = lis.size();
			lis.push_back(arr[i]);
		}
		else {
			*pos = arr[i];
			dp[i] = pos - lis.begin();
		}
	}
	int tmp = lis.size() - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (dp[i] == tmp) {
			res[tmp--] = arr[i];
		}
	}
	cout << lis.size() << '\n';
	for (int i = 0; i < lis.size(); i++) {
		cout << res[i] << ' ';
	}
	return 0;
}