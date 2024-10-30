#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
struct node {
	int x, y, cost;
};

vector<node> v;

int par[301];
int res;
bool visit[401];

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
	if (visit[x] && visit[y]) return false;
	if (x == y) return false;
	if (!visit[x] && !visit[y]) {
		par[y] = x;
	}
	else if (!visit[x]) {
		par[x] = y;
	}
	else {
		par[y] = x;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		par[i] = i;
		v.push_back({ i, i, x });
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			if (i != j) {
				v.push_back({ i, j, x });
			}
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].x;
		int y = v[i].y;
		if (x == y && !visit[getPar(x)]) {
			res += v[i].cost;
			visit[getPar(x)] = true;
		}
		else {
			if (unionPar(x, y)) {
				res += v[i].cost;
			}
		}
	}
	cout << res << '\n';
	return 0;
}