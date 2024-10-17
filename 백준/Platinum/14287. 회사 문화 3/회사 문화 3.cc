#include <iostream>
#include <vector>
using namespace std;

int n, m, cnt;
vector<int> v[100001];
pair<int, int> dat[100001];
long long seg[100001 * 4];

void dfs(int x) {
	dat[x].first = cnt++;
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		dfs(y);
	}
	dat[x].second = cnt - 1;
}

long long update(int x, int s, int e, int idx, long long v) {
	if (idx < s || e < idx) return seg[x];
	if (s == e) {
		return seg[x] += v;
	}
	int mid = s + (e - s) / 2;
	return seg[x] = update(x * 2, s, mid, idx, v) + update(x * 2 + 1, mid + 1, e, idx, v);
}

long long query(int x, int s, int e, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return seg[x];
	int mid = s + (e - s) / 2;
	return query(x * 2, s, mid, l, r) + query(x * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int p;
	cin >> p;
	for (int i = 1; i < n; i++) {
		cin >> p;
		v[p - 1].push_back(i);
	}
	dfs(0);
	for (int i = 0; i < m; i++) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			int x;
			long long v;
			cin >> x >> v;
			x--;
			update(1, 0, n - 1, dat[x].first, v);
		}
		else {
			int x;
			cin >> x;
			x--;
			cout << query(1, 0, n - 1, dat[x].first, dat[x].second) << '\n';
		}
	}
	return 0;
}