#include <iostream>
using namespace std;
const int mod = 1e9 + 7;

long long arr[100001];
struct node {
	long long sum, sum_lazy, mul_lazy, lazy;
};

node seg[100001 * 4];

void init(int x, int s, int e) {
	if (s == e) {
		seg[x].sum = arr[s];
		return;
	}
	int mid = s + (e - s) / 2;
	init(x * 2, s, mid);
	init(x * 2 + 1, mid + 1, e);
	seg[x].sum = (seg[x * 2].sum + seg[x * 2 + 1].sum) % mod;
	return;
}

void lazy(int x, int s, int e) {
	if (seg[x].lazy) {
		seg[x].sum = ((long long)(e - s + 1) * seg[x].lazy % mod) % mod;
		if (s != e) {
			for (int i = x * 2; i <= x * 2 + 1; i++) {
				seg[i].lazy = seg[x].lazy;
				seg[i].sum_lazy = 0;
				seg[i].mul_lazy = 0;
			}
		}
		seg[x].lazy = 0;
	}
	if (seg[x].mul_lazy) {
		seg[x].sum = (seg[x].sum % mod * seg[x].mul_lazy % mod) % mod;
		if (s != e) {
			int mid = s + (e - s) / 2;
			if (seg[x * 2].mul_lazy)
				seg[x * 2].mul_lazy = (seg[x * 2].mul_lazy % mod * seg[x].mul_lazy % mod) % mod;
			else
				seg[x * 2].mul_lazy = seg[x].mul_lazy;
			seg[x * 2].sum_lazy = (seg[x * 2].sum_lazy % mod * seg[x].mul_lazy % mod) % mod;
			if (seg[x * 2 + 1].mul_lazy)
				seg[x * 2 + 1].mul_lazy = (seg[x * 2 + 1].mul_lazy % mod * seg[x].mul_lazy % mod) % mod;
			else
				seg[x * 2 + 1].mul_lazy = seg[x].mul_lazy;
			seg[x * 2 + 1].sum_lazy = (seg[x * 2 + 1].sum_lazy % mod * seg[x].mul_lazy % mod) % mod;
		}
		seg[x].mul_lazy = 0;
	}
	if (seg[x].sum_lazy) {
		seg[x].sum += ((long long)(e - s + 1) * seg[x].sum_lazy % mod) % mod;
		seg[x].sum %= mod;
		if (s != e) {
			int mid = s + (e - s) / 2;
			seg[x * 2].sum_lazy += seg[x].sum_lazy;
			seg[x * 2].sum_lazy %= mod;
			seg[x * 2 + 1].sum_lazy += seg[x].sum_lazy;
			seg[x * 2 + 1].sum_lazy %= mod;
		}
		seg[x].sum_lazy = 0;
	}
	
}



void update(int x, int s, int e, int l, int r, int v, long long t) {
	lazy(x, s, e);
	if (r < s || e < l) return;
	if (l <= s && e <= r) {
		if (t == 1) seg[x].sum_lazy = v;
		else if (t == 2) seg[x].mul_lazy = v;
		else seg[x].lazy = v;
		lazy(x, s, e);
		return;
	}
	int mid = s + (e - s) / 2;
	update(x * 2, s, mid, l, r, v, t);
	update(x * 2 + 1, mid + 1, e, l, r, v, t);
	seg[x].sum = (seg[x * 2].sum + seg[x * 2 + 1].sum) % mod;
	return;
}

int get_sum(int x, int s, int e, int l, int r) {
	lazy(x, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		return seg[x].sum;
	}
	int mid = s + (e - s) / 2;
	return (get_sum(x * 2, s, mid, l, r) + get_sum(x * 2 + 1, mid + 1, e, l, r)) % mod;
}

void print(int x, int s, int e) {
	//lazy(x, s, e);
	if (s == e) {
		cout << seg[x].sum << ' ';
		return;
	}
	int mid = s + (e - s) / 2;
	print(x * 2, s, mid);
	print(x * 2 + 1, mid + 1, e);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(1, 0, n - 1);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int cmd, l, r;
		cin >> cmd >> l >> r;
		l--, r--;
		if (cmd == 4) {
			cout << get_sum(1, 0, n - 1, l, r) << '\n';
			//print(1, 0, n - 1);
			//cout << "\n\n";
		}
		else {
			int x;
			cin >> x;
			update(1, 0, n - 1, l, r, x, cmd);

		}

	}
	return 0;
}