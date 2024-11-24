#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> seg[300000 * 4];
int arr[300000];

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
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	merge_sort_init(1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		int x, y, k;
		cin >> x >> k >> y;
		if (arr[x - 1] >= k) cout << "0\n";
		else
			cout << query(1, 0, n - 1, x, x + y - 1, k - 1) << '\n';
	}
	return 0;
}