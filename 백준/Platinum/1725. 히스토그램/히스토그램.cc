#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long res;
long long arr[100001];
long long seg[4 * 100001][2];

long long init(int x, int s, int e) {
	if (s == e) {
		seg[x][0] = arr[s];
		seg[x][1] = s;
		res = max(res, arr[s]);
		return seg[x][0];
	}
	int mid = s + (e - s) / 2;
	long long a = init(x * 2, s, mid);
	long long b = init(x * 2 + 1, mid + 1, e);
	if (a < b) {
		seg[x][0] = a;
		seg[x][1] = seg[x * 2][1];
		return a;
	}
	else {
		seg[x][0] = b;
		seg[x][1] = seg[x * 2 + 1][1];
		return b;
	}
}

pair<long long, int> find_min(int node, int s, int e, int x, int y) {
	if (e < x || s > y) return { 1e9, -1 };
	if (x <= s && e <= y) return { seg[node][0], seg[node][1] };
	int mid = s + (e - s) / 2;
	pair<long long, int> a = find_min(node * 2, s, mid, x, y);
	pair<long long, int> b = find_min(node * 2 + 1, mid + 1, e, x, y);
	if (a.first < b.first) {
		return a;
	}
	else {
		return b;
	}
}



void func(int s, int e) {
	pair<long long, int> m = find_min(1, 0, n - 1, s, e);
	if (m.second == -1) return;
	res = max(res, ((e - s + 1) * m.first));
	if(s < m.second)
		func(s, m.second - 1);
	if(e > m.second)
		func(m.second + 1, e);
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
	cout << res;
	return 0;
}