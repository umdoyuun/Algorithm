#include <iostream>
#include <vector>
using namespace std;

int n, m, cnt, flag;
vector<int> v[100001];
pair<int, int> dat[100001];
struct node {
	long long sum, sum2, lazy;
};
node seg[100001 * 4];

void dfs(int x) {
	dat[x].first = cnt++;
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		dfs(y);
	}
	dat[x].second = cnt - 1;
}

void lazy_update(int x, int s, int e) {
	if (seg[x].lazy) {
		seg[x].sum += (e - s + 1) * seg[x].lazy;
		if (s != e) {
			seg[x * 2].lazy += seg[x].lazy;
			seg[x * 2 + 1].lazy += seg[x].lazy;
		}
		seg[x].lazy = 0;
	}
}

void update(int x, int s, int e, int l, int r, long long v) {
	lazy_update(x, s, e);
	if (r < s || e < l) return;
	if (l <= s && e <= r) {
		seg[x].lazy += v;
		lazy_update(x, s, e);
		return;
	}
	int mid = s + (e - s) / 2;
	update(x * 2, s, mid, l, r, v);
	update(x * 2 + 1, mid + 1, e, l, r, v);
	seg[x].sum = seg[x * 2].sum + seg[x * 2 + 1].sum;
	return;
}

void update2(int x, int s, int e, int idx, long long  v) {
	if (idx < s || e < idx) return;
	if (s == e) {
		seg[x].sum2 += v;
		return;
	}
	int mid = s + (e - s) / 2;
	update2(x * 2, s, mid, idx, v);
	update2(x * 2 + 1, mid + 1, e, idx, v);
	seg[x].sum2 = seg[x * 2].sum2 + seg[x * 2 + 1].sum2;
	return;
}

long long get_sum(int x, int s, int e, int idx) {
	lazy_update(x, s, e);
	if (idx < s || e < idx) return 0;
	if (s == e) {
		return seg[x].sum;
	}
	int mid = s + (e - s) / 2;
	return get_sum(x * 2, s, mid, idx) + get_sum(x * 2 + 1, mid + 1, e, idx);
}

long long get_sum2(int x, int s, int e, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		return seg[x].sum2;
	}
	int mid = s + (e - s) / 2;
	return get_sum2(x * 2, s, mid, l, r) + get_sum2(x * 2 + 1, mid + 1, e, l, r);
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
			long long y;
			cin >> x >> y;
			x--;
			if (flag) update2(1, 0, n - 1, dat[x].first, y);
			else update(1, 0, n - 1, dat[x].first, dat[x].second, y);
		}
		else if (cmd == 2) {
			int x;
			cin >> x;
			x--;
			long long res = get_sum(1, 0, n - 1, dat[x].first) + get_sum2(1, 0, n - 1, dat[x].first, dat[x].second);
			cout << res << '\n';
		}
		else {
			flag++;
			flag %= 2;
		}
	}
	return 0;
}