#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[501];
vector<int> lis;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		arr[x] = y;
	}
	for (int i = 0; i <= 500; i++) {
		if (arr[i]) {
			auto pos = lower_bound(lis.begin(), lis.end(), arr[i]);
			if (pos == lis.end()) {
				lis.push_back(arr[i]);
			}
			else {
				*pos = arr[i];
			}
		}
	}
	int res = n - lis.size();
	cout << res << '\n';
	return 0;
}