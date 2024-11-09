#include <iostream>
using namespace std;

int n, k;
int seg[100001 * 4];

int init(int x, int s, int e) {
	if (s == e) {
		return seg[x] = 1;
	}
	int mid = s + (e - s) / 2;
	return seg[x] = init(x * 2, s, mid) + init(x * 2 + 1, mid + 1, e);
}

int update(int x, int s, int e, int idx) {
	if (idx < s || idx > e) return seg[x];
	if (s == e) {
		return seg[x] = 0;
	}
	int mid = s + (e - s) / 2;
	return seg[x] = update(x * 2, s, mid, idx) + update(x * 2 + 1, mid + 1, e, idx);
}

int query(int x, int s, int e, int idx) {
	if (s == e) {
		return s + 1;
	}
	int mid = s + (e - s) / 2;
	if (idx <= seg[x * 2]) return query(x * 2, s, mid, idx);
	else return query(x * 2 + 1, mid + 1, e, idx - seg[x * 2]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	init(1, 0, n - 1);
	int idx = 1;
	cout << '<';
	for(int i = 0; i < n; i++){
		int size = n - i;
		idx += k - 1;
		idx %= size;
		if (idx == 0) idx = size;
		int x = query(1, 0, n - 1, idx);
		cout << x;
		update(1, 0, n - 1, x - 1);
		if (size > 1) cout << ", ";
	}
	cout << ">\n";
	return 0;
}