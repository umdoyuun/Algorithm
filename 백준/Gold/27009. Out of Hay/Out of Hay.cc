#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int x, y, cost;
}arr[10001];

int n, m, res;
int par[2001];

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
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> arr[i].x >> arr[i].y >> arr[i].cost;
	}
	sort(arr, arr + m, cmp);
	for (int i = 0; i < m; i++) {
		if (unionPar(arr[i].x, arr[i].y)) {
			res = max(res, arr[i].cost);
		}
	}
	cout << res << '\n';
	return 0;
}