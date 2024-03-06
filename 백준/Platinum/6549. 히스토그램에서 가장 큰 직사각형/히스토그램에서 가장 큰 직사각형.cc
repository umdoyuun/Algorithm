#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long arr[100001];
long long seg[4 * 100001][2];
long long res;

long long init(int x, int s, int e) {
	if (s == e) {
		seg[x][0] = arr[s];
		seg[x][1] = s;
		return seg[x][0];
	}
	int mid = s + (e - s) / 2;
	long long a = init(x * 2, s, mid);
	long long b = init(x * 2 + 1, mid + 1, e);
	if (a < b) {
		seg[x][1] = seg[x * 2][1];
		seg[x][0] = a;
	}
	else {
		seg[x][1] = seg[x * 2 + 1][1];
		seg[x][0] = b;
	}
	return seg[x][0];
}

pair<long long, long long> find(int x, int s, int e, int l, int r) {
	if (s > r || e < l) return { 1e9, -1 };
	if (l <= s && e <= r) return { seg[x][0], seg[x][1] };

	int mid = s + (e - s) / 2;
	pair<long long, long long> a = find(x * 2, s, mid, l, r);
	pair<long long, long long> b = find(x * 2 + 1, mid + 1, e, l, r);
	if (a.first < b.first) {
		return a;
	}
	else return b;
}

void func(int s, int e) {
	pair<long long, long long> a = find(1, 0, n - 1, s, e);
	if (a.second == -1) return;
	res = max(res, a.first * (long long)(e - s + 1));
	if (a.second > s) func(s, a.second - 1);
	if (a.second < e) func(a.second + 1, e);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (true) {
		cin >> n;
		res = 0;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		init(1, 0, n - 1);
		func(0, n - 1);
		cout << res << '\n';
	}
	return 0;
}