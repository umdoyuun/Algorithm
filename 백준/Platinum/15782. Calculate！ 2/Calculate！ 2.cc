#include <iostream>
#include <vector>
using namespace std;

int n, m, cnt, ret;
vector<int> graph[100001];
int mapper[100001][2];
int arr[100001];
int seg[100001 * 4];
int lazy[100001 * 4];

void dfs(int x, int pre) {
	mapper[x][0] = cnt++;
	for (int y : graph[x]) {
		if (y == pre) continue;
		dfs(y, x);
	}
	mapper[x][1] = cnt - 1;
}

int init(int x, int s, int e) {
	if (s == e) {
		return seg[x] = arr[s];
	}
	int mid = s + (e - s) / 2;
	return seg[x] = init(x * 2, s, mid) ^ init(x * 2 + 1, mid + 1, e);
}

void lazy_propagation(int x, int s, int e) {
	if (lazy[x]) {
		if((e - s) % 2 == 0)
			seg[x] ^= lazy[x];
		if (s != e) {
			for (int i = x * 2; i <= x * 2 + 1; i++) {
				lazy[i] ^= lazy[x];				
			}
		}
		lazy[x] = 0;
	}
}

int update(int x, int s, int e, int l, int r, int val) {
	lazy_propagation(x, s, e);
	if (r < s || e < l) return seg[x];
	if (l <= s && e <= r) {
		lazy[x] ^= val;
		lazy_propagation(x, s, e);
		return seg[x];
	}
	int mid = s + (e - s) / 2;
	return seg[x] = update(x * 2, s, mid, l, r, val) ^ update(x * 2 + 1, mid + 1, e, l, r, val);
}

int query(int x, int s, int e, int l, int r) {
	lazy_propagation(x, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		return seg[x];
	}
	int mid = s + (e - s) / 2;
	return query(x * 2, s, mid, l, r) ^ query(x * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int x, y;
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> arr[mapper[i][0]];
	}
	init(1, 0, n - 1);
	for (int i = 0; i < m;i++) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			cin >> x;
			cout << query(1, 0, n - 1, mapper[x][0], mapper[x][1]) << '\n';
		}
		else {
			cin >> x >> y;
			update(1, 0, n - 1, mapper[x][0], mapper[x][1], y);
		}
	}
	return 0;
}