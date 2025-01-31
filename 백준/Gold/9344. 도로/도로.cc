#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, p, q, cnt;
bool check;
int par[10001];
struct way {
	int x, y, cost;
};
vector<way> v;

void init() {
	cnt = 0;
	check = false;
	v.clear();
	for (register int i = 1; i <= n; i++) {
		par[i] = i;
	}
}

bool cmp(way a, way b) {
	return a.cost < b.cost;
}

int getPar(int x) {
	if (x == par[x]) return x;
	else return par[x] = getPar(par[x]);
}

void unionPar(int x, int y) {
	int px = getPar(x);
	int py = getPar(y);
	if (px == py) return;
	if (x == p && y == q) check = true;
	par[py] = px;
	cnt++;
	return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m >> p >> q;
		if (p > q) swap(p, q);
		init();
		int x, y, c;
		for (int i = 0; i < m; i++) {			
			cin >> x >> y >> c;
			if (x > y) swap(x, y);
			v.push_back({ x, y, c });
		}
		sort(v.begin(), v.end(), cmp);
		for (way w : v) {
			unionPar(w.x, w.y);
			if (cnt == n - 1) break;
		}
		if (cnt == n - 1 && check) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}