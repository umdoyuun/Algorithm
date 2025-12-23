#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, res;
class node {
public:
	int x, y, cost;
	bool operator < (const node& other) const {
		return cost < other.cost;
	}
};

int par[201];
vector<node> v;
vector<pair<int, int>> res_v;

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
	cin >> n;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			if (i >= j) continue;
			if (x < 0) {
				unionPar(i, j);
				res -= x;
			}
			else {
				v.push_back({ i, j, x });
			}
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		if (unionPar(v[i].x, v[i].y)) {
			res += v[i].cost;
			res_v.push_back({ v[i].x, v[i].y });
		}
	}
	cout << res << ' ' << res_v.size() << '\n';
	for (auto xy : res_v) {
		cout << xy.first << ' ' << xy.second << '\n';
	}
	return 0;
}