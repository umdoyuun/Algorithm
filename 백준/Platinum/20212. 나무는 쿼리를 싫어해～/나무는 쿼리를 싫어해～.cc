#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class s_node {
public:
	int x, y, k;
};

class q_node {
public:
	int x, y, k, idx;
};

vector<s_node> sq;
vector<q_node> qq;
vector<int> v;

vector<long long> seg;
vector<long long> lazy;

int n, m;

bool cmp(q_node a, q_node b) {
	return a.k < b.k;
}

void lazy_propagation(int x, int s, int e) {
	if (lazy[x]) {
		seg[x] += lazy[x] * (v[e + 1] - v[s]);
		if (s != e) {
			for (int i = x * 2; i <= x * 2 + 1; i++) {
				lazy[i] += lazy[x];
			}
		}
		lazy[x] = 0;
	}
}

long long update(int x, int s, int e, int l, int r, long long v) {
	lazy_propagation(x, s, e);
	if (r < s || e < l) return seg[x];
	if (l <= s && e <= r) {
		lazy[x] += v;
		lazy_propagation(x, s, e);
		return seg[x];
	}
	int mid = s + (e - s) / 2;
	return seg[x] = update(x * 2, s, mid, l, r, v) + update(x * 2 + 1, mid + 1, e, l, r, v);
}

int get_coord(int x) {
	x = lower_bound(v.begin(), v.end(), x) - v.begin();
	return x;
}

long long query(int x, int s, int e, int l, int r) {
	lazy_propagation(x, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return seg[x];
	int mid = s + (e - s) / 2;
	return query(x * 2, s, mid, l, r) + query(x * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int r_idx = 0;
	int cmd, x, y, k;
	sq.reserve(n);
	qq.reserve(n);
	v.reserve(n * 2);
	for (int i = 0; i < n; i++) {
		cin >> cmd >> x >> y >> k;
		v.push_back(x);
		v.push_back(y + 1);
		if (cmd == 1) {
			sq.push_back({ x, y, k });
		}
		else {
			qq.push_back({ x, y, k, r_idx++ });
		}
	}
	vector<long long> res(r_idx);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	sort(qq.begin(), qq.end(), cmp);
	int idx = 0;
	int m = v.size();
	seg.resize(m * 4, 0);
	lazy.resize(m * 4, 0);
	for(int i = 0; i < qq.size(); i++){
		while (idx < sq.size() && idx < qq[i].k) {
			int x = get_coord(sq[idx].x);
			int y = get_coord(sq[idx].y + 1) - 1;
			long long v = sq[idx].k;
			idx++;
			update(1, 0, m - 1, x, y, v);
		}
		int x = get_coord(qq[i].x);
		int y = get_coord(qq[i].y + 1) - 1;
		long long ret = query(1, 0, m - 1, x, y);
		res[qq[i].idx] = ret;
	}
	for (auto x : res) {
		cout << x << '\n';
	}
	return 0;
}