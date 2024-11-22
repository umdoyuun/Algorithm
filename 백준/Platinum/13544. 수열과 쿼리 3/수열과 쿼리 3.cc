#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> seg[100000 * 4];
int arr[100000];

void merge_sort_init(int x, int s, int e) {
	if (s == e) {
		seg[x].push_back(arr[s]);
		return;
	}
	int mid = s + (e - s) / 2;
	seg[x].resize(e - s + 1);
	merge_sort_init(x * 2, s, mid);
	merge_sort_init(x * 2 + 1, mid + 1, e);
	merge(seg[x * 2].begin(), seg[x * 2].end(), seg[x * 2 + 1].begin(), seg[x * 2 + 1].end(), seg[x].begin());
}

int query(int x, int s, int e, int l, int r, int v) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		return seg[x].end() - upper_bound(seg[x].begin(), seg[x].end(), v);
	}
	int mid = s + (e - s) / 2;
	return query(x * 2, s, mid, l, r, v) + query(x * 2 + 1, mid + 1, e, l, r, v);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	merge_sort_init(1, 0, n - 1);
	cin >> m;
	int last = 0;
	for (int i = 0; i < m; i++) {
		int x, y, k;
		cin >> x >> y >> k;
		x ^= last;
		y ^= last;
		k ^= last;
		last = query(1, 0, n - 1, x - 1, y - 1, k);
		cout << last << '\n';
	}
	return 0;
}