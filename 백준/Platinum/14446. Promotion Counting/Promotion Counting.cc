#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[100001];
vector<int> seg[100001 * 4];
vector<int> edges[100001];

class node {
public:
	int s, e, p;
};

node info[100001];

void dfs(int x) {
	static int i = 0;
	info[i].p = arr[x];
	info[x].s = i++;
	for (int y : edges[x]) {
		dfs(y);
	}
	info[x].e = i - 1;
}

void init(int x, int s, int e) {
	if (s == e) {
		seg[x].push_back(info[s].p);
		return;
	}
	int mid = s + (e - s) / 2;
	init(x * 2, s, mid);
	init(x * 2 + 1, mid + 1, e);
	seg[x].resize(e - s + 1);
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
	for (int i = 1; i < n; i++) {
		int p;
		cin >> p;
		edges[p - 1].push_back(i);
	}
	dfs(0);
	init(1, 0, n - 1);
	for (int i = 0; i < n; i++) {
		int ret = query(1, 0, n - 1, info[i].s, info[i].e, arr[i]);
		cout << ret << '\n';
	}
	return 0;
}