#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
long long res;
vector<pair<int, int>> v;

int seg[2001 * 4];

int update(int x, int s, int e, int idx) {
	if (idx < s || e < idx) return seg[x];
	if (s == e) return seg[x] += 1;
	int mid = s + (e - s) / 2;
	return seg[x] = update(x * 2, s, mid, idx) + update(x * 2 + 1, mid + 1, e, idx);
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
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v.push_back({ x, y });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		res += query(1, 1, n, v[i].second + 1, n);
		update(1, 1, n, v[i].second);
	}
	cout << res << '\n';
	return 0;
}