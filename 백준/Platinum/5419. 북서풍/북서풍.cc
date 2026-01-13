#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int mn = -2e9;

int n;
long long res;

class node {
public:
	int x, y;
};

vector<node> v;
int seg[75001 * 4];

void init() {
	v.clear();
	memset(seg, 0, sizeof(seg));
	res = 0;
	cin >> n;
	v.reserve(n);
}

int update(int x, int s, int e, int idx) {
	if (idx < s || e < idx) return seg[x];
	if (s == e) {
		return seg[x] += 1;
	}
	int mid = s + (e - s) / 2;
	return seg[x] = update(x * 2, s, mid, idx) + update(x * 2 + 1, mid + 1, e, idx);
}

int query(int x, int s, int e, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return seg[x];
	int mid = s + (e - s) / 2;
	return query(x * 2, s, mid, l, r) + query(x * 2 + 1, mid + 1, e, l, r);
}

bool cmp_x(node a, node b) {
	return a.x < b.x;
}

bool cmp_y(node a, node b) {
	if (a.y == b.y) {
		return a.x > b.x;
	}
	return a.y < b.y;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		init();
		int x, y;
		for (int i = 0; i < n; i++) {			
			cin >> x >> y;
			v.push_back({ x, y });
		}
		sort(v.begin(), v.end(), cmp_x);
		int x_tmp = mn;
		int compress_x = -1;
		for (int i = 0; i < n; i++) {
			if(x_tmp < v[i].x) {
				x_tmp = v[i].x;
				compress_x++;
			}
			v[i].x = compress_x;
		}
		int m = compress_x;
		sort(v.begin(), v.end(), cmp_y);
		for (auto cur : v) {
			res += query(1, 0, m, cur.x, m);
			update(1, 0, m, cur.x);
		}
		cout << res << '\n';
	}
	return 0;
}