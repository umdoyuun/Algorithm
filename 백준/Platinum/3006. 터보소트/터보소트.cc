#include <iostream>
#include <algorithm>
using namespace std;

const int mx = 1e9;
const int mn = -1;

class node {
public:
	int val, idx, cnt;
};

int n;
node mx_seg[100001 * 4];
node mn_seg[100001 * 4];
int arr[100001];

void init(int x, int s, int e) {
	if (s == e) {
		mx_seg[x] = { arr[s], s, 1 };
		mn_seg[x] = { arr[s], s, 1 };
		return;
	}
	int mid = s + (e - s) / 2;
	init(x * 2, s, mid);
	init(x * 2 + 1, mid + 1, e);
	if (mx_seg[x * 2].val > mx_seg[x * 2 + 1].val) {
		mx_seg[x] = { mx_seg[x * 2].val, mx_seg[x * 2].idx, mx_seg[x * 2].cnt + mx_seg[x * 2 + 1].cnt };
	}
	else {
		mx_seg[x] = { mx_seg[x * 2 + 1].val, mx_seg[x * 2 + 1].idx, mx_seg[x * 2].cnt + mx_seg[x * 2 + 1].cnt };
	}
	if (mn_seg[x * 2].val < mn_seg[x * 2 + 1].val) {
		mn_seg[x] = { mn_seg[x * 2].val, mn_seg[x * 2].idx, mn_seg[x * 2].cnt + mn_seg[x * 2 + 1].cnt };
	}
	else {
		mn_seg[x] = { mn_seg[x * 2 + 1].val, mn_seg[x * 2 + 1].idx, mn_seg[x * 2].cnt + mn_seg[x * 2 + 1].cnt };
	}
}

void update(int x, int s, int e, int v) { 
	int mid = s + (e - s) / 2;
	if (s == e) {
		mx_seg[x] = { mn, s, 0 };
		mn_seg[x] = { mx, s, 0 };
		return;
	}
	
	mx_seg[x].cnt--;
	mn_seg[x].cnt--;
	
	if (mn_seg[x * 2].val <= v && v <= mx_seg[x * 2].val) {
		update(x * 2, s, mid, v);
	}
	else {
		update(x * 2 + 1, mid + 1, e, v);
	}
	
	node left = mx_seg[x * 2];
	node right = mx_seg[x * 2 + 1];
	if (left.val > right.val) {
		mx_seg[x] = { left.val, left.idx, left.cnt + right.cnt };
	}
	else {
		mx_seg[x] = { right.val, right.idx, left.cnt + right.cnt };
	}
	
	left = mn_seg[x * 2];
	right = mn_seg[x * 2 + 1];
	if (left.val < right.val) {
		mn_seg[x] = { left.val, left.idx, left.cnt + right.cnt };
	}
	else {
		mn_seg[x] = { right.val, right.idx, left.cnt + right.cnt };
	}
}

int mn_query(int x, int s, int e, int l, int r) {
	if (r < s || e < l) return 0;
	else if (l <= s && e <= r) {
		return mn_seg[x].cnt;
	}
	int mid = s + (e - s) / 2;
	return mn_query(x * 2, s, mid, l, r) + mn_query(x * 2 + 1, mid + 1, e, l, r);
}

int mx_query(int x, int s, int e, int l, int r) {
	if (r < s || e < l) return 0;
	else if (l <= s && e <= r) {
		return mx_seg[x].cnt;
	}
	int mid = s + (e - s) / 2;
	return mx_query(x * 2, s, mid, l, r) + mx_query(x * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int l = 1, r = n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init(1, 1, n);
	while (l <= r) {
		int l_cnt = mn_query(1, 1, n, 1, mn_seg[1].idx);
		cout << l_cnt - 1 << '\n';
		update(1, 1, n, l);
		if (l == r) break;
		int r_cnt = mx_query(1, 1, n, mx_seg[1].idx, n);		
		cout << r_cnt - 1 << '\n';
		update(1, 1, n, r);
		l++, r--;
	}
	return 0;
}