#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class edge {
public:
	int x, y, cnt;
	bool operator<(const edge &next) const{
		return cnt > next.cnt;
	}
};

int n, m;
vector<edge> v;
int par[10001];

int getPar(int x) {
	if (x == par[x]) return x;
	return par[x] = getPar(par[x]);
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
	int x, y, c, k;
	int res = 0;
	for (int i = 1; i <= n; i++) par[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> c >> k;
		if (!k) {
			v.push_back({ x, y, c });
			res += c;
		}
		else {
			unionPar(x, y);
		}
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		if (unionPar(v[i].x, v[i].y)) {
			res -= v[i].cnt;
		}
	}
	cout << res;
	return 0;
}