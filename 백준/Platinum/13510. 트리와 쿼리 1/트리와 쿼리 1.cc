#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100001;

int n, m, cnt;
vector<pair<int, int>> edges[MAX];
pair<int, int> edge_info[MAX];
int cost[MAX];

class Node {
public:
	int pos, par, top, depth, heavy;
}node[MAX];

int seg[MAX * 4];

int dfs(int x, int pre) {
	node[x].par = pre;
	node[x].heavy = -1;
	int sum = 1, mx = -1;
	for (auto next : edges[x]) {
		if (pre == next.first) continue;
		cost[next.first] = next.second;
		int sz = dfs(next.first, x);
		sum += sz;
		if (mx < sz) {
			node[x].heavy = next.first;
			mx = sz;
		}
	}
	return sum;
}

void hld(int x, int top, int d) {
	node[x].pos = cnt++;
	node[x].top = top;
	node[x].depth = d;
	if (node[x].heavy != -1) {
		hld(node[x].heavy, top, d + 1);
	}

	for (auto next : edges[x]) {
		if (next.first == node[x].par || next.first == node[x].heavy) continue;
		hld(next.first, next.first, d + 1);
	}
}

int update(int x, int s, int e, int idx, int v) {
	if (idx < s || e < idx) return seg[x];
	if (s == e) return seg[x] = v;
	int mid = s + (e - s) / 2;
	return seg[x] = max(update(x * 2, s, mid, idx, v), update(x * 2 + 1, mid + 1, e, idx, v));
}

int query(int x, int s, int e, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return seg[x];
	int mid = s + (e - s) / 2;
	return max(query(x * 2, s, mid, l, r), query(x * 2 + 1, mid + 1, e, l, r));
}

int path_query(int x, int y) {
	int ret = 0;
	while (node[x].top != node[y].top) {
		if (node[node[x].top].depth < node[node[y].top].depth) swap(x, y);
		ret = max(ret, query(1, 0, n - 1, node[node[x].top].pos, node[x].pos));
		x = node[node[x].top].par;
	}
	if (node[x].depth > node[y].depth) swap(x, y);
	if (node[x].pos < node[y].pos) {
		ret = max(ret, query(1, 0, n - 1, node[x].pos + 1, node[y].pos));
	}
	return ret;
}

int get_node(int idx) {
	int x = edge_info[idx].first;
	int y = edge_info[idx].second;
	return node[x].depth > node[y].depth ? x : y;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int x, y, c;
	for (int i = 1; i < n; i++) {
		cin >> x >> y >> c;
		edges[x].push_back({ y, c });
		edges[y].push_back({ x, c });
		edge_info[i] = { x, y };
	}

	dfs(1, 0);
	hld(1, 1, 1);

	for (int i = 1; i <= n; i++) {
		update(1, 0, n - 1, node[i].pos, cost[i]);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> c >> x >> y;
		if (c == 1) {
			x = get_node(x);
			update(1, 0, n - 1, node[x].pos, y);
		}
		else {
			int ret = path_query(x, y);
			cout << ret << '\n';
		}
	}
	return 0;
}