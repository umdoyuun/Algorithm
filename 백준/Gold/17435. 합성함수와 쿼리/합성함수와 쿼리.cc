#include <iostream>
#include <algorithm>
using namespace std;
int m, q;

int par[200001][20];

int lca(int x, int cnt) {
	for (int i = 19; i >= 0; i--) {
		if (cnt >= 1 << i) {
			cnt -= (1 << i);
			x = par[x][i];
		}
	}
	return x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> par[i][0];
	}

	for (int i = 1; i < 20; i++) {
		for (int j = 1; j <= m; j++) {
			par[j][i] = par[par[j][i - 1]][i - 1];
		}
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		cout << lca(y, x) << '\n';
	}
	return 0;
}