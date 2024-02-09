#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];
int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		int cnt = upper_bound(arr, arr + n, x) - lower_bound(arr, arr + n, x);
		cout << cnt << ' ';
	}
	return 0;
}