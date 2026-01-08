#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n;
int arr[500001];
map<int, int> mapper;
int seg[500001 * 4];

int update(int x, int s, int e, int idx) {
	if (idx < s || e < idx) return seg[x];
	if (s == e) {
		return seg[x] = 1;
	}
	int mid = s + (e - s) / 2;
	return seg[x] = update(x * 2, s, mid, idx) + update(x * 2 + 1, mid + 1, e, idx);
}

int query(int x, int s, int e, int l, int r) {
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
	vector<int> tmp(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		tmp[i] = arr[i];
	}
	sort(tmp.begin(), tmp.end());

	for (int i = 0; i < n; i++) {
		mapper[tmp[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		int x = mapper[arr[i]];
		int ret = query(1, 0, n - 1, x, n - 1) + 1;
		cout << ret << '\n';
		update(1, 0, n - 1, x);
	}
	return 0;
}