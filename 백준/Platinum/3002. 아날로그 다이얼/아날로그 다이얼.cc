#include <iostream>
using namespace std;

class node {
public:
	int sum;
	int cnt[10];
};
int n, m;
string str;
node seg[250001 * 4];
int lazy[250001 * 4];

void update_parent(int x) {
	seg[x].sum = 0;
	for (int i = 0; i < 10; i++) {
		seg[x].cnt[i] = seg[x * 2].cnt[i] + seg[x * 2 + 1].cnt[i];
		seg[x].sum += seg[x].cnt[i] * i;
	}
}

void init(int x, int s, int e) {
	if (s == e) {
		seg[x].sum = str[s] - '0';
		seg[x].cnt[seg[x].sum]++;
		return;
	}
	int mid = s + (e - s) / 2;
	init(x * 2, s, mid);
	init(x * 2 + 1, mid + 1, e);
	update_parent(x);
}

void update_lazy(int x, int s, int e) {
	if (lazy[x]) {
		seg[x].sum = 0;
		int tmp[10] = { 0, };
		for (int i = 0; i < 10; i++) {
			tmp[(i + lazy[x]) % 10] = seg[x].cnt[i];
		}
		for (int i = 0; i < 10; i++) {
			seg[x].cnt[i] = tmp[i];
			seg[x].sum += i * seg[x].cnt[i];
		}
		if(s != e){
			for (int i = x * 2; i <= x * 2 + 1; i++) {
				lazy[i] += lazy[x];
			}
		}
		lazy[x] = 0;
	}
}

void update(int x, int s, int e, int l, int r) {
	update_lazy(x, s, e);
	if (r < s || e < l) return;
	if (l <= s && e <= r) {
		lazy[x]++;
		update_lazy(x, s, e);
		return;
	}
	int mid = s + (e - s) / 2;
	update(x * 2, s, mid, l, r);
	update(x * 2 + 1, mid + 1, e, l, r);
	update_parent(x);
}

int query(int x, int s, int e, int l, int r) {
	update_lazy(x, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		return seg[x].sum;
	}
	int mid = s + (e - s) / 2;
	return query(x * 2, s, mid, l, r) + query(x * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> str;
	init(1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		int ret = query(1, 0, n - 1, x, y);
		cout << ret << '\n';
		update(1, 0, n - 1, x, y);
	}
	return 0;
}