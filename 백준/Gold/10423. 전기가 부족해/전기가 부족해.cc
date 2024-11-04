#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k, cnt, res;
struct node{
	int x, y, cost;
};
int par[1001];
vector<node> v;

bool cmp(node a, node b) {
	return a.cost < b.cost;
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
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		par[x] = 0;
	}
	for (int i = 0; i < m; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		v.push_back({ x, y, cost });
	}
	
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		if (unionPar(v[i].x, v[i].y)) {
			res += v[i].cost;
		}
	}
	cout << res << '\n';
	return 0;
}