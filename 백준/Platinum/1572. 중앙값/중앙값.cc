#include <iostream>
#include <deque>
using namespace std;

const int mx = 65536;
int n, k;
int seg[mx * 4];

int update(int x, int s, int e, int idx, int v) {
	if (idx > e || idx < s) return seg[x];
	if (s == e) {
		return seg[x] += v;
	}
	int mid = s + (e - s) / 2;
	return seg[x] = update(x * 2, s, mid, idx, v) + update(x * 2 + 1, mid + 1, e, idx, v);
}

int find(int x, int s, int e, int cnt) {
	if (s == e) {
		return s;
	}
	int mid = s + (e - s) / 2;
	if (seg[x * 2] >= cnt) {
		return find(x * 2, s, mid, cnt);
	}
	else {
		return find(x * 2 + 1, mid + 1, e, cnt - seg[x * 2]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	deque<int> dq;
	int x;
	for (int i = 0; i < k; i++) {		
		cin >> x;
		dq.push_back(x);
		update(1, 0, mx, x, 1);
	}
	long long res = 0;
	for (int i = k; i < n; i++) {
		res += find(1, 0, mx, (k + 1) / 2);
		cin >> x;
		update(1, 0, mx, dq.front(), -1);
		update(1, 0, mx, x, 1);
		dq.pop_front();
		dq.push_back(x);
	}
	res += find(1, 0, mx, (k + 1) / 2);
	cout << res;
	return 0;
}