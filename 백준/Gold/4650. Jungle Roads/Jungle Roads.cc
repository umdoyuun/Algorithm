#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, res, cnt;
int par[27];

class node {
public:
	int x, y, cost;
	bool operator < (const node& other) const {
		return cost < other.cost;
	}
};
vector<node> v;

bool init() {
	cin >> n;
	if (!n) return false;
	v.clear();
	res = 0;
	cnt = 0;
	for (int i = 0; i < n; i++) {
		par[i] = i;
	}
	char cx, cy;
	int x, y;
	for (int i = 1; i < n; i++) {
		cin >> cx >> x;
		for (int j = 0; j < x; j++) {
			cin >> cy >> y;
			v.push_back({ cx - 'A', cy - 'A', y });
		}
	}
	sort(v.begin(), v.end());
	return true;
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
	cnt++;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (init()) {
		for (auto edge : v) {
			if (cnt == n - 1) break;
			if (unionPar(edge.x, edge.y)) {
				res += edge.cost;
			}
		}
		cout << res << '\n';
	}
	return 0;
}