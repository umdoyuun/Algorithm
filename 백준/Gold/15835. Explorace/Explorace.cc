#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class node {
public:
	int x, y, cost;
	bool operator < (const node& other) const {
		return cost < other.cost;
	}
};

int n, m, res;
vector<node> v;
int par[21];

void init() {
	cin >> n >> m;
	v.clear();
	res = 0;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		v.push_back({ x, y, cost });
	}
	sort(v.begin(), v.end());
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
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		for (auto cur : v) {
			if (unionPar(cur.x, cur.y)) {
				res += cur.cost;
			}
		}
		cout << "Case #" << tc << ": " << res << " meters\n";
	}
	return 0;
}