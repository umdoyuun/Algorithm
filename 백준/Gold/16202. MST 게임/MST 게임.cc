#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int n, m, t, res, cnt;
int par[1001];
struct node {
	int x, y, cost;
};

deque<node> dq;

void init() {
	res = 0;
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
}

int getPar(int x) {
	if (x == par[x]) return x;
	else return par[x] = getPar(par[x]);
}

bool unionPar(int x, int y) {
	x = getPar(x);
	y = getPar(y);
	if (x == y) return false;
	par[y] = x;
	cnt++;
	return true;
}

bool cmp(node a, node b) {
	return a.cost < b.cost;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> t;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		dq.push_back({ x, y, i });
	}
	sort(dq.begin(), dq.end(), cmp);
	for (int i = 0; i < t; i++) {
		init();
		for (int i = 0; i < dq.size(); i++) {
			if (unionPar(dq[i].x, dq[i].y)) {
				res += dq[i].cost;
			}
		}
		dq.pop_front();
		if (cnt < n - 1) res = 0;
		cout << res << ' ';
	}
	return 0;
}