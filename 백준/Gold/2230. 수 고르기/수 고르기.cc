#include <iostream>
#include <algorithm>
using namespace std;

int n, m, res;
int arr[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (m == 0) {
		cout << 0 << '\n';
		return 0;
	}
	sort(arr, arr + n);
	int s = 0, e = 0;
	res = 0x7fffffff;
	while (e < n) {
		int diff = arr[e] - arr[s];
		if (diff < m) e++;
		else {
			res = min(diff, res);
			s++;
		}
	}
	cout << res << '\n';
	return 0;
}