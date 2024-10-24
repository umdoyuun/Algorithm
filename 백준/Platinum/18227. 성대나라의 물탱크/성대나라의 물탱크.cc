#include <iostream>
#include <vector>
using namespace std;

int n, s, m, cnt;
vector<int> v[200001];
pair<int, int> dat[200001];
long long seg[200001 * 4];
int level[200001];
bool visit[200001];

void dfs(int x, int l) {
	dat[x].first = cnt++;
	level[x] = l;
	visit[x] = true;
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (visit[y]) continue;
		dfs(y, l + 1);
	}
	dat[x].second = cnt - 1;
}

long long update(int x, int s, int e, int idx, long long v) {
	if (idx < s || e < idx) return seg[x];
	seg[x] += v;
	if (s == e) {
		return seg[x];
	}
	int mid = s + (e - s) / 2;
	return seg[x] = update(x * 2, s, mid, idx, v) + update(x * 2 + 1, mid + 1, e, idx, v);
}

long long query(int x, int s, int e, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return seg[x];
	int mid = s + (e - s) / 2;
	return query(x * 2, s, mid, l, r) + query(x * 2 + 1, mid + 1, e, l, r);
}

void print(int x, int s, int e) {
	if (s == e) {
		cout << seg[x] << ' ';
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
	cin >> n >> s;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cin >> m;
	dfs(s, 1);
	for (int i = 0; i < m; i++) {
		int cmd, x;
		cin >> cmd >> x;
		if (cmd == 1) {
			update(1, 0, n - 1, dat[x].first, 1);
			/*print(1, 0, n - 1);
			cout << '\n';*/
		}
		else {
			cout << query(1, 0, n - 1, dat[x].first, dat[x].second) * level[x] << '\n';
		}
	}
	return 0;
}