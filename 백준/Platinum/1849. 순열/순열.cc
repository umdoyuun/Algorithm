#include <iostream>
using namespace std;

int n;
int arr[100001];
int seg[100001 * 4];

int init(int x, int s, int e) {
	if (s == e) {
		return seg[x] = 1;
	}
	int mid = s + (e - s) / 2;
	return seg[x] = init(x * 2, s, mid) + init(x * 2 + 1, mid + 1, e);
}

int update(int x, int s, int e, int idx) {
	if (idx < s || e < idx) return seg[x];
	if (s == e) {
		return seg[x] = 0;
	}
	int mid = s + (e - s) / 2;
	return seg[x] = update(x * 2, s, mid, idx) + update(x * 2 + 1, mid + 1, e, idx);
}

int query(int x, int s, int e, int k) {
	if (s == e) {
		return s;
	}
	int mid = s + (e - s) / 2;
	if (seg[x * 2] <= k) {
		return query(x * 2 + 1, mid + 1, e, k - seg[x * 2]);
	}
	else return query(x * 2, s, mid, k);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	init(1, 0, n - 1);
	for (register int i = 0; i < n; i++) {
		int x;
		cin >> x;
		int idx = query(1, 0, n - 1, x);
		arr[idx] = i + 1;
		update(1, 0, n - 1, idx);
	}
	for (register int i = 0; i < n;i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}