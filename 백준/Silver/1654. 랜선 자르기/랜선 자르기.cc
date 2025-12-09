#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
long long arr[10001];

bool check(long long x) {
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt += arr[i] / x;
	}
	if (cnt >= n) return true;
	else return false;
}

int parametric_search(long long s, long long e) {
	while (s <= e) {
		long long mid = s + (e - s) / 2;
		if (check(mid)) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	return s - 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> k >> n;
	long long mx = 0;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		mx = max(mx, arr[i]);
	}
	int res = parametric_search(1, mx);
	cout << res;
	return 0;
}