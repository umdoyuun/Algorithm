#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mx = 1000000007;

int n, m, k, i;
long long res;
int colors[200001];
int arr[200001];
pair<int, int> idx[200001];

vector<int> v[200001];
vector<int> seg[200001 * 4];

void dfs(int x, int pre) {
	arr[i] = colors[x];
	idx[x].first = i++;
	for (int y : v[x]) {
		if (y == pre) continue;
		dfs(y, x);
	}
	idx[x].second = i - 1;
}

void mergeSortInit(int x, int s, int e) {
	if (s == e) {
		seg[x].push_back(arr[s]);
		return;
	}
	int mid = s + (e - s) / 2;
	seg[x].resize(e - s + 1);
	mergeSortInit(x * 2, s, mid);
	mergeSortInit(x * 2 + 1, mid + 1, e);
	merge(seg[x * 2].begin(), seg[x * 2].end(), seg[x * 2 + 1].begin(), seg[x * 2 + 1].end(), seg[x].begin());
}

int query(int x, int s, int e, int l, int r, int v) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		return upper_bound(seg[x].begin(), seg[x].end(), v) - seg[x].begin();
	}
	int mid = s + (e - s) / 2;
	return query(x * 2, s, mid, l, r, v) + query(x * 2 + 1, mid + 1, e, l, r, v);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> colors[i];
	}
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1, 0);
	mergeSortInit(1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		int ret = query(1, 0, n - 1, idx[x].first, idx[x].second, y) % mx;
		res += ret;
		res %= mx;
	}
	cout << res << '\n';
	return 0;
}