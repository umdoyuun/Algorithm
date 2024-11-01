#include <iostream>
#include <algorithm>
using namespace std;

int n, res;
pair<int, int> arr[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (register int i = 0; i < n; i++) {
		int x, y;
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + n);
	int e = -1000000001;
	for (register int i = 0; i < n; i++) {
		int x = arr[i].first;
		int y = arr[i].second;
		if (e > y) continue;
		if (x > e) e = x;
		res += y - e;
		e = y;
	}
	cout << res << '\n';
	return 0;
}