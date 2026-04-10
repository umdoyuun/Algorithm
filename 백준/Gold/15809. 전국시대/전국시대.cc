#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int power[100001];
int par[100001];

int getPar(int x) {
	if (x == par[x]) return x;
	else return par[x] = getPar(par[x]);
}

void ally(int x, int y) {
	x = getPar(x);
	y = getPar(y);
	power[x] += power[y];
	par[y] = x;
}

void war(int x, int y) {
	x = getPar(x);
	y = getPar(y);
	if (power[x] == power[y]) {
		par[x] = 0;
		par[y] = 0;
	}
	if (power[x] < power[y]) {
		swap(x, y);
	}
	power[x] -= power[y];
	par[y] = x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		cin >> power[i];
	}
	for (int j = 0; j < m; j++) {
		int cmd, x, y;
		cin >> cmd >> x >> y;
		if (cmd == 1) {
			ally(x, y);
		}
		else {
			war(x, y);
		}
	}
	vector<int> res;
	for (int i = 1; i <= n; i++) {
		if (getPar(i) == i) {
			res.push_back(power[i]);
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for (int x : res) {
		cout << x << ' ';
	}
	return 0;
}