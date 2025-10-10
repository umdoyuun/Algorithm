#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, res, cnt;
struct node {
	int x, y, cost;
};
vector<node> v;
int par[1001];

bool cmp(node a, node b) {
	return a.cost > b.cost;
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		v.push_back({ x, y, c });
	}
	sort(v.begin(), v.end(), cmp);
	cnt++;
	for (node x : v) {
		if (unionPar(x.x, x.y)) {
			res += x.cost;
		}
	}
	if (cnt == n) {
		cout << res << '\n';
	}
	else {
		cout << -1 << '\n';
	}
	return 0;
}