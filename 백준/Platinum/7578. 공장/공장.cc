#include <iostream>
using namespace std;

int n;
int arr[500001];
int idx[1000001];
long long seg[500001 * 4];
long long res;

long long update(int x, int s, int e, int k) {
	if (k < s || e < k) return seg[x];
	if (s == e) {
		return seg[x] += 1;
	}
	int mid = s + (e - s) / 2;
	return seg[x] = update(x * 2, s, mid, k) + update(x * 2 + 1, mid + 1, e, k);
}

long long query(int x, int s, int e, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		return seg[x];
	}
	int mid = s + (e - s) / 2;
	return query(x * 2, s, mid, l, r) + query(x * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		idx[x] = i;
	}
	for (int i = 0; i < n; i++) {
		res += query(1, 0, n - 1, idx[arr[i]] + 1, n - 1);
		update(1, 0, n - 1, idx[arr[i]]);
	}
	cout << res << '\n';
	return 0;
}