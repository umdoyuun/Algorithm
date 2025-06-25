#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, res;

struct node {
	int x, y, cnt;
};

vector<node> v;
int par[51];

bool cmp(node a, node b) {
	return a.cnt < b.cnt;
}

bool init() {
	cin >> n;
	if (!n) return false;
	res = 0;
	cin >> m;
	v.clear();
	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int x, y, cnt;
		cin >> x >> y >> cnt;
		v.push_back({ x, y, cnt });
	}
	sort(v.begin(), v.end(), cmp);
	return true;
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
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (1) {
		if (!init()) break;
		for (node x : v) {
			if (unionPar(x.x, x.y)) {
				res += x.cnt;
			}
		}
		cout << res << '\n';
	}
	return 0;
}