#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node {
	int x, y, cost;
};

int par[25000];
int n, m, result;
vector<node> v;

bool compare(node x, node y) {
	return x.cost < y.cost;
}

void init() {
	result = 0;
	v.clear();
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
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		cin >> n >> m;
		for (int i = 0; i < n * m; i++) {
			par[i] = i;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m - 1; j++) {
				int cost;
				cin >> cost;
				v.push_back({ (i * m) + j, (i * m) + j + 1, cost });
				/*v[(i * m) + j].push_back({ (i * m) + j + 1, cost });
				v[(i * m) + j + 1].push_back({ (i * m) + j, cost });*/
			}
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m; j++) {
				int cost;
				cin >> cost;
				v.push_back({ (i * m) + j, (i * m) + j + m, cost });
				/*v[(i * m) + j].push_back({ (i * m) + j + m, cost });
				v[(i * m) + j + m].push_back({ (i * m + j),cost });*/
			}
		}
		sort(v.begin(), v.end(), compare);
		for (int i = 0; i < v.size(); i++) {
			if (unionParent(v[i].x, v[i].y)) {
				result += v[i].cost;
				//cout << v[i].x << ' ' << v[i].y << ' ' << v[i].cost << '\n';
			}
		}
		cout << result << '\n';
	}
	return 0;
}