#include <iostream>
using namespace std;

int n;
int seg[100001 * 4];
int arr[100001], input[100001];

int init(int x, int s, int e) {
	if (s == e) {
		return seg[x] = 1;
	}
	int mid = s + (e - s) / 2;
	return seg[x] = init(x * 2, s, mid) + init(x * 2 + 1, mid + 1, e);
}

void update(int x, int s, int e, int idx) {
	if (idx < s || e < idx) return;
	if (s == e) {
		seg[x] = 0;
		return;
	}
	seg[x]--;
	int mid = s + (e - s) / 2;
	update(x * 2, s, mid, idx);
	update(x * 2 + 1, mid + 1, e, idx);
}

int query(int x, int s, int e, int k) {
	if (s == e) {
		return s;
	}
	int mid = s + (e - s) / 2;
	if (seg[x * 2] <= k) {
		return query(x * 2 + 1, mid + 1, e, k - seg[x * 2]);
	}
	return query(x * 2, s, mid, k);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	init(1, 0, n - 1);
	for (register int i = 0; i < n; i++) {
		cin >> input[i];
		input[i] = i - input[i];
	}
	for (register int i = n - 1; i >= 0; i--) {
		int idx = query(1, 0, n - 1, input[i]);
		arr[idx] = i + 1;
		update(1, 0, n - 1, idx);
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}