#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int x, y, cost;
};
int n, m, s, e;
vector<node> v;
int par[100001];
int result = 0x7fffffff;

bool compare(node a, node b) {
	return a.cost > b.cost;
}

int getParent(int x) {
	if (x == par[x]) return x;
	else return par[x] = getParent(par[x]);
}

bool unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x == y) return false;
	par[x] = y;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s >> e;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		v.push_back({ x, y, c });
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		if (unionParent(v[i].x, v[i].y)) {
			result = min(result, v[i].cost);
		}
		if (getParent(s) == getParent(e)) {
			cout << result;
			return 0;
		}
	}
	cout << 0;
	return 0;
}