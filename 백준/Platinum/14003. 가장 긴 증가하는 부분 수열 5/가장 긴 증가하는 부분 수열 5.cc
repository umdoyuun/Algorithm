#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, cnt;
int arr[1000001];
int dp[1000001];
int res[1000001];
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	v.push_back(arr[1]);
	//dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (v[cnt] < arr[i]) {
			v.push_back(arr[i]);
			cnt++;
			dp[i] = cnt;
		}
		else {
			int tmp = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[tmp] = arr[i];
			dp[i] = tmp;
		}
	}
	int cnt2 = cnt;

	for (int i = n; i >= 0; i--) {
		if (dp[i] == cnt2) {
			res[cnt2] = arr[i];
			cnt2--;
		}
	}
	cout << cnt + 1 << '\n';
	for (int i = 0; i <= cnt; i++) {
		cout << res[i] << ' ';
	}
	return 0;
}