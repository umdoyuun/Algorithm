#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, c, k, cnt = 1;

int par[1001];

class node {
public:
	int x, y, cost;
};

vector<node> v;
vector<pair<int, int>> res;

bool cmp(node a, node b) {
	return a.cost < b.cost;
}

int getPar(int x) {
	if (x == par[x]) return x;
	return par[x] = getPar(par[x]);
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
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		if (unionPar(x, y)) {
			cnt++;
		}
	}
	int cost;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> cost;
			if (i < j) {				
				v.push_back({ i, j, cost });
			}
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		if (v[i].x == 1 || v[i].y == 1) continue;
		if (unionPar(v[i].x, v[i].y)) {
			c += v[i].cost;
			k++;
			res.push_back({ v[i].x, v[i].y });
		}
		if (cnt == n - 1) break;
	}
	cout << c << ' ' <<  k << '\n';
	for (auto xy : res) {
		cout << xy.first << ' ' << xy.second << '\n';
	}
	return 0;
}