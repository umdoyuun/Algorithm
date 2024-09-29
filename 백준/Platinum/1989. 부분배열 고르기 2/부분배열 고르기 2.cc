#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	long long sum, min;
	int idx;
};

int n, si, ei;
long long res;
long long arr[100001];
//long long seg[4 * 100001][2];
node seg[4 * 100001 * 4];

void init(int x, int s, int e) {
	if (s == e) {
		seg[x].sum = arr[s];
		seg[x].min = arr[s];
		seg[x].idx = s;
		return;
	}
	int mid = s + (e - s) / 2;
	init(x * 2, s, mid);
	init(x * 2 + 1, mid + 1, e);
	seg[x].sum = seg[x * 2].sum + seg[x * 2 + 1].sum;
	if (seg[x * 2].min < seg[x * 2 + 1].min) {
		seg[x].idx = seg[x * 2].idx;
		seg[x].min = seg[x * 2].min;
	}
	else {
		seg[x].idx = seg[x * 2 + 1].idx;
		seg[x].min = seg[x * 2 + 1].min;
	}
}

node find_min(int x, int s, int e, int l, int r) {
	if (r < s || e < l) return { 0, 0x7fffffff, -1 };
	if (l <= s && e <= r) return seg[x];
	int mid = s + (e - s) / 2;
	node a = find_min(x * 2, s, mid, l, r);
	node b = find_min(x * 2 + 1, mid + 1, e, l , r);
	if (a.min < b.min) {
		return { a.sum + b.sum, a.min , a.idx };
	}
	else {
		return { a.sum + b.sum, b.min, b.idx };
	}
}



void func(int s, int e) {
	node m = find_min(1, 0, n - 1, s, e);
	if (m.idx == -1) return;
	if (res <= (m.sum * m.min)) {
		res = m.sum * m.min;
		si = s + 1;
		ei = e + 1;
	}
	
	if (s < m.idx)
		func(s, m.idx - 1);
	if (e > m.idx)
		func(m.idx + 1, e);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(1, 0, n - 1);
	func(0, n - 1);
	cout << res << '\n' << si << ' ' << ei;
	return 0;
}